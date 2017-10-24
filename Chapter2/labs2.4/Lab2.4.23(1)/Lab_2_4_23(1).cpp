#include <iostream>
using namespace std;
int main()
{
	cout << "input number  ";
	long long n;
	cin >> n;
	long long tester = 1;
	int length = sizeof(long long) * 8;
	int k = 0;
	for (int i = 0; i < length; i++)
	{
		if (n & tester)
		{
			k++;
		}
		tester = tester << 1;
	}
	cout << k << endl;
	system("pause");
	return 0;
}