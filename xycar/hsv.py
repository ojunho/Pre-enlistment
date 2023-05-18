import cv2
import numpy as np

img = cv2.imread('cars.png')
hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
#기본 컬러를 바꾸는 것이다.


#이진화: 특정 색상 범위와 채도/명도 범위 내에 드는 픽셀들을 선택.
lower_white = np.array([0,0,150])
upper_white = np.array([179, 255, 255])

mask = cv2.inRange(hsv, lower_white, upper_white)

cv2.imshow('line', mask)

cv2.waitKey(10000)