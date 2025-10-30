#include "stdafx.h"
template<typename KEY, typename VALEU>

class HashTable
{
private:
	struct Node
	{
		KEY key;
		VALEU value;
		Node* next;
	};
	struct Bucket
	{
		int count;
		Node* head;
	};
	int size;
	int capacity;

	Bucket* bucket;
public:
	HashTable()
	{
		size = 0;
		capacity = 8;

		bucket = new Bucket [capacity];

		for (int i = 0; i < capacity; i++)
		{
			bucket[i].head = nullptr;
			bucket[i].count = 0;
		}
	}
	//unsigned int ������ ������ �Լ�
	template<typename KEY>
	unsigned int hash_function(KEY key)
	{
	
		return (unsigned int)key % capacity;
	}
	template<>
	unsigned int hash_function(const char * key)
	{	
		int sum = 0;
		for (int i = 0; *key != '\0'; i++)
		{
			sum += key[i];
			key = key + 1;
		}

		return (unsigned int)sum % capacity;
	}

	void insert(KEY key, VALEU value)
	{
		//�ؽ� �Լ��� ���ؼ� ���� �޴� �ӽ� ����
		int hashIndex = hash_function(key);
		//���ο� ��带 �����մϴ�.
		Node* newNode = new Node;

		newNode->key = key;
		newNode->value = value;
		newNode->next = nullptr;
		//��尡 1���� �������� �ʴµ��
		if (bucket[hashIndex].count == 0)
		{
			//bucket[hashIndex]�� head�����Ͱ� newNode�� ����Ű�� �մϴ�
			bucket[hashIndex].head = newNode;
		}
		else
		{
			newNode->next = bucket[hashIndex].head;

			bucket[hashIndex].head = newNode;
		}
		//bucket[hashIndex]�� ciunt�� ���� ��ŵ�ϴ�
		bucket[hashIndex].count++;

		size++;
	}
	void erase(KEY key)
	{
		//1. �ؽ� �Լ��� ���ؼ� ���� �޴� �ӽú���
		int hashIndex = hash_function(key);

		//2.Node�� Ž���� �� �ִ� ������ ���� ����
		Node* currentNode = bucket[hashIndex].head;
		//3.����Node�� ������ �� �ִ� ������ ���� ����
		Node* previousNode = nullptr;

		//4.currentNode�� nullptr�� ���ٸ� �Լ��� �����մϴ�
		if (currentNode == nullptr)
		{
			cout << "not key found..." << endl;
		}
		else
		{
			//5.currentNode�� �̿��ؼ� ���� ã���� �ϴ� key���� ã���ϴ�.
			while (currentNode != nullptr)
			{
				if (currentNode->key == key)
				{

				if (currentNode == bucket[hashIndex].head)
				{
					bucket[hashIndex].head = currentNode->next;
				}
				else
				{
					previousNode->next = currentNode->next;
				}
				size--;

				bucket[hashIndex].count--;

				delete currentNode;

				return;
			}
			else
			{
				previousNode = currentNode;

				currentNode = currentNode->next;
			}
				
			}

		}
	}

	const int bucket_count()
	{

	}

	const float& load_factor()
	{

	}
};

int main()
{
	HashTable < const char*, int> hashtable;

	hashtable.insert("Abyssal Mask", 3000);
	hashtable.insert("Bami's Cinder", 1000);

	hashtable.insert("Chain Vest", 800);
	
	hashtable.erase("Abyssal Mask");
	hashtable.erase("Galefornce");

	cout << "Load Factor : " << hashtable.load_factor()<<endl;
	cout << "Bucket count : " << hashtable.load_factor()<<endl;
	return 0;
}
