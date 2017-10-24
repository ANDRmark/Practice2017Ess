#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "To calculate bottom lower number input n  ";
	cin >> n;
	n = n * n - 2 * n + 2;
	cout << n << endl;
	system("pause");
	return 0;
}