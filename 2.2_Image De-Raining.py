# oding = utf-8
# -*- coding:utf-8 -*-
import cv2
import numpy as np
# 打开摄像头
cap = cv2.VideoCapture(0)
while True:
    # 读取一帧图像
    ret, frame = cap.read()
    # 获取图像的宽度和高度
    height, width = frame.shape[:2]
    # 创建一个空白的输出图像output
    output = np.zeros(frame.shape, dtype=frame.dtype)
    # 遍历输入图像的每个像素点
    for y in range(height):
        for x in range(width):
            # 计算当前像素点的像素值R、G、B
            R, G, B = frame[y, x]
            # 如果当前像素点在雨滴区域（这里简化为亮度较高的点）
            if R > 200 and G > 200 and B > 200:
                # 获取当前像素点附近的邻域像素点
                x_start = max(x - 1, 0)
                y_start = max(y - 1, 0)
                x_end = min(x + 2, width)
                y_end = min(y + 2, height)
                neighborhood = frame[y_start:y_end, x_start:x_end]
                # 计算邻域像素点的平均RGB值
                avg_R, avg_G, avg_B = np.mean(neighborhood, axis=(0, 1))
                # 将当前像素点的RGB值更新为邻域像素点的平均RGB值
                output[y, x] = [avg_R, avg_G, avg_B]
            else:
                # 将原始像素值赋给输出图像
                output[y, x] = frame[y, x]
    # 显示去雨后的图像
    cv2.imshow('Rain Removed', output)
    # 检测键盘输入，按下ESC键退出循环
    if cv2.waitKey(1) == 27:
        break
# 释放摄像头资源
cap.release()
cv2.destroyAllWindows()