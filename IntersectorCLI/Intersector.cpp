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
	string NUM_DAY_WORKDAY = FormatString(STUAT.select_single_node("/STUAT/HEAD/NUM_DAY/NUM_DAY_WORKDAY/text()").node().value());
	string NUM_DAY_WEEKEND = FormatString(STUAT.select_single_node("/STUAT/HEAD/NUM_DAY/NUM_DAY_WEEKEND/text()").node().value());
	string NUM_CLASS_MORN = FormatString(STUAT.select_single_node("/STUAT/HEAD/NUM_CLASS/NUM_CLASS_MORN/text()").node().value());
	string NUM_CLASS_NOON = FormatString(STUAT.select_single_node("/STUAT/HEAD/NUM_CLASS/NUM_CLASS_NOON/text()").node().value());
	string NUM_CLASS_DUSK = FormatString(STUAT.select_single_node("/STUAT/HEAD/NUM_CLASS/NUM_CLASS_DUSK/text()").node().value());
	stringstream str2digit;
	int INT_NUM_DAY_WORKDAY;;
	int INT_NUM_DAY_WEEKEND;;
	int INT_NUM_CLASS_MORN;;
	int INT_NUM_CLASS_NOON;;
	int INT_NUM_CLASS_DUSK;;
	str2digit << NUM_DAY_WORKDAY; str2digit >> INT_NUM_DAY_WORKDAY; str2digit.clear();
	
	int NUM_DAY = INT_NUM_DAY_WORKDAY;
	string ver = FormatString(STUAT.select_single_node("/unigal-script/head/ver/text()").node().value());
	cout << "[NUM_DAY_WORKDAY=" << NUM_DAY_WORKDAY << "]" << endl;
	cout << "[NUM_DAY_WEEKEND=" << NUM_DAY_WEEKEND << "]" << endl;
	cout << "[NUM_CLASS_MORN=" << NUM_CLASS_MORN << "]" << endl;
	cout << "[NUM_CLASS_NOON=" << NUM_CLASS_NOON << "]" << endl;
	cout << "[NUM_CLASS_DUSK=" << NUM_CLASS_DUSK << "]" << endl;
	cout << "开始解析脚本，若需要编译成目标语言则输入1，不需要编译成目标语言则输入0" << endl;
	int flag_complier = 0;
	cin >> flag_complier;
	ofstream objectfile;
	if (flag_complier == 1)
	{
		if (dst == "BKE")
		{
			objectfile.open("Simple2.bkspr");
		}
		else if (dst == "librian")
		{
			cout << "本编译器输出结果为ANSI编码，需要用户手工处理为UTF-8方可支持Librian" << endl;
			objectfile.open("入口.liber");
		}
	}
	int iterator = 0;
	int mode = 0;
	string LatestCharacter = "NULL";
	while (true)
	{
		cout << "==== Press 1 to next row ====" << endl;
		cout << "==== Press 2 to exit     ====" << endl;
		cin >> mode;
		if (mode == 1)
		{
			iterator += 1;
			char xpath[250];
			sprintf(xpath, "%s%d%s", "/unigal-script/body/*[", iterator, "]");
#ifdef _DEBUG
			cout << "[" << iterator << "]" << xpath << endl;
#endif // DEBUG
			cout << "[ID= " << iterator << " ]" << endl;
			cout << "[type= " << STUAT.select_node(xpath).node().name() << " ]" << endl;
			string type = STUAT.select_node(xpath).node().name();
			if (type == "text")
			{
				//SHOW
				cout << "[character= " << FormatString(STUAT.select_node(xpath).node().child("character").child("name").child_value()) << " ]" << endl;
				cout << "[content= " << FormatString(STUAT.select_node(xpath).node().child("content").child("part").child_value()) << " ]" << endl;
				//COMPLIER
				string CurrentCharacter = FormatString(STUAT.select_node(xpath).node().child("content").child("part").child_value());
				if (flag_complier == 1)
				{
					if (dst == "BKE")
					{
						//【凉子】[r]
						//抱歉，等很久了么？？[p]
						if (LatestCharacter == CurrentCharacter)
						{
							//说话角色已变更
							LatestCharacter = CurrentCharacter;
							objectfile << FormatString(STUAT.select_node(xpath).node().child("character").child("name").child_value()) << "[r]" << endl;
						}
						else
						{
							//说话角色未变更
							;
						}
						objectfile << FormatString(STUAT.select_node(xpath).node().child("content").child("part").child_value());
					}
					else if (dst == "librian")
					{
						//潘大爺 「今天天氣不錯，去散步吧。」
						objectfile << FormatString(STUAT.select_node(xpath).node().child("character").child("name").child_value()) << " ";
						objectfile << "「" << FormatString(STUAT.select_node(xpath).node().child("content").child("part").child_value()) << "」" << endl;
					}
				}
			}
			else if (type == "code")
			{
				cout << "[code type= " << STUAT.select_node(xpath).node().first_child().name() << " ]" << endl;
				string codetype = STUAT.select_node(xpath).node().first_child().name();
				if (codetype == "action")
				{
					string code_actiontype = STUAT.select_node(xpath).node().first_child().first_child().name();
					if (code_actiontype == "newline")
					{
						//SHOW
						cout << "[action= newline ]" << endl;
						//COMPLIER
						if (flag_complier == 1)
						{
							cout << "generate obj file" << endl;
							if (dst == "BKE")
							{
								cout << "dst == BKE" << endl;
								objectfile << "[p]" << endl;
							}
							if (dst == "librian")
							{
								cout << "dst == librian" << endl;
							}
						}
						else
						{
							;
						}
					}
					if (code_actiontype == "waitclick")
					{
						cout << "[action= waitclick ]" << endl;
					}
				}
				if (codetype == "resource")
				{
					;
				}
				if (codetype == "logic")
				{
					;
				}
				if (codetype == "extension")
				{
					;
				}
			}
			else if (type == "struct")
			{
				;
			}
			else
			{
				;
			}
		}
		else
		{
			if (flag_complier != 0)
			{
				//进行后处理
				if (dst == "BKE")
				{
					objectfile << "@quit" << endl;
				}
				exit(0);
			}
			else
			{
				//不进行后处理
				exit(0);
			}
		}
	}
	return 0;
}