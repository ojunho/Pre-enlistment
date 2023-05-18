import cv2
#동영상 파일 읽어들여 표시하기.

vid = cv2.VideoCapture('small.avi')
#비디오 캡쳐 객체를 생성할 수 있음.

while True:
    ret, frame = vid.read()
    if not ret:
        break
    #frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)  #색변환: cv2를 사용하여 BGR2 -> HSV:


    if ret:
        cv2.imshow('video', frame)
    if cv2.waitKey(1) > 0:
        break

vid.release()
cv2.destroyAllWindows()