#include "../25proarma1th/stdafx.h"
#define SIZE 5

template<typename T>
class Queue
{
private:
	int rear;
	int front;
	T container[SIZE];

public:
	Queue()
	{
		rear = 0;
		front = 0;
	}

	void push(T data)
	{
		if (rear >= SIZE)
		{
			cout << "linear queue overflow" << endl;
		}
		else
		{
			container[rear++] = data;
		}
	}

	void pop()
	{
		if (empty())
		{
			cout << "linear queue is empty" << endl;
			exit(1);
		}
		else
		{
			front++;
		}
	}

	bool empty() const
	{
		return front == rear;
	}

	const T& peek() const
	{
		if (empty())
		{
			cout << "queue is empty" << endl;
			exit(1);
		}
		return container[front];
	}

	int size() const
	{
		return rear - front;
	}
};

int main()
{
	Queue<int> queue;
	queue.push(10);
	queue.push(20);
	queue.push(30);
	queue.push(40);
	queue.push(50);

	while (!queue.empty())
	{
		cout << queue.peek() << endl;
		queue.pop();
	}

	cout << "Queue Size : " << queue.size() << endl;
	return 0;
}
