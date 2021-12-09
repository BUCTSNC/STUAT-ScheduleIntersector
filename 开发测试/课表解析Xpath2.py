from lxml import etree

schema_doc = etree.parse("../Docs/Schema.xsd")

class Schedule(object):

    def __init__(self,Name,XML_url):
        kebiao = etree.parse(XML_url, base_url="../Docs/Schema.xsd")
        schema = etree.XMLSchema(schema_doc)
        # print(schema.validate(kebiao))
        STUDENT_NAME = kebiao.xpath('HEAD/STUDENT/STUDENT_NAME/text()')[0]
        STUDENT_ID = int(kebiao.xpath('HEAD/STUDENT/STUDENT_ID/text()')[0])
        if schema.validate(kebiao): #验证xml格式是否正确
            if Name == STUDENT_NAME:
                print("当前课表"+STUDENT_NAME+str(STUDENT_ID))
                WORKDAY = int(kebiao.xpath('HEAD/NUM_DAY/NUM_DAY_WORKDAY/text()')[0])
                WEEKEND = int(kebiao.xpath('HEAD/NUM_DAY/NUM_DAY_WEEKEND/text()')[0])
                MORNCLASS = int(kebiao.xpath('HEAD/NUM_CLASS/NUM_CLASS_MORN/text()')[0])
                NOONCLASS = int(kebiao.xpath('HEAD/NUM_CLASS/NUM_CLASS_NOON/text()')[0])
                DUSKCLASS = int(kebiao.xpath('HEAD/NUM_CLASS/NUM_CLASS_DUSK/text()')[0])
                STUDENT_NAME = kebiao.xpath('HEAD/STUDENT/STUDENT_NAME/text()')[0]
                STUDENT_ID = int(kebiao.xpath('HEAD/STUDENT/STUDENT_ID/text()')[0])
                UNIVERSITY = kebiao.xpath('HEAD/EXTRA/UNIVERSITY/text()')[0]
                COLLEGE = kebiao.xpath('HEAD/EXTRA/COLLEGE/text()')[0]
                MAJOR = kebiao.xpath('HEAD/EXTRA/MAJOR/text()')[0]
                CLASS = kebiao.xpath('HEAD/EXTRA/CLASS/text()')[0]
                LESSON = kebiao.xpath('BODY/LESSON/NAME/text()')
                self.kebiao = kebiao
                self.WORKDAY = WORKDAY
                self.MORNCLASS = MORNCLASS
                self.NOONCLASS = NOONCLASS
                self.DUSKCLASS = DUSKCLASS
                self.WEEKEND = WEEKEND
                self.Name = STUDENT_NAME
                self.ID = STUDENT_ID
                self.UNIVERSITY = UNIVERSITY
                self.COLLEGE = COLLEGE
                self.MAJOR = MAJOR
                self.CLASS = CLASS
                self.LESSON = LESSON
            else:
                print("姓名与XML核对出错，请检查XML文件" + XML_url + STUDENT_NAME)
        else:
            print('xml文件不符合规范')
            print(schema.error_log)

    def name(self):
        return self.Name
    def id(self):
        return self.ID
    def university(self):
        return self.UNIVERSITY
    def college(self):
        return self.COLLEGE
    def major(self):
        return self.MAJOR
if __name__ == '__main__':
    xz = Schedule(Name='小张',XML_url='../Docs/NewSimple.xml')
    print(xz.LESSON)
