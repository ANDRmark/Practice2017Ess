#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "input n  ";
	cin >> n;
	int banknotes[] = { 50, 20, 10, 5, 1 };
	while (n > 0)
	{
		for (int i = 0; i < 5; i++)
		{
			if (n >= banknotes[i])
			{
				n = n - banknotes[i];
				cout << banknotes[i] << " ";
				break;
			}
		}
	}
	cout << endl;
	system("pause");
	return 0;
}