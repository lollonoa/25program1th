#include "stdafx.h"

template<typename T>
class List
{
private:
	struct Node
	{
		T data;
		Node* next;
	};

	int size;
	Node* head;

public:
	List()
	{
		size = 0;
		head = nullptr;
		currentNode = nullptr;
	}
	void push_front(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		if (head == nullptr)
		{
			head = newNode;

			newNode->next = nullptr;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
		size++;
	}
	void pop_front()
	{
		if (head == nullptr)
		{
			cout << "Linked List is Empty" << endl;
			return;
		}

		Node * deleteNode = head;

		head = deleteNode->next;

		delete deleteNode;

		size--;
	}
	void push_back(T data)
	{
		Node* newNode= new Node;

		newNode->dara = dara;

		newNode->next = nullptr;
		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			Node* currentNode = head;
			while (currentNode->next != nullptr)
			{
				currentNode = currentNode->next;
			}

			currentNode->next = newNode;

		}

		size++;

	}
};


int main()
{
	cout << "Hello World\n";
	List<int> list;
	list.push_front(10);
	list.push_front(5);

	list.pop_front();
	list.pop_front();
	list.pop_front();

	list.push_back(20);
	list.push_back(30);

	return 0;
}