#include <iostream>
using namespace std;
int main()
{
	unsigned short int val;
	bool ispalindrome = true;
	cout << "value = ";
	unsigned short int testerleft;
	unsigned short int testerright = 1;
	testerleft = 1 << (sizeof(testerleft) * 8 - 1);
	cin >> val;
	for (int i = 0; i < sizeof(val) * 4; i++)
	{
		if ((bool)(val & testerleft) != (bool)(val & testerright))
		{
			ispalindrome = false;
			break;
		}
		testerleft =testerleft >> 1;
		testerright = testerright << 1;
	}
	if (ispalindrome) cout << val << " is a bitwise palindrome" << endl;
	else cout << val << " is not a bitwise palindrome" << endl;
	system("pause");
	return 0;
}