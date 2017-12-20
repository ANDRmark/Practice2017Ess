#include <iostream>

using namespace std;

class Node
{
public:
	Node(int val);
	int value;
	Node* next;
};
Node::Node(int val) : value(val), next(nullptr)
{
}


class List
{
public:
	List();
	void push_front(int value);
	bool pop_front(int &value);
	void push_back(int value);
	bool pop_back(int &value);
	int size() { return listSize; }
private:
	int listSize;
	Node* head;
	Node* tail;
};
List::List() : head(nullptr), tail(nullptr), listSize(0)
{
}
void List::push_front(int value)
{
	Node* new_head = new Node(value);

	if (listSize == 0) tail = new_head;

	new_head->next = head;
	head = new_head;
	listSize++;
}

void List::push_back(int value)
{
	Node *new_tail = new Node(value);

	listSize == 0 ? head = new_tail : tail->next = new_tail;

	tail = new_tail;
	listSize++;
}

bool List::pop_front(int &value)
{
	Node *popped = head;

	if (popped == NULL) return false;

	head = head->next;
	value = popped->value;
	delete popped;
	listSize--;

	return true;
}

bool List::pop_back(int &value) {

	if (!listSize) return false;

	Node *popped = tail;

	if (listSize == 1) {		
		head = NULL;
		tail = NULL;
	}
	else {
		Node *penult = head;
		while (penult->next != tail) {
			penult = penult->next;
		}
		penult->next = NULL;
		tail = penult;		
	}

	value = popped->value;
	delete popped;
	listSize--;

	return true;
}





int main()
{
	List list;

	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);

	int value = 0;
	while (list.pop_back(value))
	{
		cout << value << endl;
	}

	system("pause");
	return 0;
}
