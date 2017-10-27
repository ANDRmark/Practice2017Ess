#include <iostream>
using namespace std;
struct Date {
	int year;
	int month;
	int day;
};
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
int dayOfYear(Date date) {
	int numofday = 0;
	for (int i = 1; i < date.month; i++)
	{
		numofday += monthLength(date.year, i);
	}
	numofday += date.day;
	return  numofday;
}
int main(void) {
	Date d;
	cout << "Enter year month day: ";
	cin >> d.year >> d.month >> d.day;
	cout << dayOfYear(d) << endl;
	system("pause");
	return 0;
}
