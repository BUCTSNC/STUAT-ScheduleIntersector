# # def print_hi(name):
# #     # 在下面的代码行中使用断点来调试脚本。
# #     print(f'Hi, {name}')  # 按 Ctrl+F8 切换断点。
# #
# #
# # # 按间距中的绿色按钮以运行脚本。
# # if __name__ == '__main__':
# #     print_hi('PyCharm')
#
# import uuid
#
# mat = []
# for i in range(5):
#     mat.append([0, 0, 0, 0, 0])
#
# # print(mat)
#
# # 从UUID5生成identicon，用库画出来
# username=input()
# uuid_result=str(uuid.uuid5(uuid.NAMESPACE_DNS,username))
# print(uuid_result)
#
# uuid_result_colour=str(uuid_result)[0:6]
# print(uuid_result_colour)
# uuid_result_style=uuid_result[6:7]
# print(uuid_result_style)
# uuid_result_01=uuid_result[7:8]+uuid_result[9:13]+uuid_result[14:18]+uuid_result[19:23]+uuid_result[24:]
# print(uuid_result_01)
#
# # 需要从LSN的库里面偷一部分tkinter和rgb的库
#
# style_dict={
#     "0":"default",
# "1":"default",
# "2":"default",
# "3":"default",
# "4":"default",
# "5":"default",
# "6":"default",
# "7":"default",
# "8":"default",
# "9":"default",
# "a":"default",
# "b":"default",
# "c":"default",
# "d":"default",
# "e":"default"
# }

from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_Dialog(object):
    def setupUi(self, Dialog):
        Dialog.setObjectName("Dialog")
        Dialog.resize(400, 300)
        self.groupBox = QtWidgets.QGroupBox(Dialog)
        self.groupBox.setGeometry(QtCore.QRect(0, 0, 391, 241))
        self.groupBox.setObjectName("groupBox")
        self.textEdit = QtWidgets.QTextEdit(self.groupBox)
        self.textEdit.setGeometry(QtCore.QRect(20, 50, 351, 181))
        self.textEdit.setObjectName("textEdit")
        self.comboBox = QtWidgets.QComboBox(self.groupBox)
        self.comboBox.setGeometry(QtCore.QRect(100, 20, 91, 20))
        self.comboBox.setObjectName("comboBox")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.label = QtWidgets.QLabel(self.groupBox)
        self.label.setGeometry(QtCore.QRect(30, 20, 61, 21))
        self.label.setObjectName("label")
        self.queryBtn = QtWidgets.QPushButton(Dialog)
        self.queryBtn.setGeometry(QtCore.QRect(40, 250, 75, 23))
        self.queryBtn.setMaximumSize(QtCore.QSize(75, 16777215))
        self.queryBtn.setObjectName("queryBtn")
        self.clearBtn = QtWidgets.QPushButton(Dialog)
        self.clearBtn.setGeometry(QtCore.QRect(250, 250, 75, 23))
        self.clearBtn.setMaximumSize(QtCore.QSize(75, 16777215))
        self.clearBtn.setObjectName("clearBtn")

        self.retranslateUi(Dialog)
        self.queryBtn.clicked.connect(Dialog.queryWeather)
        self.clearBtn.clicked.connect(Dialog.clearText)
        QtCore.QMetaObject.connectSlotsByName(Dialog)

    def retranslateUi(self, Dialog):
        _translate = QtCore.QCoreApplication.translate
        Dialog.setWindowTitle(_translate("Dialog", "Dialog"))
        self.groupBox.setTitle(_translate("Dialog", "城市天气预报"))
        self.comboBox.setItemText(0, _translate("Dialog", "北京"))
        self.comboBox.setItemText(1, _translate("Dialog", "上海"))
        self.comboBox.setItemText(2, _translate("Dialog", "天津"))
        self.label.setText(_translate("Dialog", "城市"))
        self.queryBtn.setText(_translate("Dialog", "查询"))
        self.clearBtn.setText(_translate("Dialog", "清空"))

