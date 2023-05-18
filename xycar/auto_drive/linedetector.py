import rospy
import cv2
import numpy as np
from sensor_msgs.msg import Image
from cv_bridge import CvBridge

class LineDetector:

    def __init__(self):

        self.cam_img = np.zeros(shape=(480, 640, 3), dtype=np.unit8)
        self.mask = np.zeors(shape=(self.scan_height, self.image_width),
                             dtype = np.unit8)
        self.edge = np.zeors(shape=(self.scan_height, self.image_width),
                             dtype=np.unit8)
        self.bridge = CvBridge()

        #인자로 주어진 이름의 투픽에 대한 subscriber객체 생성: 콜백으로는 conv_image()메서드를 등록.
        rospy.Subscriber(topic, Image, self.conv_image)

    def conv_image(self, data):
        self.cam_img = self.bridge.imgmsg_to_cv2(data, 'bgr8')
        v = self.roi_vertical_pos
        roi = self.cam_img[v:v + self.scan_height, :]

        hsv = cv2.cvtColor(roi, cv2.COLOR_BGR2HSV)
        avg_value = np.average(hsv[:, :, 2])
        value_threshold = avg_value * 1.0
        lbound = np.array([0, 0, value_threshold], dtype = np.unit8)
        ubound = np.array([100, 255, 255], dtype = np.unit8)
        self.mask = cv2.inRange(hsv, lbound, ubound)

        gray = cv2.cvtColor(roi, cv2.COLOR_BGR2HSV)
        blur = cv2.GaussianBlur(gray, (5, 5), 0)
        self.edge = cv2.Canny(blur, 60, 70)

    def detect_lines(self):
        # Return positions of left and right lines detected.
        #왼쪽과 오른쪽 차선이 검출된 위치 좌표를 반환. => 여러가지 방법을 동원해서 차선을 잘 인식할 수 있는 방법을 구현!
        return -1, -1
        #과제:

    def show_images(self, left, right):
        # Display images for debugging purposes:
        # do not forget to call cv2.waitKey().
        # 디버깅을 위해서 "검출되었다고 생각되는" 차선 위치를 (left, right 인자로 받아서) 적절한 이미지 위에 사각형, 원등으로 표현하여
        # 화면에 표시.
        pass






