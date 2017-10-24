#include <iostream>
using namespace std;
int main()
{
	int year, month, day;
	cout << "Enter year number ";
	cin >> year;
	bool goodinput = true;
	if (year < 1900 || year > 2099)
	{
		cout << "Year is out of range\n";
		goodinput = false;
	}
	if (goodinput)
	{
		cout << "Enter month number ";
		cin >> month;
		if (month < 1 || month > 12)
		{
			cout << "Month is out of range\n";
			goodinput = false;
		}
	}
	if (goodinput)
	{
		cout << "Enter day number ";
		cin >> day;
		if (day < 1 || day > 31)
		{
			cout << "Day is out of range\n";
			goodinput = false;
		}
	}
	if (goodinput)
	{
		month -= 2;
		if (month <= 0)
		{
			month += 12;
			year--;
		}
		month *= 83;
		month /= 32;
		//month = month * 2.6 - 0.2;
		month += day;
		month += year;
		month += year / 4;
		month -= year / 100;
		month += year / 400;
		cout << month % 7 << endl;
	}
	system("pause");
	return 0;
}