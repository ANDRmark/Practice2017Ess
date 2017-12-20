#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

using namespace std;

class FlightBooking {
public:
	FlightBooking(int id, int capacity, int reserved);
	FlightBooking::FlightBooking(int id, int capacity);
	FlightBooking();
	void printStatus();
	bool reserveSeats(int number_ob_seats);
	bool cancelReservations(int number_ob_seats);
	int getId() { return id; }
	void setID(int id) { this->id = id; }
private:
	int id;
	int capacity;
	int reserved;
};
FlightBooking::FlightBooking()
{
	id = 0; capacity = 0; reserved = 0;
}
FlightBooking::FlightBooking(int id, int capacity) {
	this->id = id;
	this->capacity = capacity;
	this->reserved = 0;
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
void FlightBooking::printStatus()
{
	std::cout << fixed << setprecision(0) << "Flight " << this->id << ": " << this->reserved << "/" << this->capacity << " (" << double(this->reserved) / this->capacity * 100 << "%) seats taken" << endl;
}
bool FlightBooking::reserveSeats(int number_ob_seats)
{
	if (this->reserved + number_ob_seats <= 105./100 * this->capacity) {
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
		if (i == str.length() - 1) 
			if (str[i] == ' ') str.replace(i, 1, "");
	}
	if (str[0] == ' ') str.replace(0, 1, "");
	return str;
}
int IndexOfElementByID(FlightBooking arr[], int arrLength, int id) {
	int number = 0;
	for (int i = 0; i < arrLength; i++) {
		if (arr[i].getId() == id) return i;
	}
	return -1;
}

int main() {
	FlightBooking booking[10];
	booking[4] = FlightBooking(112, 400, 0);

	int bookingLength = sizeof(booking) / sizeof(booking[0]);
	string command = "";

	while (true)
	{
		for (int i = 0; i < bookingLength; i++) {
			if (booking[i].getId()) booking[i].printStatus();
		}

		cout << endl << "What would you like to do?: ";
		getline(cin, command);

		command = RemoveSpaces(command);
		if (command == "quit") break;

		int findSpace1 = command.find(" ");
		if (findSpace1 == string::npos) cout << "Cannot perform this operation : invalid input" << endl;
		else {

			string action = command.substr(0, findSpace1);
			if (action == "delete") {

				string strID = command.substr(findSpace1 + 1);
				if (OnlyNumbersInString(strID)) {

					int index = IndexOfElementByID(booking, bookingLength, atoi(strID.c_str()));
					if (index != -1) booking[index].setID(0);
					else cout << "Cannot perform this operation : no flight with such id" << endl;

				}
				else cout << "Cannot perform this operation : invalid id" << endl;

			}
			else if (action == "add" || action == "cancel" || action == "create") {

				int findSpace2 = command.substr(findSpace1 + 1).find(" ");
				if (findSpace2 == string ::npos) cout << "Cannot perform this operation : invalid input" << endl;
				else {

					string strID = command.substr(findSpace1 + 1, findSpace2);
					string strNumber = command.substr(findSpace1 + findSpace2 + 2);

					if (OnlyNumbersInString(strID) && OnlyNumbersInString(strNumber)) {
						
						int id = atoi(strID.c_str());
						int number = atoi(strNumber.c_str());

						if (action == "create") {	

							if (IndexOfElementByID(booking, bookingLength, id) == -1) {

								for (int i = 0; i < bookingLength; i++) {
									if (booking[i].getId() == 0) {
										booking[i] = FlightBooking(id, number, 0);
										break;
									}
								}

							}
							else cout << "Cannot perform this operation : flight with such id already exist" << endl;

						}
						else {

							int index = IndexOfElementByID(booking, bookingLength, id);
							if (index != -1) {
								if (action == "add") {
									if (!booking[index].reserveSeats(number)) cout << "Cannot perform this operation : capacity reached" << endl;
								}
								else {
									if (!booking[index].cancelReservations(number)) cout << "Cannot perform this operation : not enough seats to cancel" << endl;
								}
							}
							else cout << "Cannot perform this operation : no flight with such id" << endl;

						}

					}
					else cout << "Cannot perform this operation : invalid input" << endl;

				}

			}
			else cout << "Operation is not found" << endl;

		}

	}

	system("pause");
	return 0;
}