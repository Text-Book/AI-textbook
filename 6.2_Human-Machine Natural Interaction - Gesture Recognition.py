# oding = utf-8
# -*- coding:utf-8 -*-
import cv2
import mediapipe as mp


class HandDetector:
    """
    使用mediapipe库查找手。导出地标像素格式。添加了额外的功能。如查找方式，许多手指向上或两个手指之间的距离。并提供找到的手的边框信息。
    """

    def __init__(self, mode=False, maxHands=2, detectionCon=0.5, minTrackCon=0.5):
        """
param mode: 在静态模式下，对每个图像进行检测，param maxHands: 要检测的最大手数，param detectionCon: 最小检测置信度，param minTrackCon: 最小跟踪置信度
        """


self.mode = mode
self.maxHands = maxHands
self.modelComplex = False
self.detectionCon = detectionCon
self.minTrackCon = minTrackCon
# 初始化手部识别模型
self.mpHands = mp.solutions.hands
self.hands = self.mpHands.Hands(self.mode, self.maxHands, self.modelComplex, self.detectionCon, self.minTrackCon)
self.mpDraw = mp.solutions.drawing_utils
# 初始化绘图器
self.tipIds = [4, 8, 12, 16, 20]  # 指尖列表
self.fingers = []
self.lmList = []
# 从图像(BRG)中找到手部，省略


