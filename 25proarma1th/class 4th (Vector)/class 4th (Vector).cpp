#include "../25proarma1th/stdafx.h"
template<typename T>
class Vector
{
private:
	int count;
	int capacity;

	T* pointer;

public:
	Vector()
	{

		count = 0;
		capacity = 0;
		pointer = nullptr;
	}
	void resize(int newSize)
	{
		capacity = newSize;
		T* temporary = new T[capacity];
		for (int i = 0; i < capacity; i++)
		{
			temporary[i] = NULL;
		}
		for (int i = 0; i < count; i++)
		{
			temporary[i] = pointer[i];
		}

		delete[] pointer;

		pointer = temporary;

	}

	void push_back(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}
		else if (count >= capacity)
		{
			resize(capacity * 2);
		}
		pointer[count++] = data;
	}

	void pop_back()
	{
		if (count == 0)
		{
			cout << "Vector is empty" << endl;
			return;
		}
		else
		{
			pointer[--count] = NULL;
		}
	}
	const int& size()
	{
		return count;
	}

	const T& operator[](const int& index)
	{
		return pointer[index];
	}
	~Vector()

	{
		delete[] pointer;
	}


};

int main()
{
	Vector<int> vector;

	vector.push_back(10);
	vector.push_back(20);
	vector.push_back(30);
	vector.push_back(40);
	vector.push_back(50);

	vector.pop_back();

	for (int i = 0; i < vector.size(); i++)
	{
		cout << vector[i] << endl;
	}

	return 0;
}