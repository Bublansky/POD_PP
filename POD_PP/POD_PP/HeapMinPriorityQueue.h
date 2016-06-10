#include<iostream>

using namespace std;

class heap_min_priority_queue
{
private:
	int heap_size = 0;
	const int infinite = 9999;
	int Queue[50][2];

	int Parent(int i);
	int Left(int i);
	int Right(int i);

public:
	heap_min_priority_queue();
	void build_min_heap();
	void Min_heapify(int i);
	void Insert(int key, int value);
	int Minimum();
	int Extract_min();
	bool Decrease_key(int i, int key);
	
	void ShowQueue();
};
heap_min_priority_queue::heap_min_priority_queue()
{
};
void heap_min_priority_queue::ShowQueue()
{
	for (int i = 1; i < heap_size + 1; i++)
	{
		cout << Queue[i][0] << ", " << Queue[i][1] << endl;
	}
}
void heap_min_priority_queue::build_min_heap()
{

	for (int i = trunc(heap_size / 2); i >= 1; i--)
	{
		Min_heapify(i);
	}
};
void heap_min_priority_queue::Min_heapify(int i)
{
	int l = Left(i);
	int r = Right(i);
	int smallest, aux;

	if (l <= heap_size && Queue[i][0] > Queue[l][0])
	{
		smallest = l;
	}
	else
	{
		smallest = i;
	}
	if (r <= heap_size && Queue[r][0] < Queue[smallest][0])
	{
		smallest = r;
	}
	if (smallest != i)
	{
		//troca as chaves
		aux = Queue[i][0];
		Queue[i][0] = Queue[smallest][0];
		Queue[smallest][0] = aux;

		//troca os valores
		aux = Queue[i][1];
		Queue[i][1] = Queue[smallest][1];
		Queue[smallest][1] = aux;

		Min_heapify(smallest);
	}
};
void heap_min_priority_queue::Insert(int key, int value)
{
	//aumenta a quantidade de itens na fila
	heap_size++;

	//A[heap_size] = infinite;

	//indice 0 é a key
	Queue[heap_size][0] = infinite;
	Queue[heap_size][1] = value;
	//values[heap_size] = value;

	Decrease_key(heap_size, key);
	//Min_heapify(heap_size);
};
int heap_min_priority_queue::Minimum()
{
	return Queue[1][1];
}
int heap_min_priority_queue::Extract_min()
{
	if (heap_size < 1)
	{
		return -1;
	}

	//int min = A[1];
	int min = Queue[1][1];

	Queue[1][0] = Queue[heap_size][0];
	Queue[1][1] = Queue[heap_size][1];

	heap_size -= 1;

	Min_heapify(1);

	return min;
};
bool heap_min_priority_queue::Decrease_key(int i, int key)
{
	int aux;

	if (key > Queue[i][0])
	{
		return false;
	}

	Queue[i][0] = key;

	while (i > 1 && Queue[Parent(i)][0] > Queue[i][0])
	{
		//troca de chaves
		aux = Queue[i][0];
		Queue[i][0] = Queue[Parent(i)][0];
		Queue[Parent(i)][0] = aux;

		//troca de valores
		aux = Queue[i][1];
		Queue[i][1] = Queue[Parent(i)][1];
		Queue[Parent(i)][1] = aux;

		i = Parent(i);
	}
	return true;
};
int heap_min_priority_queue::Parent(int i)
{
	return trunc(i / 2);
};
int heap_min_priority_queue::Left(int i)
{
	return 2 * i;
};
int heap_min_priority_queue::Right(int i)
{
	return 2 * i + 1;
};



































