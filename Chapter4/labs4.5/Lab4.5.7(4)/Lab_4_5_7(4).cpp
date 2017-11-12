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
	string word1;
	string word2;
	cout << "Input two words" << endl;
	cin >> word1;
	cin >> word2;
	bool isAngram = true;
	if (word1.length() != word2.length())
	{
		isAngram = false;
	}
	else
	{
		word1 = Tolower(word1);
		word2 = Tolower(word2);
		int letterpos = 0;
		for (int i = 0; i < word1.length(); i++)
		{
			letterpos = word2.find(word1[i]);
			if (letterpos == string::npos) { isAngram = false; break; }
			word2.erase(letterpos, 1);
		}
	}
	if (isAngram)
		cout << "anagrams" << endl;
	else
		cout << "not anagrams" << endl;
	system("pause");
	return 0;

}