#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
string Tolower(string a)
{
	string s = a;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + 'z' - 'Z';
	}
	return s;
}
int main(void) {
	cout << "Input comma separated keywords and then sentence" << endl;
	std::string stop_words;
	std::getline(std::cin, stop_words);
	std::string sentence;
	std::getline(std::cin, sentence);

	string * stopwords;
	int stopwordsnum = 0;
	for (int i = 0; i < stop_words.length(); i++)
	{
		if (stop_words[i] == ',')
		{
			if (i == 0) continue;
			if (stop_words[i - 1] != ',' )
				stopwordsnum++;
		}
		if (i == stop_words.length() - 1 && stop_words[i] != ',')
			stopwordsnum++;
	}
	string word = "";
	stopwords = new string[stopwordsnum];
	stopwordsnum = 0;
	for (int i = 0; i < stop_words.length(); i++)
	{
		if (stop_words[i] == ',')
		{
			if (!word.empty())
			{
				stopwords[stopwordsnum++] = word;
				word.clear();
			}
		}
		else
		{
			word += stop_words[i];
		}
		if (i == stop_words.length() - 1)
		{
			if (!word.empty())
			{
				stopwords[stopwordsnum++] = word;
				word.clear();
			}
		}
	}
	word = "";
	for (int i = 0; i < sentence.length(); i++)
	{
		if (isspace(sentence[i]) )
		{
			if (!word.empty())
			{
				for (int j = 0; j < stopwordsnum; j++)
				{
					if (Tolower(word) == Tolower(stopwords[j]))
					{
						sentence.erase(i - stopwords[j].length(), stopwords[j].length()+1);
						i -= stopwords[j].length()+1;
						break;
					}
				}
				word.clear();
			}
		}
		else
		{
			word += sentence[i];
		}
		if (i == sentence.length() - 1)
		{
			if (!word.empty())
			{
				for (int j = 0; j < stopwordsnum; j++)
				{
					if (Tolower(word) == Tolower(stopwords[j]))
					{
						sentence.erase(i - stopwords[j].length() + 1, stopwords[j].length());
						i -= stopwords[j].length();
						break;
					}
				}
				word.clear();
			}
		}
	}
	std::cout << sentence << "\n";
	system("pause");
	return 0;

}