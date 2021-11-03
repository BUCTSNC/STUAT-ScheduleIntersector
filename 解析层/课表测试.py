import xml.dom.minidom
DOMTree = xml.dom.minidom.parse("test.xml")#
weekday = DOMTree.documentElement.getElementsByTagName("NUM_WEEKDAY")[0].childNodes[0].data
weekend = DOMTree.documentElement.getElementsByTagName("NUM_WEEKEND")[0].childNodes[0].data
days = weekday+weekend
print(days)