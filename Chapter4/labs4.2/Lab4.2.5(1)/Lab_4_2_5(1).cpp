#include <iostream>
#include <iomanip>
using namespace std;
int main(void) {
	int n;
	cout << "input N (from 1 to 100000)" << endl;
	cin >> n;
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += i+1;
	}
	cout << sum << endl;
	system("pause");
	return 0;

}