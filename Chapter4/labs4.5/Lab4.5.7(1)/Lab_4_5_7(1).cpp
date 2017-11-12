#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main(void) {
	std::string sentence;
	cout << "Input sentence with duplicape words" << endl;
	std::getline(std::cin, sentence);
	sentence.append(1, ' ');
	string s1 = "", s2 = "";
	for (int i = 0; i < sentence.length(); i++)
	{
		if (isspace(sentence[i]))
		{
			if (s1 == s2 && !s1.empty())
			{
				sentence.erase(i - s1.length(), s1.length()+1);
				s1.clear();
			}
			else
			{
				s2.swap(s1);
				s1.clear();
			}
		}
		else s1.append(1,sentence[i]);
	}
	if (sentence[sentence.length() - 1] == ' ') 
		sentence.erase(sentence.length() - 1, 1);
	std::cout << sentence << "\n";
	system("pause");
	return 0;

}