# oding = utf-8
# -*- coding:utf-8 -*-
import cv2
import pytesseract
# 设置Tesseract的安装路径
pytesseract.pytesseract.tesseract_cmd = r'Tesseract-OCR\tesseract.exe'
# 打开摄像头
cap = cv2.VideoCapture(0)
# 检查摄像头是否成功打开
if not cap.isOpened():
    print("无法打开摄像头")
    exit()
# 读取一帧图像
ret, frame = cap.read()
# 关闭摄像头
cap.release()
# 如果成功读取到图像
if ret:
    # 显示图像
    cv2.imshow('拍摄的照片', frame)
    cv2.waitKey(0)  # 等待按键
    cv2.destroyAllWindows()
    # OCR识别文字
    text = pytesseract.image_to_string(frame, lang='eng')
    # 打印识别出的文字
    print("识别的文字内容如下：")
    print(text)
else:
    print("未能读取到图像")
# 清理窗口和摄像头
cv2.destroyAllWindows()
