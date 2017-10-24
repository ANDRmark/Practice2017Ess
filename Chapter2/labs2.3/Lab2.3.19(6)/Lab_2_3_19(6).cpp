#include <iostream>
using namespace std;
int main(void) {
	int height;
	int maxh = 8;
	cout << "Input height of piramid ";
	cin >> height;
	if (height < 3 || height > maxh) cout << "Height can be from 3 to 8" << endl;
	else {
		for (int i = 0; i < height; i++)
		{
			for (int n = 0; n < 3; n++)
			{
				for (int j = 0; j < maxh - 1 - i; j++)
					cout << " ";
				cout << "*";
				char c = ' ';
				if (i == height - 1) c = '*';
				for (int k = 0; k < i * 2 - 1; k++)
					cout << c;
				if (i != 0) cout << "*";
				for (int j = 0; j < maxh - 1 - i; j++)
					cout << " ";
				cout << " ";
			}
			cout << endl;
		}
	}
	system("pause");
	return 0;
}