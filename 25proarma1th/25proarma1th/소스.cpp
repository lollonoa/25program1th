#include "stdafx.h"
template<typename T>

class PriorityQueue
{
private:
	T* container;

	int index;
	int capacity;
public:
PriorityQueue()
{
	index = 0;
	capacity = 0;
	container = nullptr;
}

void resize(int newSize)
{
	capacity = newSize;

	T* temporary = new T[capacity];
	for (int i = 0; i < capacity; i++)
	{
		temporary[i] = NULL;
	}
	for (int i = 0; i < index; i++)
	{
		temporary[i] = container[i];
	}
	delete[]container;
	container = temporary;
}
void push(T data)
{
	if (capacity <= 0)
	{
		resize(1);
	}
	else if (index >= capacity)
	{
		resize(capacity * 2);
	}
	container[index++] = data;

	int child = index - 1;
	int parent = (child - 1) / 2;

	while (child > 0)
	{
		if (container[parent] < container[child])
		{
			swap(container[parent], container[child]);
		}
		child = parent;
		parent = (child - 1) / 2;
	}
	const T& top()
	{

	}
	const bool & empty()

	~PriorityQueue()
	{

	}
}
};

int main()
{
	PriorityQueue<int> prioritQueue;
	prioritQueue.push(10);
	prioritQueue.push(20);
	prioritQueue.push(5);
	prioritQueue.push(33);
	return 0;
}
