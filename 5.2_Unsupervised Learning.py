# oding = utf-8
# -*- coding:utf-8 -*-
import pandas as pd
from sklearn.cluster import KMeans
from sklearn.preprocessing import MinMaxScaler
from matplotlib import pyplot as plt
grade = pd.read_csv("./学生成绩.csv",encoding="UTF-8")
# 设k=4，即聚成4类
# 构建聚类模型
km = KMeans(n_clusters = 4)
y_predicted = km.fit_predict(grade[['语文', '数学']])
grade['level'] = y_predicted
# 可视化展示结果
level0 = grade[grade.level == 0]
level1 = grade[grade.level == 1]
level2 = grade[grade.level == 2]
level3 = grade[grade.level == 3]
plt.scatter(level0.语文, level0.数学, color = 'grey')
plt.scatter(level1.语文, level1.数学, color = 'green')
plt.scatter(level2.语文, level2.数学, color = 'blue')
plt.scatter(level3.语文, level3.数学, color = 'pink')
# 展示聚类中心
plt.scatter(km.cluster_centers_[:, 0], km.cluster_centers_[:, 1], color = 'red', marker = '*', label = 'centroid')
plt.show()