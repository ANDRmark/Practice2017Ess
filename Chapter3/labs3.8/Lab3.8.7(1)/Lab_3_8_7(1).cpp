#include <iostream>
#include <cmath>
using namespace std;
void increment(int &arg, int val = 1)
{
	arg += val;
}
void increment(float &arg, int val = 1)
{
	arg += val;
}
int main(void) {
	int intvar = 0;
	float floatvar = 1.5;
	for (int i = 0; i < 10; i++)
		if (i % 2) {
			increment(intvar);
			increment(floatvar, sqrt(intvar));
		}
		else {
			increment(intvar, i);
			increment(floatvar);
		}
		cout << intvar * floatvar << endl;
		system("pause");
		return 0;
}