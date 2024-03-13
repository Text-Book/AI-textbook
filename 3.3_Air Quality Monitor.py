# oding = utf-8
# -*- coding:utf-8 -*-
import random

class AirQualityMonitor:
    def __init__(self):
        # 初始化传感器读数
        self.pm25_sensor = 0
        self.gas_sensor = 0

    def measure_pm25(self):
        # 模拟PM2.5传感器测量，范围在20附近波动
        self.pm25_sensor = 20 + random.uniform(-5, 5)

    def measure_gas(self):
        # 模拟气体传感器测量，范围在300附近波动
        self.gas_sensor = 300 + random.uniform(-50, 50)

    def display_result(self):
        # 显示测量结果
        print(f"PM2.5 Level: {self.pm25_sensor}")
        print(f"Gas Concentration: {self.gas_sensor}")

# 示例用法
if __name__ == "__main__":
    monitor = AirQualityMonitor()
    monitor.measure_pm25()
    monitor.measure_gas()
    monitor.display_result()