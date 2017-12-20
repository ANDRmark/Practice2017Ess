#include <iostream>

using namespace std;

class Node
{
public:
	Node(int val);
	~Node();
	int value;
	Node* next;
};
Node::Node(int val) : value(val), next(nullptr)
{
	//cout << "+Node" << endl;
}
Node::~Node()
{
	//cout << "-Node" << endl;
}


class List
{
public:
	List();
	~List();
	void push_front(int value);
	bool pop_front(int &value);
	int size();
private:
	Node* head;
	int listSize;
};
List::List() : head(nullptr), listSize(0)
{
}
List::~List() {
	cout << "List was deleted" << endl;
}
void List::push_front(int value)
{
	Node* new_head = new Node(value);
	new_head->next = head;
	head = new_head;
	listSize++;
}
bool List::pop_front(int &value)
{
	if (head == NULL) return false;

	Node *popped = head;
	head = head->next;
	value = popped->value;
	delete popped;
	listSize--;

	return true;
}
int List::size() {
	return listSize;
}
//int List::size() {
//	int counter = 0;
//	Node *n = head;
//	do {
//		counter++;
//		n = n->next;
//	} while (n != NULL);
//	return counter;
//}





int main()
{
	List list;

	for (int i = 0; i <= 5; i++)
	{
		list.push_front(i);
		cout << "pushed " << i << ", size: " << list.size() << endl;
	}

	cout << endl;

	int value = 0;
	for (int i = 0; i <= 2; i++)
	{		
		list.pop_front(value);
		cout << "popped " << value << ", size: " << list.size() << endl;
	}

	system("pause");
	return 0;
}
