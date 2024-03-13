
#include <opencv2/opencv.hpp>
int main() {
    // ��Ĭ������ͷ
    cv::VideoCapture cap(0);
    // ��������
    cv::namedWindow("Face Recognition", cv::WINDOW_AUTOSIZE);
    // ��������������
    cv::CascadeClassifier faceCascade("haarcascade_frontalface_default.xml");
    while (cv::waitKey(1) != 27) {
        // ��ȡ��Ƶ֡
        cv::Mat frame, gray;
        cap >> frame;
        // ��ͼ��ת��Ϊ�Ҷ�ͼ
        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
        // �������������������
        std::vector<cv::Rect> faces;
        faceCascade.detectMultiScale(gray, faces, 1.1, 4, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));
        // ��ͼ���л���������
        for (const auto& face : faces)
            cv::rectangle(frame, face, cv::Scalar(0, 255, 0), 2);
        // ��ʾ���
        cv::imshow("Face Recognition", frame);
    }
    // �ͷ���Դ
    cap.release();
    cv::destroyAllWindows();
    return 0;
}