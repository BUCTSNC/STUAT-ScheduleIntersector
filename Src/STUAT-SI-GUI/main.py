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
uuid_result=str(uuid.uuid5(uuid.NAMESPACE_DNS,username))
print(uuid_result)

uuid_result_colour=str(uuid_result)[0:6]
print(uuid_result_colour)
uuid_result_style=uuid_result[6:7]
print(uuid_result_style)
uuid_result_01=uuid_result[7:8]+uuid_result[9:13]+uuid_result[14:18]+uuid_result[19:23]+uuid_result[24:]
print(uuid_result_01)

# 需要从LSN的库里面偷一部分tkinter和rgb的库

style_dict={
    "0":"default",
"1":"default",
"2":"default",
"3":"default",
"4":"default",
"5":"default",
"6":"default",
"7":"default",
"8":"default",
"9":"default",
"a":"default",
"b":"default",
"c":"default",
"d":"default",
"e":"default"
}
