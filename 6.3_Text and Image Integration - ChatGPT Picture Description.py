# oding = utf-8
# -*- coding:utf-8 -*-
import openai
# 设置ChatGPT的凭据
openai.api_key = 'YOUR_API_KEY'
# 定义要描述的图像
def build_prompt(image_path):
    prompt = f'Image: {image_path}\nDescribe the image:'
    return prompt
# 从用户输入中提取图像路径
def extract_image_path(user_input):
    image_path = ...
    return image_path
# 让ChatGPT生成描述
def generate_description(image_path):
    prompt = build_prompt(image_path)
    # 调用ChatGPT生成描述
    response = openai.Completion.create(
        engine='text-davinci-003',
        prompt=prompt,
        max_tokens=100,
        n=1,
        stop=None,
        temperature=0.7
    )
# 从ChatGPT响应中提取生成的描述
    description = response.choices[0].text.strip()
    return description
# 读取用户输入并调用ChatGPT生成描述
while True:
    user_input = input('Enter image path (or "quit" to exit): ')
    if user_input.lower() == 'quit':
        break
    description = generate_description(image_path)
    print(description)