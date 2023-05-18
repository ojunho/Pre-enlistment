#!/usr/vin/env python

import cv2, time
import numpy as np

cap = cv2.VideoCapture("1.avi")

value_threshold = 60

image_width = 640
scan_width, scan_heigth = 200, 20
lmid, rmid = scan_width, image_width - scan_width
area_width, area_heigth = 20, 10
roi_vertical_pos = 430
row_begin = (scan_heigth - area_heigth)//2
row_end = row_begin + area_heigth
pixel_cnt_threshold = 0.8 * area_width * area_heigth

while True:
    ret, grame = cap.read()
    if not ret:
        break
    if cv2.waitKey(1) & 0xFF == 27:
        break


    #roi설정, (아까 지정한 부분부터 일정 크기 세로 띠 모양)
    roi = frame[roi_vertical_pos:roi_vertical_pos + scan_heigth, :]
    frame = cv2.rectangle(frame, (0, roi_vertical_pos),
                          (image_width - 1, roi_vertical_pos + scan_heigth),
                          (255, 0, 0), 3)

    # roi로 끊어낸 부분을 bgr -> hsv
    hsv = cv2.cvtColor(roi, cv2.COLOR_BGR2HSV)

    # 이진화를 하기 위한 색상과 명도 범위 지정.
    lbound = np.array([0, 0, value_threshold], dtype = np.unit8)
    ubound = np.array([131, 255, 255], dtype=np.unit8)

    # 이진화된 이미지.
    bin = cv2.inRange(hsv, lbound, ubound)

    # 이것을 다시 컬러 이미지로
    view = cv2.cvtColor(bin, cv2.COLOR_GRAY2BGR)

    left, right = -1, -1

    for l in range(area_width, lmid):
        area = bin[row_begin:row_end, l - area_width:l]
        if cv2.countNonZero(area) > pixel_cnt_threshold:
            left = l
            break
    for r in range(image_width - area_width, rmid, -1):
        area = bin[row_begin:row_end, r:r + area_width]
        if cv2.countNonZero(area) > pixel_cnt_threshold:
            right = r
            break

    if left != -1:
        lsquare = cv2.rectangle(view,
                                (left - area_width, row_begin),
                                (left, row_end),
                                (0, 255, 0), 3)
    else:
        print("Lost left line")

    if right != -1:
        rsquare = cv2.rectangle(view,
                                (right, row_begin),
                                (right + area_width, row_end),
                                (0, 255, 0), 3)
    else:
        print("Lost right line")

    cv2.imshow("origin", frame)
    cv2.imshow("view", view)

    time.sleep(0.1)

cap.release()
cv2.destroyAllWindows()