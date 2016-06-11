#pragma once
#include<iostream>

using namespace std;

class heap_max_priority_queue
{
private:
	int heap_size = 0;
	const int infinite = 9999;
	int Queue[50][2];
	int limit = 0;
	//Queue[][0] - key
	//Queue[][1] - value

	int Parent(int i);
	int Left(int i);
	int Right(int i);

public:
	heap_max_priority_queue();
	void build_max_heap();
	void Max_heapify(int i);
	void Insert(int key, int value);
	int Maximum();
	int Extract_max();
	bool Increase_key(int i, int key);
	void ShowQueue();
};

heap_max_priority_queue::heap_max_priority_queue()
{
};
void heap_max_priority_queue::build_max_heap()
{
	int aux;

	/*
	for (int i = heap_size; i >= 1; i--)
	{
		aux = Queue[1][0];
		Queue[1][0] = Queue[i][0];
		Queue[i][0] = aux;

		aux = Queue[1][1];
		Queue[1][1] = Queue[i][1];
		Queue[i][1] = aux;

		Max_heapify(i);
	}
	*/
	///*
	for (int i = trunc(heap_size / 2); i >= 1; i--)
	{
		Max_heapify(i);
	}

	//*/
};
void heap_max_priority_queue::Max_heapify(int i)
{
	int l = Left(i);
	int r = Right(i);
	int largest, aux;

	if (l <= heap_size && Queue[l][0] > Queue[i][0])
	{
		largest = l;
	}
	else
	{
		largest = i;
	}
	if (r <= heap_size && Queue[r][0] > Queue[largest][0])
	{
		largest = r;
	}
	if (largest != i)
	{
		aux = Queue[i][0];
		Queue[i][0] = Queue[largest][0];
		Queue[largest][0] = aux;

		aux = Queue[i][1];
		Queue[i][1] = Queue[largest][1];
		Queue[largest][1] = aux;


		Max_heapify(largest);
	}
};
void heap_max_priority_queue::Insert(int key, int value)
{

	heap_size++;

	Queue[heap_size][0] = -infinite;
	Queue[heap_size][1] = value;

	Increase_key(heap_size, key);

	//build_max_heap();

};
void heap_max_priority_queue::ShowQueue()
{
	for (int i = 1; i < heap_size + 1; i++)
	{
		cout << Queue[i][0] << ", " << Queue[i][1] << endl;
	}
}

int heap_max_priority_queue::Maximum()
{
	//return max key value
	return Queue[1][1];
}
int heap_max_priority_queue::Extract_max()
{
	if (heap_size < 1)
	{
		return -1;
	}

	//max value
	int max = Queue[1][1];

	Queue[1][0] = Queue[heap_size][0];
	Queue[1][1] = Queue[heap_size][1];

	heap_size -= 1;

	Max_heapify(1);

	return max;
};
bool heap_max_priority_queue::Increase_key(int i, int key)
{
	int aux;

	if (key < Queue[i][0])
	{
		return false;
	}

	Queue[i][0] = key;

	while (i > 1 && Queue[Parent(i)][0] < Queue[i][0])
	{
		//trocando as chaves
		aux = Queue[i][0];
		Queue[i][0] = Queue[Parent(i)][0];
		Queue[Parent(i)][0] = aux;

		//trocando os valores
		aux = Queue[i][1];
		Queue[i][1] = Queue[Parent(i)][1];
		Queue[Parent(i)][1] = aux;


		i = Parent(i);
	}
	return true;
};
int heap_max_priority_queue::Parent(int i)
{
	return trunc(i / 2);
};
int heap_max_priority_queue::Left(int i)
{
	return 2 * i;
};
int heap_max_priority_queue::Right(int i)
{
	return 2 * i + 1;
};