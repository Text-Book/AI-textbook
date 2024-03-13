# oding = utf-8
# -*- coding:utf-8 -*-
# 导入所需的库
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler
# 设置中文字体
plt.rcParams['font.family'] = 'SimHei'
# 创建数据集
data = {'每天学习时间 (小时)': [6, 8, 9, 7, 6.5, 11, 6.5, 12, 6, 7, 8, 10, 6.5, 9, 8, 7.5, 9, 11, 6.5, 8],
      '课堂参与度 (百分制)': [85, 70, 95, 60, 75, 80, 65, 92, 50, 88, 75, 90, 60, 85, 70, 78, 88, 75, 92, 60],
      '全科平均成绩 (百分制)': [80, 75, 88, 70, 76, 90, 72, 95, 60, 85, 78, 92, 68, 86, 76, 80, 85, 82, 95, 72],
      '学科兴趣 (0-10)': [8, 6, 9, 5, 7, 9, 5, 10, 5, 8, 7, 9, 5, 8, 6, 7, 8, 7, 9, 5]}
# 将数据集转换为DataFrame
df = pd.DataFrame(data)
# 标准化数据
scaler = StandardScaler()
scaled_data = scaler.fit_transform(df)
# 构建K均值聚类模型
kmeans = KMeans(n_clusters=4, random_state=1)
# 训练模型
kmeans.fit(scaled_data)
# 获取簇标签
labels = kmeans.labels_
# 将簇标签添加到数据集中
df['学习小组'] = labels
# 绘制聚类结果
plt.figure(figsize=(12, 8))
scatter = plt.scatter(df['每天学习时间 (小时)'], df['全科平均成绩 (百分制)'], c=labels, cmap='viridis', s=100)
# 添加图例
names = ['学霸小组', '努力小组', '奋进小组', '卓越小组']
legend = plt.legend(handles=scatter.legend_elements()[0], labels=names, title='学习小组', loc='lower right')
legend.get_frame().set_linewidth(2)
legend.get_title().set_fontsize('20')
for text in legend.get_texts():
    text.set_fontsize('20')
# 添加标签
plt.xlabel('每天学习时间 (小时)', fontsize=20)
plt.ylabel('全科平均成绩 (百分制)', fontsize=20)
plt.title('初中生学习小组分配', fontsize=20)
plt.xticks(fontsize=16)
plt.yticks(fontsize=16)
sns.set_style("darkgrid")
plt.show()
# 分析每个学习小组的特点
cluster_centers = scaler.inverse_transform(kmeans.cluster_centers_)
cluster_info = pd.DataFrame(cluster_centers, columns=df.columns[:-1])
# 新的学生信息
X_new = pd.DataFrame({
    '每天学习时间 (小时)': [13, 6],
    '课堂参与度 (百分制)': [95, 60],
    '全科平均成绩 (百分制)': [95, 60],
    '学科兴趣 (0-10)': [10, 5]})

# 数据标准化后预测可分配的学习小组
X_test = scaler.transform(X_new)
y_pred = kmeans.predict(X_test)
# 输出预测结果
print("新学生1:", X_new.iloc[0].tolist())
print("预测学习小组:", names[y_pred[0]])
print("新学生2:", X_new.iloc[1].tolist())
print("预测学习小组:", names[y_pred[1]])

