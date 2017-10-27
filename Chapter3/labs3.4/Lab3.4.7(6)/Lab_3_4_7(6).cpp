#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int num) {
	if (num <= 1) return false;
	int nmax = sqrt(num);
	for (int i = 2; i <= nmax; i++)
	{
		if (!(num % i)) return false;
	}
	return true;
}
int main(void) {
	for (int i = 0; i <= 21; i++)
		if (isPrime(i))
			cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}
