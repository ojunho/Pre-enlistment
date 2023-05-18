#!/usr/bin/env python

import rospy, time

from linedetector import LineDetector
from obstacledetector import ObstacleDetector
from motordriver import MotorDriver

from imuread import ImuRead

class AutoDrive:

    def __init__(self):
        rospy.init_node('xycar_driver')
        self.line_detector = LineDetector('/usb_cam/image_raw')
        self.obstacle_detector = ObstacleDetector('/ultrasonic')
        self.driver = MotorDriver('/xycar_motor_msg')

        self.imu = ImuRead("/diagnostics")

    def trace(self):
        #장애물 거리와 양쪽 차선을 탐지.
        obs_l, obs_m, obs_r = self.obstacle_detector.get_distance()
        line_l, line_r = self.line_detector.detect_lines()
        #디버깅을 위한 화면 표시도!
        self.line_detector.show_images(line_l, line_r)

        r, p, y = self.imu.get_data()

        #조향각과 속도 인자를 결정.
        angle = self.steer(line_l, line_r)
        speed = self.accelerate(angle, obs_l, obs_m, obs_r)
        print(angle, speed)

        print("R (%.1f) P (%.1f) Y (%.1f)" %(r, p, y))
        #모터 제어를 위한 메서드 호출(조향각과 속도 인자를 넣어준다)
        self.driver.drive(angle + 90, speed + 90)

    def steer(left, right):
        mid = (left + right) // 2
        if mid < 280:
            angle = -30
        elif mid > 360:
            angle = 30
        else:
            angle = 0
        return angle

    def accelerate(angle, left, mid, right):
        #전방 왼쪽, 가운데, 전방 오른쪽 장애물 중에 가장 작은 값이 50미만이면 정지.
        if min(left, mid, right) < 50:
            speed = 0
        #좌, 우회전의 경우 저속.
        elif angle < -20 or angle < 20:
            speed = 110
        #직진의 경우 고속.
        else:
            speed = 120
        return speed



    def exit(self):
        print("finished")

if __name__ == "__main__":
    car = AutoDrive()
    time.sleep(3)
    rate = rospy.Rate(10)
    while not rospy.is_shtdown():
        car.trace()
        rate.sleep()
    rospy.on_shutdown(car.exit)