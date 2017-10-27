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
int daysBetween(Date d1, Date d2) {
	if (d1.year > d2.year || (d1.year == d2.year && d1.month > d2.month) || (d1.year == d2.year && d1.month == d2.month && d1.day > d2.day)) return -1;
	int days = 0;
	for (int i = d1.year; i < d2.year; i++)
	{
		if (isLeap(i)) days += 366;
		else days += 365;
	}
	days += dayOfYear(d2);
	days -= dayOfYear(d1);
	return days;
}
int main(void) {
	Date since, till;
	cout << "Enter first date (y m d): ";
	cin >> since.year >> since.month >> since.day;
	cout << "Enter second date (y m d): ";
	cin >> till.year >> till.month >> till.day;
	cout << daysBetween(since, till) << endl;
	system("pause");
	return 0;
}
