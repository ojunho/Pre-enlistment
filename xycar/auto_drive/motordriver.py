import rospy
from std_msgs.msg import Int32MultiArray

class MotorDriver:

    def __init__(self, topic):
        self.motor_pub = rospy.Publisher(topic,
                                         Int32MultiArray,
                                         queue_size=1)

    def drive(self, angle, speed):
        drive_info = [angle, speed]
        pub_info = Int32MultiArray(data=drive_info)
        #구동: 인자로 주어진 조향각과 속도 정보를 정해진 토픽에 발행.
        self.motor_pub.publish(pub_info)