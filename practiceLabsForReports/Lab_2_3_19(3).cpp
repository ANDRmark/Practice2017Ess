#include <iostream>
using namespace std;
int main()
{
	int power;
	unsigned long long a = 1;
	cout << "input power of 2 (number from 0 to 63) ";
	cin >> power;
	if (power < 0 || power > 63) cout << "power is out of range" << endl;
	else 
	{
		for (int i = 0; i < power; i++)
			a *= 2;
		cout << a << endl;
	}
	return 0;
}