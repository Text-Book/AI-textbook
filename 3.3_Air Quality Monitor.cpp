#include <iostream>
#include <cstdlib>
#include <ctime>

class AirQualityMonitor {
private:
    float pm25_sensor;
    float gas_sensor;
public:
    AirQualityMonitor() : pm25_sensor(0), gas_sensor(0) {}

    void measurePM25() {
        // 模拟PM2.5传感器测量，范围在20附近波动
        pm25_sensor = 20 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 10));
    }

    void measureGas() {
        // 模拟气体传感器测量，范围在300附近波动
        gas_sensor = 300 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 100));
    }

    void displayResult() {
        // 显示测量结果
        std::cout << "PM2.5 Level: " << pm25_sensor << std::endl;
        std::cout << "Gas Concentration: " << gas_sensor << std::endl;
    }
};

// 示例用法
int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    AirQualityMonitor monitor;
    monitor.measurePM25();
    monitor.measureGas();
    monitor.displayResult();
    return 0;
}