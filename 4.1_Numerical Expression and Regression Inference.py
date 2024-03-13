# oding = utf-8
# -*- coding:utf-8 -*-
# 导入所需的库
import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
# 设置中文字体
plt.rcParams['font.family'] = 'SimHei'
# 创建数据集
data = {'身高 (cm)': [155, 160, 150, 165, 175, 152, 158, 162, 168, 170],
       '体重 (kg)': [45, 50, 42, 55, 60, 48, 52, 56, 58, 59]}
# 将数据集转换为DataFrame
df = pd.DataFrame(data)
# 提取自变量（身高）和因变量（体重）
X = df[['身高 (cm)']]
y = df['体重 (kg)']
# 构建线性回归模型
model = LinearRegression()
# 最小二乘法拟合模型
model.fit(X, y)
# 获取参数值：斜率
coef = model.coef_
print("斜率:", coef[0])

# 获取参数值：截距
intercept = model.intercept_
print("截距:", intercept)
# 数据类型转换
x = df['身高 (cm)']
# 计算皮尔逊相关系数
corr_coef = np.corrcoef(x, y)[0, 1]
# 打印结果
print("皮尔逊相关系数:", corr_coef)
# 计算预测值
y_pred = model.predict(X)
# 绘制拟合直线
sns.scatterplot(x, y)
plt.plot(X, y_pred, color='red')
sns.set_style("darkgrid")
plt.xlabel('身高 (cm)')
plt.ylabel('体重 (kg)')
plt.title('身高与体重的关系')
plt.show()
# 新的身高数据
X_new = pd.DataFrame([173,178])
y_new = model.predict(X_new)
# 输出预测结果
print("新的身高数据:", list(X_new[0]))
print("预测的体重为:", y_new)
