# oding = utf-8
# -*- coding:utf-8 -*-
# 导入所需的库
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.tree import DecisionTreeClassifier, plot_tree
# 设置中文字体
plt.rcParams['font.family'] = 'SimHei'
# 创建数据集
data = {'语文成绩': [85, 70, 65, 90, 78, 62, 82, 75, 88, 70, 65, 92, 80, 68, 87, 75, 62, 82, 77, 80],
    '数学成绩': [88, 75, 68, 92, 80, 60, 85, 75, 85, 72, 70, 90, 78, 65, 88, 70, 60, 85, 75, 78],
    '科学成绩': [82, 72, 70, 87, 75, 65, 88, 80, 92, 78, 68, 85, 75, 70, 92, 72, 65, 88, 80, 70],
    '学科兴趣': [1, 2, 0, 1, 2, 0, 1, 2, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 2],
    '学科能力': [3, 2, 1, 0, 3, 2, 1, 2, 0, 3, 1, 0, 3, 2, 1, 2, 1, 0, 3, 2],
    '作业成绩': [90, 78, 55, 95, 82, 50, 88, 70, 90, 78, 55, 95, 82, 55, 90, 78, 50, 88, 70, 82],
    '作业难度': [3, 2, 1, 0, 3, 2, 1, 3, 1, 3, 2, 0, 3, 2, 1, 3, 1, 0, 3, 2]}
# 将数据集转换为DataFrame
df = pd.DataFrame(data)
# 提取特征（学生成绩）和目标（作业难度）
X = df.iloc[:,:6]
y = df[["作业难度"]]
# 获取列名
feature_names = X.columns.tolist()
target_names = ['简单', '一般', '中等', '困难']
# 构建决策树分类模型
model = DecisionTreeClassifier()
# 训练模型
model.fit(X, y)
# 获取参数值
feature_importance = model.feature_importances_
# 打印每个特征的重要性得分
for i, importance in enumerate(feature_importance):
    print(f"{feature_names[i]}: 重要性得分 = {round(importance,4)}")
# 可视化
plt.figure(figsize=(12, 8))
plot_tree(model, filled=True, feature_names=feature_names, class_names=target_names)
plt.show()
# 新的学生信息（语文偏科，数学偏科）
X_new = pd.DataFrame({
    '语文成绩': [95, 60],
    '数学成绩': [60, 95],
    '科学成绩': [65, 80],
    '学科兴趣': [0, 1],
    '学科能力': [1, 2],
    '作业成绩': [70, 80]})
# 模型预测的适合的作业难度
y_new = model.predict(X_new)
# 输出预测结果
print("新学生1:", X_new.iloc[0].tolist())
print("预测作业难度:", target_names[y_new[0]])
print("新学生2:", X_new.iloc[1].tolist())
print("预测作业难度:", target_names[y_new[1]])


