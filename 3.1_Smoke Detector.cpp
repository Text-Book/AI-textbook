
#include <iostream>
// 预设的烟雾密度阈值
const int SMOKE_THRESHOLD = 50;
// 函数声明
void triggerAlarm(int smokeDensity);
int main() {
    int smokeDensity;
    // 提示用户输入当前烟雾密度
    std::cout << "请输入当前烟雾密度（整数）：";
    std::cin >> smokeDensity;
    // 检查烟雾密度是否超过阈值
    if (smokeDensity > SMOKE_THRESHOLD) {
        // 调用函数触发警报
        triggerAlarm(smokeDensity);
    }
    else {
        std::cout << "烟雾密度正常，无需警报。" << std::endl;
    }
    return 0;
}
// 触发警报的函数
void triggerAlarm(int smokeDensity) {
    std::cout << "警报：检测到烟雾密度超过阈值！" << std::endl;
    std::cout << "当前烟雾密度为：" << smokeDensity << std::endl;
    std::cout << "请立即采取行动！" << std::endl;
}