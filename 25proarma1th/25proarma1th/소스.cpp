#include "stdafx.h"
template<typename T>

class Graph
{
private:
	int size; //������ ����
	int count; //��������� ũ��
	int capacity;//�ִ�뷮

	T* vertex;//������ ����
	int** matrix;//�������
public:
	Graph()
	{
		size = 0;
		count = 0;
		capacity = 0;

		vertex = nullptr;
		matrix = nullptr;
	}

};


int main()
{
	Graph<int> graph;
	return 0;
}
