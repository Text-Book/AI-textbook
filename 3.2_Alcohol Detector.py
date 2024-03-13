# coding: utf-8
import time

def get_alcohol_level():
    # 这里模拟获取酒精浓度的传感器数据，实际应用中需要根据传感器的具体接口来获取
    # 假设传感器返回的值在0到1之间，表示酒精浓度的百分比
    print("获取的酒精浓度为：")
    return float(input())  # 将输入值转换为浮点数并返回

def trigger_alarm():
    # 这里可以编写触发警报的代码，比如发出声音或者发送警报通知
    print("警报：酒精浓度超过安全限制！")

def alcohol_detection():
    # 设置酒精浓度的阈值
    threshold = 0.5
    while True:
        alcohol_level = get_alcohol_level()  # 获取酒精浓度
        if alcohol_level > threshold:
            trigger_alarm()  # 触发警报
        else:
            break  # 当酒精浓度低于阈值时跳出循环
        time.sleep(1)  # 每隔1秒检测一次

alcohol_detection()  # 启动酒精检测程序
