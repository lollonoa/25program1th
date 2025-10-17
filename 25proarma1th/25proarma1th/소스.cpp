#include "stdafx.h"
template<typename T>
class List
{
private:
	struct Node
	{
		Node* previous;
		T data;
		Node* next;
	};

	int size;
	Node* head;
	Node* tail;
public:
	List()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	void push_front(T data)
	{
		Node* newNode=new Node;
		newNode->data = data;
		newNode->next = nullptr;
		newNode->previous = nullptr;
		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			head->previous = newNode;
			newNode->next = head;
			head = newNode;
		}
		size++;
	}

	void pop_front()
	{
		if (head == nullptr)
		{
			cout << "linked list is empty" << endl;
			return;
		}
		else
		{
			Node* deleteNode = head;

			if (head == tail)
			{
				head = nullptr;
				tail = nullptr;
			}
			else
			{
				deleteNode->next->previous = nullptr;
				head = head->next;

			}
			delete deleteNode;

			size--;
		}
	}

	void push_back(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;
		newNode->previous - nullptr;

		if (tail == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			newNode->previous = tail;
			tail = newNode;
		}
		size++;
	}

	void pop_back()
	{
		Node* deleteNode = head;
		head->next = nullptr;
		tail = nullptr;
		if (head == nullptr)
		{
			cout << "linked list is empty" << endl;
			return;
		}

	}
};

int main()
{
	List<int> list;
	list.push_front(10);
	list.push_front(5);

	list.push_back(10);
	list.push_back(20);

	list.pop_front();
	list.pop_front();



	
	return 0;
}