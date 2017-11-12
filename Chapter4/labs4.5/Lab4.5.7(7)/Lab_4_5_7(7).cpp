#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main(void) {
	cout << "Input password" << endl;
	std::string password;
	std::getline(std::cin, password);
	bool eightcharlong = false;
	bool AtLeastUpper = false;
	bool AtLeastLower = false;
	bool AtLeastDigit = false;
	bool AtLeastSpecChar = false;
	if (password.length() >= 8) eightcharlong = true;
	for (int i = 0; i < password.length(); i++)
	{
		if (password[i] >= 'A' && password[i] <= 'Z')
		{
			AtLeastUpper = true;
			break;
		}
	}
	for (int i = 0; i < password.length(); i++)
	{
		if (password[i] >= 'a' && password[i] <= 'z')
		{
			AtLeastLower = true;
			break;
		}
	}
	for (int i = 0; i < password.length(); i++)
	{
		if (password[i] >= '0' && password[i] <= '9')
		{
			AtLeastDigit = true;
			break;
		}
	}
	for (int i = 0; i < password.length(); i++)
	{
		if (!(password[i] >= '0' && password[i] <= '9') && !(password[i] >= 'A' && password[i] <= 'Z') && !(password[i] >= 'a' && password[i] <= 'z'))
		{
			AtLeastSpecChar = true;
			break;
		}
	}
	if (eightcharlong && AtLeastUpper && AtLeastLower && AtLeastDigit && AtLeastSpecChar)
		cout << "The password is valid" << endl;
	else
	{
		if (!eightcharlong) cout << "The password must be at least 8 characters long" << endl;
		if (!AtLeastUpper) cout << "The password must have at least one upper case letter" << endl;
		if (!AtLeastLower) cout << "The password must have at least one lower case letter" << endl;
		if (!AtLeastDigit) cout << "The password must have at least one digit" << endl;
		if (!AtLeastSpecChar) cout << "The password must have at least one special character" << endl;
	}
	system("pause");
	return 0;

}