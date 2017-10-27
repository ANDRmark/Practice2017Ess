#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Collection {
	int elno;
	int *elements;
};
void AddToCollection(Collection &col, int element) {
	if (col.elements == NULL || sizeof(col.elements) == 0)
	{
		col.elements = new int[1]{ element };
		col.elno = 1;
	}
	else
	{
		int length = col.elno;
		int *newmass = new int[length + 1];
		for (int i = 0; i < length; i++)
			*(newmass + i) = *(col.elements + i);
		*(newmass + length) = element;
		delete[] col.elements;
		col.elements = newmass;
		col.elno = length + 1;
	}
}
void PrintCollection(Collection col) {
	cout << "[ ";
	for (int i = 0; i < col.elno; i++)
		cout << col.elements[i] << " ";
	cout << "]" << endl;
}
int main(void) {
	Collection collection = { 0, NULL };
	int elems;
	cout << "How many elements? ";
	cin >> elems;
	srand(time(NULL));
	for (int i = 0; i < elems; i++)
		AddToCollection(collection, rand() % 100 + 1);
	PrintCollection(collection);
	delete[] collection.elements;
	system("pause");
	return 0;
}