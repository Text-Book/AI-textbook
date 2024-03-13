# oding = utf-8
# -*- coding:utf-8 -*-
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
df = pd.read_csv('.\data\Titanic.csv')  # 加载数据
# （1）构造特征向量和标签值
titanic = df[[‘Pclass’, ‘Sex’, ‘Age’, ‘SibSp’, ‘Parch’, ‘Fare’, ‘Survived’]]
X = titanic.iloc[:,0:6]
Y = titanic.iloc[:,6:7]
# (2)划分训练数据和测试数据
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test
= train_test_split(X, y, test_size=0.2, random_state=0)
# (3)特征矩阵进行归一化
from sklearn.preprocessing import StandardScaler
sc = StandardScaler()
X_train = sc.fit_transform(X_train)
X_test = sc.transform(X_test)
# (4)建立逻辑回归模型
from sklearn.linear_model import LogisticRegression
classifier = LogisticRegression(random_state=0)
classifier.fit(X_train, y_train)
# (5) 模型评价
from sklearn.metrics import accuracy_score
printf( accuracy_score(y_test, y_pred) )   #在测试集的预测准确率约为79%

