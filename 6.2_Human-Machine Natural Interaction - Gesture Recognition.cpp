#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;
int main() {
    // 加载训练好的模型
    Ptr<ml::KNearest> model = cv::ml::KNearest::create();
    model->load("gesture_model.xml");
    // 打开摄像头
    VideoCapture capture(0);
    if (!capture.isOpened()) {
        printf("无法打开摄像头\n");
        return -1;
    }
    // 创建窗口
    namedWindow("Hand Gesture Recognition", WINDOW_NORMAL);
    // 用于存储图像帧
    Mat frame;
    while (true) {
        // 读取摄像头图像
        capture.read(frame);
        // 对图像进行处理，例如灰度化、阈值化等操作
        cvtColor(frame, frame, COLOR_BGR2GRAY);
        threshold(frame, frame, 128, 255, THRESH_BINARY);
        // 调整图像大小，与训练数据一致
        resize(frame, frame, Size(64, 64));
        // 将图像转为一维数组
        Mat sample = frame.reshape(1, 1);
        // 使用训练好的模型进行预测
        Mat results;
        model->findNearest(sample, 1, results);
        // 获取手势识别结果
        int gesture = (int)results.at<float>(0, 0);
        // 在窗口中显示图像和结果
        imshow("Hand Gesture Recognition", frame); //省略后续代码
