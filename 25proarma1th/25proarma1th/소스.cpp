#include "stdafx.h"
template<typename KEY, typename VALUE>

class HashTable
{
private:
	struct Node
	{
		KEY key;
		VALUE value;
		Node* next;
	};
	struct Bucket
	{
		Node* head;
	};
	int size;
	int capacity;

	Bucket* bucket;
public:
	HashTable()
	{
		size = 0;
		capacity = 0;

		bucket = nullptr;
	}
};

int main()
{


	return 0;
}
