
#include <iostream>
// Ԥ��������ܶ���ֵ
const int SMOKE_THRESHOLD = 50;
// ��������
void triggerAlarm(int smokeDensity);
int main() {
    int smokeDensity;
    // ��ʾ�û����뵱ǰ�����ܶ�
    std::cout << "�����뵱ǰ�����ܶȣ���������";
    std::cin >> smokeDensity;
    // ��������ܶ��Ƿ񳬹���ֵ
    if (smokeDensity > SMOKE_THRESHOLD) {
        // ���ú�����������
        triggerAlarm(smokeDensity);
    }
    else {
        std::cout << "�����ܶ����������辯����" << std::endl;
    }
    return 0;
}
// ���������ĺ���
void triggerAlarm(int smokeDensity) {
    std::cout << "��������⵽�����ܶȳ�����ֵ��" << std::endl;
    std::cout << "��ǰ�����ܶ�Ϊ��" << smokeDensity << std::endl;
    std::cout << "��������ȡ�ж���" << std::endl;
}