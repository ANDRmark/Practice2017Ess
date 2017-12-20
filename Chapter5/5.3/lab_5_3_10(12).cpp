#include <iostream>
#include <string>
#include <regex>

using namespace std;

class FarmAnimal {
public:
	FarmAnimal(double weight, double water_consumption);
	double getWaterConsumption();
private:
	double water_consumption;
	double weight;
};
FarmAnimal::FarmAnimal(double weight, double water_consumption) {
	weight < 1 ? this->weight = 20 : this->weight = weight;
	water_consumption < 1 ? this->water_consumption = 1 : this->water_consumption = water_consumption;
}
double FarmAnimal::getWaterConsumption() {
	if (this->water_consumption == 8.6 || this->water_consumption == 6.8) return water_consumption * weight / 100;
	return water_consumption * weight / 10;
}


class Cow : public FarmAnimal {
public:
	Cow(double weight, double water_consumption);
};
Cow::Cow(double weight, double water_consumption) : FarmAnimal(weight, water_consumption) { }


class Sheep : public FarmAnimal {
public:
	Sheep(double weight, double water_consumption);
};
Sheep::Sheep(double weight, double water_consumption) : FarmAnimal(weight, water_consumption) { }


class Horse : public FarmAnimal {
public:
	Horse(double weight, double water_consumption);
};
Horse::Horse(double weight, double water_consumption) : FarmAnimal(weight, water_consumption) { }


class ConsumptionAccumulator
{
public:
	ConsumptionAccumulator();
	double getTotalConsumption();
	void addConsumption(FarmAnimal animal);
private:
	double total_consumption;
};
ConsumptionAccumulator::ConsumptionAccumulator() : total_consumption(0)
{
}
double ConsumptionAccumulator::getTotalConsumption()
{
	return total_consumption;
}
void ConsumptionAccumulator::addConsumption(FarmAnimal animal)
{
	total_consumption += animal.getWaterConsumption();
}




string RemoveSpaces(string str);

int main()
{
	ConsumptionAccumulator accumulator;
	
	cout << "!There is only cow, sheep and horse!" << endl;
	cout << "!Input animal names with lower-case letters!" << endl << endl;

	string input1 = "", input2 = "", input3 = "";
	getline(cin, input1);
	getline(cin, input2);
	getline(cin, input3);

	input1 = RemoveSpaces(input1);
	input2 = RemoveSpaces(input2);
	input3 = RemoveSpaces(input3);

	regex pattern("^(cow|sheep|horse)\\s\\d+(\.\\d+)?$");

	if (regex_match(input1, pattern) && regex_match(input2, pattern) && regex_match(input3, pattern)) {

		int findSpace1 = input1.find(" ");
		string strAnimal1 = input1.substr(0, findSpace1);
		string strWeight1 = input1.substr(findSpace1 + 1);
		double weight1 = atof(strWeight1.c_str());

		int findSpace2 = input2.find(" ");
		string strAnimal2 = input2.substr(0, findSpace2);
		string strWeight2 = input2.substr(findSpace2 + 1);
		double weight2 = atof(strWeight2.c_str());

		int findSpace3 = input3.find(" ");
		string strAnimal3 = input3.substr(0, findSpace3);
		string strWeight3 = input3.substr(findSpace3 + 1);
		double weight3 = atof(strWeight3.c_str());


		FarmAnimal *f1;
		FarmAnimal *f2;
		FarmAnimal *f3;

		if (strAnimal1 == "cow") f1 = new Cow(weight1, 8.6);
		else if (strAnimal1 == "sheep") f1 = new Sheep(weight1, 1.1);
		else f1 = new Horse(weight1, 6.8);

		if (strAnimal2 == "cow") f2 = new Cow(weight2, 8.6);
		else if (strAnimal2 == "sheep") f2 = new Sheep(weight2, 1.1);
		else f2 = new Horse(weight1, 6.8);

		if (strAnimal3 == "cow") f3 = new Cow(weight3, 8.6);
		else if (strAnimal3 == "sheep") f3 = new Sheep(weight3, 1.1);
		else f3 = new Horse(weight3, 6.8);

		accumulator.addConsumption(*f1);
		accumulator.addConsumption(*f2);
		accumulator.addConsumption(*f3);

		cout << accumulator.getTotalConsumption() << endl;

	}
	else cout << "Invalid input" << endl;

	cout << accumulator.getTotalConsumption() << endl;

	system("pause");
	return 0;
}string RemoveSpaces(string str) {
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