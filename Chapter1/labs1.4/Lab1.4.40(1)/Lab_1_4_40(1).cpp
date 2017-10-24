// Lab14401.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include <iostream>
using namespace std;
int main(void) {
	float pi = 3.14159265359;
	float x, y;
	cout << "Enter value for x: ";
	cin >> x;
	y = x*x/(pi*pi*(x*x+0.5))*(1+x*x/(pi*pi*(x*x-0.5)*(x*x-0.5)));
	cout << "y = " << y << endl;
	return 0;
}