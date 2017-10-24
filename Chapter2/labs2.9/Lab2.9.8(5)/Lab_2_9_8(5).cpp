#include <iostream>
using namespace std;
int main()
{
	double matrix[][4] = { { 1, 2, 3, 4 },
	{ 2, 2, 3, 1 },
	{ 3, 3, 3, 2 },
	{ 4, 1, 2, 4 } };
	int side = sizeof(matrix[0]) / sizeof(matrix[0][0]);
	bool issymmetric = true;
	// Insert your code here
	for (int i = 0; i < side; i++)
	{
		for (int j = i; j < side; j++)
		{
			if (matrix[i][j] != matrix[j][i])
			{
				issymmetric = false;
				break;
			}
		}
		if (!issymmetric)
			break;
	}
	if (issymmetric)
		cout << "The matrix is symmetric" << endl;
	else
		cout << "The matrix is not symmetric" << endl;
	system("pause");
	return 0;
}