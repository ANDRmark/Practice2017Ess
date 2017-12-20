#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

using namespace std;

class FlightBooking {
public:
	FlightBooking(int id, int capacity, int reserved);
	void printStatus();
	bool reserveSeats(int number_ob_seats);
	bool cancelReservations(int number_ob_seats);
private:
	int id;
	int capacity;
	int reserved;
};
void FlightBooking::printStatus()
{
	std::cout << fixed << setprecision(0) << "Flight " << this->id << ": " << this->reserved << "/" << this->capacity << " (" << double(this->reserved) / this->capacity * 100 << "%) seats taken" << endl;
}
FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
	this->id = id;
	this->capacity = capacity;
	if (reserved > 0) {
		if (double(reserved) / capacity * 100 <= 105) this->reserved = reserved;
		else this->reserved = capacity * 105 / 100;
	}
	else this->reserved = 0;
}
bool FlightBooking::reserveSeats(int number_ob_seats)
{
	if (this->reserved + number_ob_seats <= this->capacity) {
		this->reserved += number_ob_seats;
		return true;
	}
	return false;
}
bool FlightBooking::cancelReservations(int number_of_seats) {
	if (this->reserved - number_of_seats >= 0) {
		this->reserved -= number_of_seats;
		return true;
	}
	return false;
}



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
		if (i == str.length() - 1) {
			if (str[i] == ' ') str.replace(i, 1, "");
		}
	}
	if (str[0] == ' ') str.replace(0, 1, "");
	//if (str[str.length() - 1] == ' ') str.replace(str.length() - 1, 1, "");
	return str;
}

int main() {
	int reserved = 0,
		capacity = 0;

	cout << "Provide flight capacity: ";
	cin >> capacity;
	cout << "Provide number of reserved seats: ";
	cin >> reserved;

	FlightBooking booking(1, capacity, reserved);

	string command;
	int number = 0;

	while (true)
	{
		booking.printStatus();
		cout << "What would you like to do?: ";
		getline(cin, command);

		command = RemoveSpaces(command);
		if (command == "quit") break;

		int findSpace1 = command.find(" ");
		if (findSpace1 == string::npos) {
			cout << "Cannot perform this operation" << endl;
		}
		else {

			string action = command.substr(0, findSpace1);
			if (action == "add" || action == "cancel") {

				string quantity = command.substr(findSpace1 + 1);

				if (OnlyNumbersInString(quantity)) {
					number = atoi(quantity.c_str());
					if (action == "add") 
						if (!booking.reserveSeats(number)) cout << "Cannot perform this operation" << endl;

					else if (action == "cancel")
						if (!booking.cancelReservations(number)) cout << "Cannot perform this operation" << endl;
				}
				else cout << "Cannot perform this operation : invalid input number" << endl;

			}
			else cout << "Operation is not found" << endl;
		}

	}

	system("pause");
	return 0;
}
