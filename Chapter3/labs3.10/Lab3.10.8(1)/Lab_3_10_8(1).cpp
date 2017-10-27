#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(void) {
	int maxball;
	int ballsno;
	cout << "Max ball number? ";
	cin >> maxball;
	cout << "How many balls? ";
	cin >> ballsno;
	if (maxball < ballsno) cout << "Impossibe" << endl;
	else {
		srand(time(NULL));
		int *mass = new int[ballsno];
		int a = 0;
		bool valuewas;
		for (int i = 0; i < ballsno; i++)
		{
			do
			{
				a = rand() % maxball + 1;
				valuewas = false;
				for (int j = 0; j < i; j++)
				{
					if (*(mass + j) == a)
					{
						valuewas = true;
						break;
					}
				}
				*(mass + i) = a;
			} while (valuewas);
		}
		for (int i = 0; i < ballsno; i++)
		{
			cout.width(6);
			cout << *(mass + i);
		}
		cout << endl;
		delete[] mass;
	}
	system("pause");
	return 0;

}
