#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "To calculate n! input n  ";
	cin >> n;
	if (n == 0) cout << 1 << endl;
	else
	{
		long long z = 1;
		for (int i = 1; i <= n; i++)
		{
			z = z * i;
		}
		cout << z << endl;
	}
	system("pause");
	return 0;
}