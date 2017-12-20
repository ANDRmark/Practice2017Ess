#include <iostream>
#include <string>

using namespace std;

class Fraction {
public:
	Fraction(int numerator, int denominator);
	string toString();
	double toDouble();
	Fraction plus(Fraction that);
	Fraction minus(Fraction that);
	Fraction times(Fraction that);
	Fraction by(Fraction that);
	bool isGreaterThan(Fraction that);
	bool isLessThan(Fraction that);
	bool isEqual(Fraction that);
private:
	int numerator;
	int denominator;
	void reduce();
};
Fraction::Fraction(int numerator, int denominator) {
	this->numerator = numerator;
	this->denominator = denominator;
}
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
Fraction Fraction::plus(Fraction that) {
	int num = this->numerator * that.denominator + that.numerator * this->denominator;
	int den = this->denominator * that.denominator;
	Fraction result(num, den);
	result.reduce();
	return result;
}
Fraction Fraction::minus(Fraction that) {
	int num = this->numerator * that.denominator - that.numerator * this->denominator;
	int den = this->denominator * that.denominator;
	Fraction result(num, den);
	result.reduce();
	return result;
}
Fraction Fraction::times(Fraction that)
{
	int num = this->numerator * that.numerator;
	int den = this->denominator * that.denominator;
	Fraction result(num, den);
	result.reduce();
	return result;
}
Fraction Fraction::by(Fraction that) {
	int num = this->numerator * that.denominator;
	int den = this->denominator * that.numerator;
	Fraction result(num, den);
	result.reduce();
	return result;
}
void Fraction::reduce(void) {
	int a = this->numerator;
	int b = this->denominator;
	do {
		fabs(a) > fabs(b) ? a = a % b : b = b % a;
	} while (a && b);
	this->numerator /= (a + b);
	this->denominator /= (a + b);
}
bool Fraction::isGreaterThan(Fraction that) {
	int num = this->numerator;
	int den = this->denominator;
	this->numerator *= that.denominator;
	this->denominator *= that.denominator;
	that.numerator *= den;
	that.denominator *= den;
	if (this->numerator > that.numerator) {
		this->reduce();
		return true;
	}
	this->reduce();
	return false;
}
bool Fraction::isLessThan(Fraction that) {
	int num = this->numerator;
	int den = this->denominator;
	this->numerator *= that.denominator;
	this->denominator *= that.denominator;
	that.numerator *= den;
	that.denominator *= den;
	if (this->numerator < that.numerator) {
		this->reduce();
		return true;
	}
	this->reduce();
	return false;
}
bool Fraction::isEqual(Fraction that) {
	int num = this->numerator;
	int den = this->denominator;
	this->numerator *= that.denominator;
	this->denominator *= that.denominator;
	that.numerator *= den;
	that.denominator *= den;
	if (this->numerator == that.numerator) {
		this->reduce();
		return true;
	}
	this->reduce();
	return false;
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

bool StrIsValid(string str) {
	return OnlyNumbersInString(str) && StrHasOneOrNoMinus(str) && str.length();
}

int main(void) {
	int num1, den1, num2, den2;
	string input1 = "", input2 = "";
	getline(cin, input1);
	getline(cin, input2);

	input1 = RemoveSpaces(input1);
	input2 = RemoveSpaces(input2);

	if (StrHasExectlyOneSlash(input1) && StrHasExectlyOneSlash(input2)) {

		int findSlashInput1 = input1.find("/");
		string strNumInput1 = input1.substr(0, findSlashInput1);
		string strDenInput1 = input1.substr(findSlashInput1 + 1);

		int findSlashInput2 = input2.find("/");
		string strNumInput2 = input2.substr(0, findSlashInput2);
		string strDenInput2 = input2.substr(findSlashInput2 + 1);

		if (StrIsValid(strNumInput1) && StrIsValid(strDenInput1) && StrIsValid(strNumInput2) && StrIsValid(strDenInput2)) {

			num1 = atoi(strNumInput1.c_str());
			den1 = atoi(strDenInput1.c_str());

			num2 = atoi(strNumInput2.c_str());
			den2 = atoi(strDenInput2.c_str());

			Fraction fraction1(num1, den1);
			Fraction fraction2(num2, den2);

			if (fraction1.isGreaterThan(fraction2)) cout << fraction1.toString() << " > " << fraction2.toString() << endl;
			else if (fraction1.isLessThan(fraction2)) cout << fraction1.toString() << " < " << fraction2.toString() << endl;
			else cout << fraction1.toString() << " = " << fraction2.toString() << endl;

		}

	}
	else cout << "Invalid input" << endl;

	system("pause");
	return 0;
}
