#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
string CheckIP(string input)
{
	int dotpos1 = 0;
	int dotpos2 = 0;
	int dotpos3 = 0;
	int dotsnum = 0;
	string substr;
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '.') dotsnum++;
		else if (input[i] > 57 || input[i] < 48)
			return "Only digits and dots allowed";
	}
	if (dotsnum > 3) return "Too many parts";
	if (dotsnum < 3) return "Incorrect parts count";
	dotpos1 = input.find('.', dotpos1);
	dotpos2 = input.find('.', dotpos1+1);
	dotpos3 = input.find('.', dotpos2+1);

	string ippart1 = input.substr(0, dotpos1);
	string ippart2 = input.substr(dotpos1 + 1, dotpos2 - dotpos1 - 1);
	string ippart3 = input.substr(dotpos2 + 1, dotpos3 - dotpos2 - 1);
	string ippart4 = input.substr(dotpos3 + 1, input.length() - dotpos3 - 1);
	if (ippart1.length() > 3 ||
		ippart2.length() > 3 || 
		ippart3.length() > 3 || 
		ippart4.length() > 3 )
		return "Too many characters in a part";
	if (stoi(ippart1) > 255 || 
		stoi(ippart2) > 255 || 
		stoi(ippart3) > 255 ||
		stoi(ippart4) > 255 )
		return "Too big a value of a part";
	return "Correct IP";
}
int main(void) {
	string input;
	cout << "Ipput IP address" << endl;
	getline(cin, input);
	cout << CheckIP(input) << endl;
	system("pause");
	return 0;

}