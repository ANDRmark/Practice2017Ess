#include <iostream>
using namespace std;
int main()
{
	struct MyTime
	{
		int hours;
		int minutes;
	} timenow;
	cout << "input time " << endl << "input hours number ";
	cin >> timenow.hours;
	if (timenow.hours > 23 || timenow.hours < 0) cout << "wrong number of hours";
	else 
	{
		cout << "input minutes number ";
		cin >> timenow.minutes;
		if (timenow.minutes < 0 || timenow.minutes > 59) cout << "wrong number of minutes" ;
		else
		{
			cout << "input minutes number of event ";
			int n;
			cin >> n;
			timenow.minutes += n;
			while (timenow.minutes >= 60)
			{
				timenow.hours++;
				timenow.minutes -= 60;
				if (timenow.hours >= 24)
					timenow.hours = 0;
			}
			cout << timenow.hours << ":" << timenow.minutes;
		}
	}
	cout << endl;
	system("pause");
	return 0;
}