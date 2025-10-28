#include "../25proarma1th/stdafx.h"
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
	}
	const bool& empty()
	{
		return index <= 0;
	}

	const int& size()
	{
		return index;
	}

	const T& top()
	{
		if (empty())
		{
			exit(1);
		}
		else
		{
			return container[0];
		}
	}

	void pop()
	{
		if (index <= 0)
		{
			cout << "prinority queue is empty" << endl;
		}
		else
		{
			container[0] = container[--index];
			container[index] = NULL;

			int parent = 0;
			int child = parent * 2 + 1;

			while (child < index)
			{
				child = parent * 2 + 1;

				if (container[child] < container[child + 1])
				{
					child++;
				}
				if (container[child] < container[parent])
				{
					break;
				}
				else
				{
					std::swap(container[child], container[parent]);

					parent = child;
				}
			}
		}

	}
	~PriorityQueue()
	{
		delete[] container;
	}

};

int main()
{
	PriorityQueue<int> prioritQueue;
	prioritQueue.push(10);
	prioritQueue.push(20);
	prioritQueue.push(5);
	prioritQueue.push(33);

	while (prioritQueue.empty() == false)
	{
		cout << prioritQueue.top() << endl;

		prioritQueue.pop();
	}

	cout << "priority Queue is Size : " << prioritQueue.size() << endl;

	cout << prioritQueue.top() << endl;

	return 0;
}
