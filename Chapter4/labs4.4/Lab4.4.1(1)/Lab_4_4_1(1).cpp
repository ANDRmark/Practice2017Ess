#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main(void) {
	char *alphabet;
	int *charnumbers;
	int alphlength = 'z' - 'a' + 1;
	alphabet = new char[alphlength];
	charnumbers = new int[alphlength];
	for (int i = 0; i < alphlength; i++)
	{
		charnumbers[i] = 0;
	}
	for (int i = 0; i < alphlength; i++)
	{
		alphabet[i] = 'a'+i;
	}
	string sentense;
	cout << "Input sentence" << endl;
	getline(cin,sentense);
	for (int i = 0; i < sentense.length(); i++)
	{
		char c = sentense[i];
		if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
		{
			c = tolower(c);
			for (int j = 0; j < alphlength; j++)
			{
				if (c == alphabet[j])
				{
					charnumbers[j]++;
				}
			}
		}
	}
	bool isPangram = true;
	for (int i = 0; i < alphlength; i++)
	{
		if (charnumbers[i] == 0)
		{
			isPangram = false;
			break;
		}
	}
	if (isPangram) cout << "Pangram" << endl;
	else cout << "Not pangram" << endl;
	for (int i = 0; i < alphlength; i++)
	{
		cout << alphabet[i] << "-" << charnumbers[i] << endl;
	}
	delete[] charnumbers;
	delete[] alphabet;
	system("pause");
	return 0;

}