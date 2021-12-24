#课表解析Xpath方法.py
#STUAT
#
#Created by Xiexiaopeng on 2021/12/3
#Copyleft © 2020-2021 Student Network Center Of BUCT. 
#Licensed by GPL-3.0
#

from lxml import etree

kebiao=etree.parse('../Docs/NewSimple.xml',base_url="../Docs/Schema.xsd")
workday = int(kebiao.xpath('//NUM_DAY_WORKDAY/text()')[0])
weekend = int(kebiao.xpath('//NUM_DAY_WEEKEND/text()')[0])
print(workday+weekend)
