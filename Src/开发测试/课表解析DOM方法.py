# 课表解析DOM方法.py
# STUAT
#
# Created by Xiexiaopeng on 2021/12/4
# Copyleft © 2020-2021 Student Network Center Of BUCT.
# Licensed by GPL-3.0
#

import xml.dom.minidom

DOMTree = xml.dom.minidom.parse("test.xml")  #
weekday = (
    DOMTree.documentElement.getElementsByTagName("NUM_WEEKDAY")[0]
    .childNodes[0]
    .data
)
weekend = (
    DOMTree.documentElement.getElementsByTagName("NUM_WEEKEND")[0]
    .childNodes[0]
    .data
)
days = weekday + weekend
print(days)
