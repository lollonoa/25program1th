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
	}
	void push_back(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		
		if (head == nullptr)
		{
			head = newNode;
			newNode->next = head;
		}
		else
		{
			newNode->next = head->next;
			head->next = newNode;
			head = newNode;
		}
	size++;
	}
	void push_front(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;

		if (head == nullptr)
		{
			head = newNode;
			newNode->next = head;
		}
		else
		{
			newNode->next = head->next;

			head->next = newNode;
		}
		size++;
	}
	void pop_front()
	{
		Node* newNode = new Node;
		newNode->data = data;
		
		if (head == nullptr)
		{
			cout << "linked list is empty" << endl;
			return;
		}
		else
		{
			Node* deleteNode = newNode;
			head->next = newNode;
			newNode->next = head->next;
		}
		size--;
	}
};

int main()
{
	List<int> list;

	list.push_back(10);
	list.push_back(20);

	list.push_front(5);
	list.push_front(1);

	list.pop_front();

	return 0;
}