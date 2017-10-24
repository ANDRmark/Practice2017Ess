#include<iostream>
using namespace std;
int main(void)
{
	float grossprice, taxrate, netprice, taxvalue;
	cout << "Enter a gross price: ";
	//cin >> grossprice;
	//cout << "Enter a tax rate: ";
	//cin >> taxrate;// Insert you code here
	while (cin >> grossprice && grossprice < 0)
	{
		cout << "Gross price cannot be less than zero\nEnter a gross price: ";
	}
	cout << "Enter a tax rate: ";
	while (cin >> taxrate && (taxrate <= 0 || taxrate >=100))
	{
		cout << "Tax rate should be more then 0 and less then 100\nEnter a tax rate: ";
	}
	netprice = grossprice / (1.0 + 0.01 * taxrate);
	taxvalue = grossprice  - netprice;
	cout << "Net price: " << netprice << endl;
	cout << "Tax value: " << taxvalue << endl;
	system("pause");
	return 0;
}