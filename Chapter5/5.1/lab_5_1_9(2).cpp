#include <iostream>
#include <string>

using namespace std;

class Square
{
public:
	Square(double side);
private: double side;
		 double area;
public:
	void set_side(double side) {
		if (side > 0) {
			this->side = side;
			area = side * side;
		}
	}
	void print()
	{
		cout << "Square: side=" << this->side << " area=" << this->area << endl;
	}
};

Square::Square(double side)
{
	this->side = side;
	this->area = side * side;
}

int main()
{
	Square s(4);
	s.print();

	s.set_side(2.0);
	s.print();

	s.set_side(-33);
	s.print();

	system("pause");
	return 0;
}