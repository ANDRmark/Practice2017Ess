#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "input fibonachi sequence number ";
	cin >> n;
	if (n == 1 || n == 2) cout << 1;
	else
	{
		long long zprevious = 1;
		long long z = 1;
		for (int i = 2; i < n; i++)
		{
			z = z + zprevious;
			zprevious = z - zprevious;;
		}
		cout << z;
	}
	cout << endl;
	system("pause");
	return 0;
}