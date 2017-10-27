#include <iostream>
using namespace std;
int main()
{
	int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
	int n = sizeof(vector) / sizeof(vector[0]);
	int *searcher, *min;
	min = vector;
	searcher = min;
	for (int i = 0; i < n; i++)
	{
		if (*searcher < *min)
		{
			min = searcher;
		}
		searcher = searcher + 1;
	}
	cout << *min << endl;
	system("pause");
	return 0;
}