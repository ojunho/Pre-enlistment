import rospy
from std_msgs.msg import Int32MultiArray

class ObstacleDetector:

    def __init__(self, topic):
        self.left = -1
        self.mid = -1
        self.right = -1
        #인자로 주어진 이름의 토픽에 대한 subscriber객체를 생성. 콜백으로는 read_distance()를 등록.
        rospy.Subscriber(topic, Int32MultiArray, self.read_distance)

    def read_distance(self, data):
        # 콜백: 메시지를 해석하여 세 방향 센서의 입력값을 기록.
        self.left = data.data[0]
        self.mid = data.data[1]
        self.right = data.data[2]

    def get_distance(self):
        return self.left, self.mid, self.right