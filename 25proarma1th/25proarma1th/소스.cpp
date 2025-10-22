#include "stdafx.h"
template<typename T>

class Stack
{
private:
	int highset;
	int capacity;

	T* container;
public:
	Stack()
	{
		highset = -1;
		capacity = 0;

		container = nullptr;

	}
	void push(T data)
	{
		T* resize = new T[highset];
		for (int i = 0; i < capacity; i++)
		{
			resize[i] = NULL;
		}
	}
};

int main()
{


	return 0;
}