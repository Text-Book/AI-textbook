#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;
int main() {
    // ����ѵ���õ�ģ��
    Ptr<ml::KNearest> model = cv::ml::KNearest::create();
    model->load("gesture_model.xml");
    // ������ͷ
    VideoCapture capture(0);
    if (!capture.isOpened()) {
        printf("�޷�������ͷ\n");
        return -1;
    }
    // ��������
    namedWindow("Hand Gesture Recognition", WINDOW_NORMAL);
    // ���ڴ洢ͼ��֡
    Mat frame;
    while (true) {
        // ��ȡ����ͷͼ��
        capture.read(frame);
        // ��ͼ����д�������ҶȻ�����ֵ���Ȳ���
        cvtColor(frame, frame, COLOR_BGR2GRAY);
        threshold(frame, frame, 128, 255, THRESH_BINARY);
        // ����ͼ���С����ѵ������һ��
        resize(frame, frame, Size(64, 64));
        // ��ͼ��תΪһά����
        Mat sample = frame.reshape(1, 1);
        // ʹ��ѵ���õ�ģ�ͽ���Ԥ��
        Mat results;
        model->findNearest(sample, 1, results);
        // ��ȡ����ʶ����
        int gesture = (int)results.at<float>(0, 0);
        // �ڴ�������ʾͼ��ͽ��
        imshow("Hand Gesture Recognition", frame); //ʡ�Ժ�������
