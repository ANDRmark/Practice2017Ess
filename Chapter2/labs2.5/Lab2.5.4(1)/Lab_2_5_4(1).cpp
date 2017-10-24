#include <iostream>
using namespace std;
int main()
{
	bool exit = false;
	while (!exit)
	{
		cout << "MENU:\n0 - exit\n1 - addition\n2 - subtraction\n3 - multiplication\n4 - division\nYour choice?\n";
		int choice = -1;
		cin >> choice;
		if (choice == 0) break;
		float x, y;
		if (choice > 0 && choice < 5)
		{
			cout << "input x and then y" << endl;
			cin >> x >> y;
		}
		switch (choice)
		{
		case 0:
			exit = true;
			break;
		case 1:
			cout << " x + y = " << (x + y) << endl;
			break;
		case 2:
			cout << " x - y = " << (x - y) << endl;
			break;
		case 3:
			cout << " x * y = " << (x * y) << endl;
			break;
		case 4:
			cout << " x / y = " << (x / y) << endl;
			break;
		default:
			cout << "Unexpected choice, input 0 to exit" << endl;
		}
	}
	system("pause");
	return 0;
}