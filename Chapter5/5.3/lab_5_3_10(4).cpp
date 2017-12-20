#include <iostream>
#include <string>

using namespace std;

class GymMembeship {
private:
	int userID;
	string name;
	int numberOfMonth;
public:
	int getId() { return userID; }
	void setId(int id) {
		this->userID = id;
	}
	GymMembeship() {
		this->userID = 0;
		this->name = "";
		this->numberOfMonth = 0;
	}
	GymMembeship(int userID, string name, int numberOfMonth) {
		this->userID = userID;
		this->name = name;
		if (numberOfMonth <= 12) this->numberOfMonth = numberOfMonth;
		else this->numberOfMonth = 0;
	}
	void print() {
		cout << "member " << this->userID << " : " << this->name << " subscription valid for " << this->numberOfMonth << " month" << endl;
	}
	bool increaseMonth(int numberOfMonth) {
		if (this->numberOfMonth + numberOfMonth <= 12) {
			this->numberOfMonth += numberOfMonth;
			return true;
		}
		return false;
	}
	void cancelSubscription(void) {
		this->numberOfMonth = 0;
	}

};





bool OnlyNumbersInString(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] < '0' || str[i]  > '9') return false;
	}
	return true;
}
string RemoveSpaces(string str) {
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
int IndexOfElementByID(GymMembeship arr[], int arrLength, int id) {
	int number = 0;
	for (int i = 0; i < arrLength; i++) {
		if (arr[i].getId() == id) return i;
	}
	return -1;
}

int main() {
	GymMembeship members[10];
	members[0] = GymMembeship(1, "Nick", 6);

	int membersNumber = sizeof(members) / sizeof(members[0]);
	string command = "";

	while (true)
	{
		for (int i = 0; i < membersNumber; i++) {
			if (members[i].getId()) members[i].print();
		}

		cout << endl << "What would you like to do?: ";
		getline(cin, command);

		command = RemoveSpaces(command);
		if (command == "quit") break;

		int findSpace1 = command.find(" ");
		if (findSpace1 == string::npos) cout << "Cannot perform this operation : invalid input" << endl;
		else {

			string action = command.substr(0, findSpace1);
			if (action == "cancel" || action == "delete") {

				string strID = command.substr(findSpace1 + 1);
				if (OnlyNumbersInString(strID)) {

					int index = IndexOfElementByID(members, membersNumber, atoi(strID.c_str()));
					if (index != -1) {

						if (action == "delete") members[index].setId(0);
						else members[index].cancelSubscription();

					}
					else cout << "Cannot perform this operation : no member with such id" << endl;

				}
				else cout << "Cannot perform this operation : invalid id" << endl;

			}

			else {
				int findSpace2 = command.substr(findSpace1 + 1).find(" ");
				if (action == "extend") {
					if (findSpace2 == string::npos) cout << "Cannot perform this operation : invalid input" << endl;
					else {

						string strID = command.substr(findSpace1 + 1, findSpace2);
						string strNumber = command.substr(findSpace1 + findSpace2 + 2);

						if (OnlyNumbersInString(strID) && OnlyNumbersInString(strNumber)) {
							int id = atoi(strID.c_str());
							int number = atoi(strNumber.c_str());

							int index = IndexOfElementByID(members, membersNumber, id);
							if (index != -1) {
								if (!members[index].increaseMonth(number)) cout << "Month can not be increased by this value" << endl;
							}
							else cout << "Cannot perform this operation : no member with such id" << endl;
						}
						else cout << "Cannot perform this operation : invalid input" << endl;

					}
				}
				else if (action == "create") {

					string strID = command.substr(findSpace1 + 1, findSpace2);
					string name = command.substr(findSpace1 + findSpace2 + 2);

					if (OnlyNumbersInString(strID)) {
						int id = atoi(strID.c_str());

						if (IndexOfElementByID(members, membersNumber, id) == -1) {

							for (int i = 0; i < membersNumber; i++) {
								if (members[i].getId() == 0) {
									members[i] = GymMembeship(id, name, 0);
									break;
								}
							}

						}
						else cout << "Cannot perform this operation : member with such id already exist" << endl;
					}

				}
				else cout << "Operation is not found" << endl;
			}

		}

	}

	system("pause");
	return 0;
}