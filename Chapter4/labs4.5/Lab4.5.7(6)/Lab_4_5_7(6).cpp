#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
string ToUpper(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		s[i] = toupper(s[i]);
	}
	return s;
}
string ToImportant(string s)
{
	string news = "";
	news.append(1, ' ');
	for (int i = 0; i < s.length(); i++)
	{
		news.append(1, s[i]);
		news.append(1, ' ');
	}
	return news;
}
int main(void) {
	cout << "Input sentence with words surrounded with * or _" << endl;
	std::string sentence;
	std::getline(std::cin, sentence);

	bool asteriskmode = false;
	bool underscoremode = false;
	string symbols = "";
	for (int i = 0; i < sentence.length(); i++)
	{
		switch (sentence[i])
		{
		case '*':
			sentence.erase(i, 1);
			if (asteriskmode)
			{
				sentence.replace(i - symbols.length() , symbols.length(), ToUpper(symbols));
				symbols.clear();
			}
			asteriskmode = !asteriskmode;
			i--;
			break;
		case '_':
			sentence.erase(i, 1);
			if (underscoremode)
			{
				sentence.replace(i - symbols.length() , symbols.length(), ToImportant(symbols));
				i = i - symbols.length() + ToImportant(symbols).length();
				symbols.clear();
			}
			underscoremode = !underscoremode;
			i--;
			break;
		default:
			if (asteriskmode || underscoremode)
			symbols += sentence[i];
			break;
		}
		if (asteriskmode && underscoremode)
		{
			asteriskmode = false;
			underscoremode = false;
			symbols.clear();
		}
	}
	cout << sentence << endl;
	system("pause");
	return 0;

}