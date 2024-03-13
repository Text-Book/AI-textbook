# oding = utf-8
# -*- coding:utf-8 -*-

# 预设的烟雾密度阈值
SMOKE_THRESHOLD = 50

# 触发警报的函数
def trigger_alarm(smoke_density):
    print("警报：检测到烟雾密度超过阈值！")
    print("当前烟雾密度为:", smoke_density)
    print("请立即采取行动！")

def main():
    # 提示用户输入当前烟雾密度
    smoke_density = int(input("请输入当前烟雾密度（整数）："))

    # 检查烟雾密度是否超过阈值
    if smoke_density > SMOKE_THRESHOLD:
        # 调用函数触发警报
        trigger_alarm(smoke_density)
    else:
        print("烟雾密度正常，无需警报。")

if __name__ == "__main__":
    main()