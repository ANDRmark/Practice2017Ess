#include <iostream>
using namespace std;
int main()
{
	struct MyTime
	{
		int hours;
		int minutes;
	} timeA, timeB;
	bool good = true;
	if (good)
	{
		cout << "Input time A" << endl << "hours ";
		cin >> timeA.hours;
		if (timeA.hours < 0 || timeA.hours > 23) { cout << "wrong value"; good = false; }
	}
	if (good)
	{
		cout << "minutes ";
		cin >> timeA.minutes;
		if (timeA.minutes < 0 || timeA.minutes > 59) { cout << "wrong value"; good = false; }
	}
	if (good)
		if (good)
		{
			cout << "Input time B" << endl << "hours ";
			cin >> timeB.hours;
			if (timeB.hours < 0 || timeB.hours > 23) { cout << "wrong value"; good = false; }
		}
	if (good)
	{
		cout << "minutes ";
		cin >> timeB.minutes;
		if (timeB.minutes < 0 || timeB.minutes > 59) { cout << "wrong value"; good = false; }
	}
	int a;
	int b;
	if (good)
	{
		 a = timeA.hours * 60 + timeA.minutes;
		 b = timeB.hours * 60 + timeB.minutes;
		if (a > b) { cout << "Erlier event happend later, cannot calculate";good = false; }
	}
	if (good)
	{
		int hours = (b - a) / 60;
		int minutes = (b - a - hours * 60);
		cout << hours << ":" << minutes;
	}
	cout << endl;
	system("pause");
	return 0;
}