# def print_hi(name):
#     # 在下面的代码行中使用断点来调试脚本。
#     print(f'Hi, {name}')  # 按 Ctrl+F8 切换断点。
#
#
# # 按间距中的绿色按钮以运行脚本。
# if __name__ == '__main__':
#     print_hi('PyCharm')

import uuid

mat = []
for i in range(5):
    mat.append([0, 0, 0, 0, 0])

# print(mat)

# 从UUID5生成identicon，用库画出来
username=input()
uuid_result=uuid.uuid5(uuid.NAMESPACE_DNS,username)
print(uuid_result)
