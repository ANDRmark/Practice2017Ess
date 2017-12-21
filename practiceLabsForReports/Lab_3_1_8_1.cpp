#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

//your code
int limit = 15;
bool mypredicate(int i, int j) {
	if (abs(i - j) > limit) return false;
	return true;
}
int main()
{
	vector<int> original_values =
	{ 210, 314, 202, 110, 211, 302, 358, 229, 260, 411, 412, 311, 373, 483 };
	vector<int> noisy_values =
	{ 211, 324, 203, 113, 227, 320, 340, 210, 239, 411, 412, 333, 371, 601 };

	pair<vector<int>::iterator, vector<int>::iterator> mypair;
	limit = 15;
	bool isMismatch = true;
	while (isMismatch)
	{
		mypair = mismatch(original_values.begin(), original_values.end(), noisy_values.begin(), mypredicate);
		if (mypair.first == original_values.end() || mypair.second == noisy_values.end()) break;
		cout << "First difference greater than " << limit << " is found:" << *mypair.first << " - " << *mypair.second << '\n';
		limit++;
		if (limit == 400) isMismatch = false;
	}
	//your code
	return 0;
}