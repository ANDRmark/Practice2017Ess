#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main(void) {
	cout << "Input pattern and sentene" << endl;
	std::string pattern;
	std::getline(std::cin, pattern);
	std::string sentence;
	std::getline(std::cin, sentence);
	string output = "";

	for (int i = 0; i < sentence.length() - pattern.length() + 1; i++)
	{
		bool isMatch = true;
		for (int j = 0; j < pattern.length(); j++)
		{
			if (isMatch)
			switch (pattern[j])
			{
			case 'D':
				if (!(sentence[i + j] >= '0' && sentence[i + j] <= '9'))
				    isMatch = false;
				break;
			case 'A':
				if (!(sentence[i + j] >= 'A' && sentence[i + j] <= 'Z' || sentence[i + j] >= 'a' && sentence[i + j] <= 'z'))
					isMatch = false;
				break;
			case '?':
				break;
			default:
				if(tolower(pattern[j]) != tolower(sentence[i+j]))
					isMatch = false;
				break;
			}
		}
		if (isMatch)
			output += sentence.substr(i, pattern.length()) + '\n';
	}
	std::cout << output << "\n";
	system("pause");
	return 0;

}