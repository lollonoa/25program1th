﻿#include "../25proarma1th/stdafx.h"

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

		Node* deleteNode = head;

		head = deleteNode->next;

		delete deleteNode;

		size--;
	}

	void push_back(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;

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

	void pop_back()
	{
		if (head == nullptr)
		{
			cout << "Linked List is Empty" << endl;
			return;
		}
		else
		{
			Node* previousNode = nullptr;
			Node* deleteNode = head;

			if (size == 1)
			{
				head = deleteNode->next;
				delete deleteNode;
			}
			else
			{
				while (deleteNode->next != nullptr)
				{
					previousNode = deleteNode;
					deleteNode = deleteNode->next;
				}
				previousNode->next = deleteNode->next;
				delete deleteNode;
			}
			size--;

		}

	}

	const bool& empty()
	{
		return (head == nullptr);
	}

	~List()
	{
		while (head != nullptr)
		{
			pop_front();
		}
	}

};


int main()
{
	cout << "Hello World\n";
	List<int> list;
	list.push_front(10);
	list.push_front(5);
	list.push_front(1);

	list.push_back(20);

	list.pop_front();
	list.pop_back();

	cout << list.empty() << endl;

	return 0;
}