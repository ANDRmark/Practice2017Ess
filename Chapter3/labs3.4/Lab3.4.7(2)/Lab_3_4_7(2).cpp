#include <iostream>
using namespace std;
bool isLeap(int year) {
	bool common = true;
	if (year % 4) common = true;
	else if (year % 100) common = false;
	else if (year % 400) common = true;
	else common = false;
	return !common;
}
int monthLength(int year, int month) {
	int monthlengths[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && isLeap(year)) return 29;
	if (month < 1 || month > 12 || year < 1900 || year > 2100) return 0;
	return monthlengths[month - 1];
}
int main(void) {
	for (int yr = 2000; yr < 2002; yr++) {
		for (int mo = 1; mo <= 12; mo++)
			cout << monthLength(yr, mo) << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}
