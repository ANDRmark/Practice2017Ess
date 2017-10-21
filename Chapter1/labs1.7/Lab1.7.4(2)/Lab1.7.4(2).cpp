#include <iostream>

using namespace std;
int main()
{
	int x1, x2;
	cin >> x1 >> x2;
	float fx1 = 1. / x1;
	float fx2 = 1. / x2;
	if (fx1 == fx2) cout << "Equal";
	else cout << "Not Equal";
	cout << "\n";
	system("pause");
	return 0;
}