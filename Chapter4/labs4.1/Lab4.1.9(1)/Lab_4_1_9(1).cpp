#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
int main(void) {
	int **grades;
	int numberofcourses;
	int *numberofgradesincourse;
	cout << "Input number of courses" << endl;
	cin >> numberofcourses;
	numberofgradesincourse = new int[numberofcourses];
	grades = new int*[numberofcourses];
	for (int i = 0; i < numberofcourses; i++)
	{
		cin >> numberofgradesincourse[i];
		grades[i] = new int[numberofgradesincourse[i]];
		for (int j = 0; j < numberofgradesincourse[i]; j++)
		{
			cin >> grades[i][j];
		}
	}
	cout << fixed << setprecision(2);
	for (int i = 0; i < numberofcourses; i++)
	{
		cout << "Course " << (i + 1) << ": ";
		float courseavg = 0;
		for (int j = 0; j < numberofgradesincourse[i]; j++)
		{
			courseavg += grades[i][j];
		}
		courseavg /= numberofgradesincourse[i];
		cout << "final " << courseavg << ", grades: ";
		for (int j = 0; j < numberofgradesincourse[i]; j++)
		{
			cout.width(2);
			cout << grades[i][j];
		}
		cout << endl;
	}
	float overallavg = 0;
	int allgradesnum = 0;
	for (int i = 0; i < numberofcourses; i++)
	{
		for (int j = 0; j < numberofgradesincourse[i]; j++)
		{
			overallavg += grades[i][j];
			allgradesnum++;
		}
	}
	overallavg /= allgradesnum;
	cout << "Overall final " << overallavg << endl;
	for (int i = 0; i < numberofcourses; i++)
	{
		delete[] grades[i];
	}
	delete[] grades;
	delete[] numberofgradesincourse;
	system("pause");
	return 0;

}
