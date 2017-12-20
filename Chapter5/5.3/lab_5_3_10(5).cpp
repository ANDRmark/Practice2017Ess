#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Fraction {
public:
	Fraction(int numerator, int denominator) {
		this->numerator = numerator;
		if (denominator) this->denominator = denominator;
		else this->denominator = 1;
	}
	string toString();
	double toDouble();
private:
	int numerator;
	int denominator;
};
string Fraction::toString() {
	if (fabs(numerator) > fabs(denominator)) {
		if (numerator % denominator == 0) return to_string(numerator / denominator);
		else return to_string(numerator / denominator) + " " + to_string(int(fabs(numerator - (numerator / denominator) * denominator))) + "/" + to_string(int(fabs(denominator)));
	}
	if (numerator < 0 && denominator < 0) return to_string(int(fabs(numerator))) + "/" + to_string(int(fabs(denominator)));
	if (denominator < 0) return to_string(numerator) + "/" + to_string(int(fabs(denominator)));
	return to_string(numerator) + "/" + to_string(denominator);
}
double Fraction::toDouble() {
	return double(numerator) / denominator;
}



bool OnlyNumbersInString(string str) {
	for (int i = 0; i < str.length(); i++) {
		if ((str[i] < '0' || str[i]  > '9') && str[i] != ' ' && str[i] != '-') return false;
	}
	return true;
}
string RemoveSpaces(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			if (str[i + 1] == ' ') {
				str.replace(i, 1, "");
				i--;
			}
		}
		if (i == str.length() - 1)
			if (str[i] == ' ') str.replace(i, 1, "");
	}
	if (str[0] == ' ') str.replace(0, 1, "");
	return str;
}
bool StrHasExectlyOneSlash(string str) {
	int numberOfSlashes = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '/') numberOfSlashes++;
		if (numberOfSlashes > 1) return false;
	}
	if (numberOfSlashes == 0) return false;
	return true;
}
bool StrHasOneOrNoMinus(string str) {
	int numberOfMinuses = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '-') numberOfMinuses++;
		if (numberOfMinuses > 1) return false;
	}
	return true;
}

int main(void) {
	int numerator, denominator;
	string input = "";
	getline(cin, input);

	input = RemoveSpaces(input);

	if (StrHasExectlyOneSlash(input)) {

		int findSlash = input.find("/");

		string strNumerator = input.substr(0, findSlash);
		string strDenominator = input.substr(findSlash + 1);

		if (OnlyNumbersInString(strNumerator) && OnlyNumbersInString(strDenominator) && strNumerator.length() && strDenominator.length() && StrHasOneOrNoMinus(strNumerator) && StrHasOneOrNoMinus(strDenominator)) {

			numerator = atoi(strNumerator.c_str());
			denominator = atoi(strDenominator.c_str());

			Fraction fraction(numerator, denominator);
			cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;

		}
		else cout << "Invalid input" << endl;

	}
	else cout << "Invalid input" << endl;

	system("pause");
	return 0;
}
