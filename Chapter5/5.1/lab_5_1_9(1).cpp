#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	string name;
	int age;
	string surname;
	string city;
	bool married;
};

void print(Person* person)
{
	cout << person->name << " is " << person->age << " years old" << endl;
}

int main()
{
	Person person;
	person.name = "Harry";
	person.age = 23;
	cout << "Meet " << person.name << endl;
	print(&person);

	person.surname = "Pupkin";
	person.city = "London";
	person.married = true;

	cout << "His surname is " << person.surname << " and he lives in " << person.city << endl;
	if (person.married) cout << person.name << " is also married" << endl;
	else cout << person.name << " is not married" << endl;

	system("pause");
	return 0;
}