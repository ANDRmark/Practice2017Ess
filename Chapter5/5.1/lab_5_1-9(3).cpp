#include <iostream>

using namespace std;

class AdHocSquare
{
public:
	AdHocSquare(double side) {
		this->side = side;
	}
	void set_side(double side) {
		this->side = side;
	}
	double get_area() {
		return side * side;
	}
private:
	double side;
};

class LazySquare
{
public:
	void set_side(double side) {
		this->side = side;
		side_changed = true;
	}
	double get_area() {
		if (side_changed) return side * side;
		return area;
	}
private:
	double side;
	double area;
	bool side_changed;
};

int main(void) {

	AdHocSquare adHocSquare(2.0);
	cout << "adHocSquare was counted: " << adHocSquare.get_area() << endl;
	cout << "adHocSquare with same side was recounted: " << adHocSquare.get_area() << endl;

	LazySquare lazySquare;
	lazySquare.set_side(2.0);
	cout << "LazySquare was counted: " << lazySquare.get_area() << endl;
	cout << "LazySquare with the same side wasn't recounted: " << lazySquare.get_area() << endl;
	lazySquare.set_side(3.0);
	cout << "LazySquare was new side was recounted: " << lazySquare.get_area() << endl;

	system("pause");
	return 0;
}

