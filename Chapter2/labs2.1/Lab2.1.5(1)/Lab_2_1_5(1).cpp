#include <iostream>
using namespace std;
int main(void) {
	int year;
	cout << "Enter a year: ";
	cin >> year;
	if (year < 1582) {
		cout << "No Gregorian calendar\n";
	}
	else
	{
		bool common = true;
		if (year % 4) common = true;
		else if (year % 100) common = false;
		else if (year % 400) common = true;
		else common = false;
		if (common) cout << "Common year\n";
		else cout << "Leap year\n";
	}
	system("pause");
	return 0;
}