
#include <opencv2/opencv.hpp>
int main() {
    // 打开默认摄像头
    cv::VideoCapture cap(0);
    // 创建窗口
    cv::namedWindow("Face Recognition", cv::WINDOW_AUTOSIZE);
    // 加载人脸分类器
    cv::CascadeClassifier faceCascade("haarcascade_frontalface_default.xml");
    while (cv::waitKey(1) != 27) {
        // 读取视频帧
        cv::Mat frame, gray;
        cap >> frame;
        // 将图像转换为灰度图
        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
        // 用人脸分类器检测人脸
        std::vector<cv::Rect> faces;
        faceCascade.detectMultiScale(gray, faces, 1.1, 4, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));
        // 在图像中绘制人脸框
        for (const auto& face : faces)
            cv::rectangle(frame, face, cv::Scalar(0, 255, 0), 2);
        // 显示结果
        cv::imshow("Face Recognition", frame);
    }
    // 释放资源
    cap.release();
    cv::destroyAllWindows();
    return 0;
}