#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int power;
	double a = 1;
	cout << "input negative power of 2 (number should be positive) ";
	cin >> power;
	if (power < 0) cout << "power is out of range" << endl;
	else
	{
		for (int i = 0; i < power; i++)
			a /= 2;
		cout.precision(20);
		//cout << setprecision(20) 
		cout << a << endl;
	}
	system("pause");
	return 0;
}