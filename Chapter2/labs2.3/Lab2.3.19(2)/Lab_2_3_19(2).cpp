#include <iostream>
using namespace std;
int main()
{
	double pi4 = 0.;
	long n;
	cout << "Number of iterations? ";
	cin >> n;
	for (long i = 1; i <= n; i++)
	{
		pi4 += (i % 2 * 2 - 1) * 1.0 / (i * 2 - 1);
	}
	cout.precision(20);
	cout << "Pi = " << (pi4 * 4.) << endl;
	system("pause");
	return 0;
}