#include "stdafx.h"
#define SIZE 5
template<typename T>
class Queue
{
private:
	int rear;
	int front;

	T* container[SIZE];
public:
	Queue()
	{
		rear = 0;
		front = 0;

		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}

	}
	void push(T data)
	{
		if (rear == SIZE)
		{
			cout << "linear queue overflow" << endl;
		}
		else
		{
			continer[rear++] = data;
		}
	}
	void pop()
	{
		if (front == rear)
		{
			cout << "Queue is empty" << endl;
			exit(1);
		}
		else
		{
			container[front++] = NULL;
		}
	}
	const bool empty() const
	{
		return front == rear;
	}

	const T& peek()const
	{
		if (empty())
		{
			cout << "Queue is empty" << endl;
			exit(1);
		}
		return container[front];
	}
};

int main()
{
	Queue<int> queue;

	return 0;
}