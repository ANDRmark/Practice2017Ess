#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main(void) {
	cout << "Input comma separeted values and template text" << endl;
	std::string values;
	std::getline(std::cin, values);
	std::string text;
	std::getline(std::cin, text);

	string propertyname = "";
	string propertyvalue = "";
	string temp = "";
	for (int i = 0; i < values.length(); i++)
	{
		if (values[i] == '=')
		{
			propertyname = temp;
			temp.clear();
		} else
		if (values[i] == ',' || i == values.length() -1)
		{
			if (i == values.length() - 1)
				temp.append(1, values[i]);
			propertyvalue = temp;
			temp.clear();
			{
				bool findprop = false;
				for (int j = 0; j < text.length(); j++)
				{
					if (text[j] == '[' && !findprop) { findprop = true; temp.clear(); }
					else
					if (text[j] == ']' && findprop) 
					{
						findprop = false;
						if (temp == propertyname)
						{
							text.replace(j - propertyname.length() - 1, propertyname.length() + 2, propertyvalue);
							j = j - propertyname.length() - 1 + propertyvalue.length();
							j--;
						}
						temp.clear();
					}
					else
					{
						if (findprop)
						temp += text[j];
					}
				}
			}
		}
		else
		{
			temp.append(1, values[i]);
		}
	}
	cout << text << endl;
	system("pause");
	return 0;

}