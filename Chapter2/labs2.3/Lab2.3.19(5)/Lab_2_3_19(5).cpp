#include <iostream>
using namespace std;
int main(void) {
	int side;
	cout << "side length of a square ";
	cin >> side;
	if (side < 1 ) cout << "Length cannot be less then 1" << endl;
	else if (side > 25) cout << "its too big square" << endl;
	else {
		side -= 2;
		if (side < 1) side = 1;
		cout << '+';
		for (int i = 0; i < side; i++)
			cout << '-';
		cout << '+' << endl;
		for (int i = 0; i < side; i++) {
			cout << '|';
			for (int j = 0; j < side; j++)
				cout << ' ';
			cout << '|' << endl;
		}
		cout << '+';
		for (int i = 0; i < side; i++)
			cout << '-';
		cout << '+' << endl;
	}
	system("pause");
	return 0;
}