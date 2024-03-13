# oding = utf-8
# -*- coding:utf-8 -*-
import cv2
import dlib
# 加载人脸检测器
detector = dlib.get_frontal_face_detector()
# 加载视频捕捉对象
cap = cv2.VideoCapture(0)
while True:
    # 读取视频帧
    ret, frame = cap.read()
    # 将图像转换为灰度图
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    # 使用人脸检测器检测人脸
    faces = detector(gray)
    # 在图像中绘制人脸框
    for face in faces:
        x, y, w, h = face.left(), face.top(), face.width(), face.height()
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)
    # 显示结果
    cv2.imshow("Face Recognition", frame)
    # 检测键盘输入，按下ESC键退出循环
    if cv2.waitKey(1) == 27:
        break
# 释放资源
cap.release()
cv2.destroyAllWindows()