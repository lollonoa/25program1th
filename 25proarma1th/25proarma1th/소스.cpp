#include "stdafx.h"
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
		T* temporary = capacity;
		temporary = nullptr;
		pointer = temporary;

	}
};

int main()
{
	Vector<int> vector;

	return 0;
}