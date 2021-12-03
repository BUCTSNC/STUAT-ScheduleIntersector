from lxml import etree

kebiao=etree.parse('../Docs/NewSimple.xml',base_url="../Docs/Schema.xsd")
workday = int(kebiao.xpath('//NUM_DAY_WORKDAY/text()')[0])
weekend = int(kebiao.xpath('//NUM_DAY_WEEKEND/text()')[0])
print(workday+weekend)
