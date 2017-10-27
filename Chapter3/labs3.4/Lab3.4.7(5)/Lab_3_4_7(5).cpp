#include <iostream>
#include <ctime>
using namespace std;
struct Date {
	int year;
	int month;
	int day;
};
Date today(void) {
	time_t t = time(NULL);
	tm t2;
	//t2 = *localtime(&t);
	localtime_s(&t2, &t);
	Date d;
	d.year = t2.tm_year + 1900;
	d.month = t2.tm_mon + 1;
	d.day = t2.tm_mday;
	return d;
}
int main(void) {
	Date t = today();
	cout << t.year << "-" << t.month << "-" << t.day << endl;
	system("pause");
	return 0;
}
