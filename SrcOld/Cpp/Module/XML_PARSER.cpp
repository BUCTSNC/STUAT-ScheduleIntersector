#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "pugixml.hpp"

using namespace std;

string FormatString(string str)
{
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
	str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
	return str;
}

int main(void)
{

	pugi::xml_document STUAT;
	pugi::xml_parse_result result = STUAT.load_file("Simple_maomao.xml");
	std::cout << "Load result: " << result.description() << ", mesh name: " << STUAT.child("mesh").attribute("name").value() << std::endl;

	string NUM_DAY_WORKDAY;// = FormatString(STUAT.select_single_node("/STUAT/HEAD/NUM_DAY/NUM_DAY_WORKDAY/text()").node().value());
	string NUM_DAY_WEEKEND;// = FormatString(STUAT.select_single_node("/STUAT/HEAD/NUM_DAY/NUM_DAY_WEEKEND/text()").node().value());
	string NUM_CLASS_MORN;// = FormatString(STUAT.select_single_node("/STUAT/HEAD/NUM_CLASS/NUM_CLASS_MORN/text()").node().value());
	string NUM_CLASS_NOON;// = FormatString(STUAT.select_single_node("/STUAT/HEAD/NUM_CLASS/NUM_CLASS_NOON/text()").node().value());
	string NUM_CLASS_DUSK;// = FormatString(STUAT.select_single_node("/STUAT/HEAD/NUM_CLASS/NUM_CLASS_DUSK/text()").node().value());
	stringstream str2digit;
	int INT_NUM_DAY_WORKDAY;
	int INT_NUM_DAY_WEEKEND;
	int INT_NUM_CLASS_MORN;
	int INT_NUM_CLASS_NOON;
	int INT_NUM_CLASS_DUSK;
	str2digit << NUM_DAY_WORKDAY; str2digit >> INT_NUM_DAY_WORKDAY; str2digit.clear();
	str2digit << NUM_DAY_WORKDAY; str2digit >> INT_NUM_DAY_WEEKEND; str2digit.clear();
	str2digit << NUM_DAY_WORKDAY; str2digit >> INT_NUM_CLASS_MORN; str2digit.clear();
	str2digit << NUM_DAY_WORKDAY; str2digit >> INT_NUM_CLASS_NOON; str2digit.clear();
	str2digit << NUM_DAY_WORKDAY; str2digit >> INT_NUM_CLASS_DUSK; str2digit.clear();
	int NUM_DAY = INT_NUM_DAY_WORKDAY+ INT_NUM_DAY_WEEKEND;
	int NUM_CLASS = INT_NUM_CLASS_MORN + INT_NUM_CLASS_NOON + INT_NUM_CLASS_DUSK;
	cout << "[NUM_DAY_WORKDAY=" << INT_NUM_DAY_WORKDAY << "]" << endl;
	cout << "[NUM_DAY_WEEKEND=" << INT_NUM_DAY_WEEKEND << "]" << endl;
	cout << "[NUM_CLASS_MORN=" << INT_NUM_CLASS_MORN << "]" << endl;
	cout << "[NUM_CLASS_NOON=" << INT_NUM_CLASS_NOON << "]" << endl;
	cout << "[NUM_CLASS_DUSK=" << INT_NUM_CLASS_DUSK << "]" << endl;
	cout << "[NUM_DAY=" << NUM_DAY << "]" << endl;
	cout << "[NUM_CLASS=" << NUM_CLASS << "]" << endl;
	return 0;
}