#include <iostream>
using namespace std;
int main()
{
	int sys, ft;
	float m, in, rate = 39.37008;//1 meter to 1 inch (12 inches in feet)
	cout << "Enter 0 to input in metric system, Enter 1 to input in imperical system ";
	cin >> sys;
	switch (sys)
	{
	case 0:
		cout << "Enter positive number of meters (can be real) ";
		cin >> m;
		if (m < 0) cout << "Bad number of meters\n";
		else
		{
			in = m * rate;
			ft = in / 12;
			in = in - ft * 12;
			cout << ft << '\'' << in << "\"\n";
		}
		break;
	case 1:
		cout << "Enter positive number of feets (integer only) ";
		cin >> ft;
		if (ft < 0)
		{
			cout << "Bad number of feets\n";
			break;
		}
		cout << "Enter positive number of inches (can be real) ";
		cin >> in;
		if (in < 0)
		{
			cout << "Bad number of inches\n";
			break;
		}
		m = (in + 12 * ft) / rate;
		cout << m << "m\n";
		break;
	default:
		cout << "unexpected input\n";
		break;
	}
	system("pause");
	return 0;
}