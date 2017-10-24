#include <iostream>
using namespace std;
int main()
{
	int c0, steps = 0;
	cin >> c0;
	if (c0 <= 0)cout << "Bad number";
	else
	{
		while (c0 != 1)
		{
			if (c0 % 2) c0 =c0 * 3 + 1;
			else c0 = c0 / 2;
			steps++;
			cout << c0 << endl;
		}
		cout << "steps = " << steps << endl;
	}
	system("pause");
	return 0;
}