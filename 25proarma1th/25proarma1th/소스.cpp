#include "stdafx.h"
template<typename T>

class Graph
{
private:
	int size; //정점의 개수
	int count; //인접행렬의 크기
	int capacity;//최대용량

	T* vertex;//정점의 집합
	int** matrix;//인접행렬
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
