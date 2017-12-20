#include <iostream>
#include <string>
#include <regex>
#include <iomanip>

using namespace std;

class Point2D {
public:
	Point2D(double x, double y) {
		this->x = x;
		this->y = y;
	}

	string toString() {
		return "This is string with coordinates x = " + to_string(x) + ", y = " + to_string(y);
	}
	double distanceTo(Point2D that) {
		return sqrt(pow(this->x - that.x, 2) + pow(this->y - that.y, 2));
	}
	double getX() { return this->x; }
	double getY() { return this->y; }
private:
	double x;
	double y;
};


class Line2D {
public:
	Line2D(double slope, double y_intercept) {
		this->slope = slope;
		this->y_intercept = y_intercept;
	}
	Line2D(Point2D pointA, Point2D pointB) {
		this->slope = (pointB.getY() - pointA.getY()) / (pointB.getX() - pointA.getX());
		this->y_intercept = (pointA.getY() * (pointA.getX() + pointB.getX()) - pointA.getX() * (pointA.getY() + pointB.getY())) / (pointB.getX() - pointA.getX());
	}
	string toString() {
		if (y_intercept < 0) return "y = " + to_string(slope) + "x - " + to_string(y_intercept * -1);
		return "y = " + to_string(slope) + "x + " + to_string(y_intercept);
	}
private:
	double slope;
	double y_intercept;
};
string RemoveSpaces(string str);int main(void) {	string point1 = "", point2 = "";
	getline(cin, point1);
	getline(cin, point2);

	point1 = RemoveSpaces(point1);
	point2 = RemoveSpaces(point2);

	regex pattern("^-?\\d+(\.\\d+)?\,?\\s-?\\d+(\.\\d+)?$");

	if (regex_match(point1, pattern) && regex_match(point2, pattern)) {

		int findSpace1 = point1.find(" ");
		string strX1 = point1.substr(0, findSpace1);
		string strY1 = point1.substr(findSpace1 + 1);

		double x1 = atof(strX1.c_str());
		double y1 = atof(strY1.c_str());

		Point2D p1(x1, y1);

		int findSpace2 = point2.find(" ");
		string strX2 = point2.substr(0, findSpace2);
		string strY2 = point2.substr(findSpace2 + 1);

		double x2 = atof(strX2.c_str());
		double y2 = atof(strY2.c_str());

		Point2D p2(x2, y2);

		Line2D line(p1, p2);

		cout << line.toString() << endl;

	}
	else cout << "Invalid input" << endl;	system("pause");	return 0;}string RemoveSpaces(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			if (str[i + 1] == ' ') {
				str.replace(i, 1, "");
				i--;
			}
		}
		if (i == str.length() - 1)
			if (str[i] == ' ') str.replace(i, 1, "");
	}
	if (str[0] == ' ') str.replace(0, 1, "");
	return str;
}