#include <iostream>
#include <string>

using namespace std;

class ShopItemOrder {
private: string unitName;
		 int unitPrice;
		 int numberOrdered;
public: string GetName() {
			return unitName;
		}
		void SetName(string name) {
			this->unitName = name;
		}
		int GetPrice() {
			return unitPrice;
		}
		void SetPrice(int unitPrice) {
			this->unitPrice = unitPrice;
		}
		int GetNumberOrdered() {
			return numberOrdered;
		}
		void SetNumberOrdered(int numberOrdered) {
			this->numberOrdered = numberOrdered;
		}
		int GetTotalPrice() {
			return numberOrdered * unitPrice;
		}
		void print() {
			cout << this->unitName << " was ordered in a quantity of " << this->numberOrdered << ". The total price: " << this->GetTotalPrice() << endl;
		}
};

int main(void) {

	ShopItemOrder shopItemOrder;
	shopItemOrder.SetName("Apple");
	shopItemOrder.SetPrice(2);
	shopItemOrder.SetNumberOrdered(10);
	shopItemOrder.print();

	system("pause");
	return 0;
}

