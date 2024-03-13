# oding = utf-8
# -*- coding:utf-8 -*-
from tkinter import *
# 创建窗口
window = Tk()
# 设置窗口标题
window.title("简易计算器")
# 创建文本框
entry = Entry(window, width=30)
entry.grid(row=0, column=0, columnspan=4)
# 定义按钮点击事件
def button_click(number):
    current = entry.get()
    entry.delete(0, END)
    entry.insert(0, current + str(number))
def button_clear():
    entry.delete(0, END)
def button_calculate():
    expression = entry.get()
    result = eval(expression)
    entry.delete(0, END)
    entry.insert(0, result)
# 创建按钮
button_1 = Button(window, text="1", padx=20, pady=10, command=lambda: button_click(1))
button_2 = Button(window, text="2", padx=20, pady=10, command=lambda: button_click(2))
# 其他按钮的创建类似，省略
# 按钮的布局
button_1.grid(row=1, column=0)
button_2.grid(row=1, column=1)
# 其他按钮的布局类似，省略
# 清除按钮和计算按钮的创建和布局，省略
# 运行窗口循环
window.mainloop()