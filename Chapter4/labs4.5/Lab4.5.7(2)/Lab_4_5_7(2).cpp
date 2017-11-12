#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main(void) {
	cout << "Input three lines" << endl;
	std::string from;
	std::getline(std::cin, from);
	std::string to;
	std::getline(std::cin, to);
	std::string sentence;
	std::getline(std::cin, sentence);

	int i = 0;
	do 
	{
		i = sentence.find(from,i);
		if (i != string::npos)
		{
			sentence.replace(i, from.length(), to);
			i += to.length();
		}
	} while (i != string::npos);
	std::cout << sentence << "\n";
	system("pause");
	return 0;

}