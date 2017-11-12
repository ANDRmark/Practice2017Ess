#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main(void) {
	string sentence;
	cout << "Input sentence with duplicate spaces" << endl;
	std::getline(std::cin, sentence);
	for (int i = 0; i < sentence.length() - 1; i++)
	{
		if (isspace(sentence[i]) && isspace(sentence[i + 1]))
		{
			sentence.erase(i, 1);
			i--;
		}
	}
	std::cout << sentence << "\n";
	system("pause");
	return 0;

}