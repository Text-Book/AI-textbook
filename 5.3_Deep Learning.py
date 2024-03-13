# oding = utf-8
# -*- coding:utf-8 -*-
# 1.加载包
from tensorflow.keras import datasets, layers, models
# 2.导入数据
(train_images, train_labels), (test_images, test_labels) = datasets.mnist.load_data()
# 3.归一化
train_images, test_images = train_images / 255.0, test_images / 255.0
# 4.构建CNN网络模型
model = models.Sequential(设置二维卷积层1，设置32个3*3的卷积核，activation参数将激活函数设置为ReLu函数，池化层2层：2*2采样)
# 5.编译模型
model.compile(
# Adam 优化器
# 设置交叉熵损失函数
# 设置性能指标列表，将在模型训练时监控列表中的指标
)
# 6.训练模型
history = model.fit(
#输入训练集图片
#输入训练集标签
#设置10个epoch，每个epoch都将会把所有的数据输入模型完成一次训练
#设置验证集
# 7.预测