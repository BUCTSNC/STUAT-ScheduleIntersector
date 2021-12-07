from lxml import etree

class Schedule(object):

    def __init__(self,Name,XML_url):
        kebiao = etree.parse(XML_url, base_url="../Docs/Schema.xsd")
        STUDENT_NAME = kebiao.xpath('//STUDENT_NAME/text()')[0]
        STUDENT_ID = int(kebiao.xpath('//STUDENT_ID/text()')[0])
        if Name == STUDENT_NAME:
            print("当前课表"+STUDENT_NAME+str(STUDENT_ID))
        else:
            print("姓名与XML核对出错，请检查XML文件" + XML_url + STUDENT_NAME)

    def name(self):
        return

if __name__ == '__main__':
    Schedule(Name='小张',XML_url='../Docs/NewSimple.xml')
