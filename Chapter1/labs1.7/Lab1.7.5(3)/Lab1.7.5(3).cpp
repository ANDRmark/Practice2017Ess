#include <iostream>
using namespace std;
int main()
{
	int x1, x2, x3, x4;
	cin >> x1 >> x2 >> x3 >> x4;
	if (x1 > -1 && x1 < 256 &&
		x2 > -1 && x2 < 256 &&
		x3 > -1 && x3 < 256 &&
		x4 > -1 && x4 < 256)
		cout << x1 << "." << x2 << "." << x3 << "." << x4 << endl;
	system("pause");
	return 0;
}