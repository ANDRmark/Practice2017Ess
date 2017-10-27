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
int main(void) {
	for (int yr = 1995; yr < 2017; yr++)
		cout << yr << " -> " << isLeap(yr) << endl;
	system("pause");
	return 0;
}
