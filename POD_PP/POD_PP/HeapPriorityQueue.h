#include<iostream>
class heap_min_priority_queue
{
private:
	int heap_size;
	const int infinite = 9999;
	int values[];

public:
	heap_min_priority_queue();
	void build_min_heap(int A[], int size);
	void Min_heapify(int A[], int i);
	void Insert(int A[], int key, int value);
	int Minimum(int A[]);
	int Extract_min(int A[]);
	bool Decrease_key(int A[], int i, int key);
	int Parent(int i);
	int Left(int i);
	int Right(int i);
};
heap_min_priority_queue::heap_min_priority_queue()
{

};
void heap_min_priority_queue::build_min_heap(int A[], int size)
{
	heap_size = size;

	for (int i = trunc(size / 2); i >= 1; i--)
	{
		Min_heapify(A, i);
	}
};
void heap_min_priority_queue::Min_heapify(int A[], int i)
{
	int l = Left(i);
	int r = Right(i);
	int smallest, aux;

	if (l <= heap_size && A[i] > A[l])
	{
		smallest = l;
	}
	else
	{
		smallest = i;
	}
	if (r <= heap_size && A[r] < A[smallest])
	{
		smallest = r;
	}
	if (smallest != i)
	{
		//troca as chaves
		aux = A[i];
		A[i] = A[smallest];
		A[smallest] = aux;

		//troca os valores
		aux = values[i];
		values[i] = values[smallest];
		values[smallest] = aux;

		Min_heapify(A, smallest);
	}
};
void heap_min_priority_queue::Insert(int A[], int key, int value)
{
	heap_size++;

	A[heap_size] = infinite;
	values[heap_size] = value;

	Decrease_key(A, heap_size, key);
};
int heap_min_priority_queue::Minimum(int A[])
{
	return values[1];
}
int heap_min_priority_queue::Extract_min(int A[])
{
	if (heap_size < 1)
	{
		return -1;
	}

	//int min = A[1];
	int min = values[1];

	A[1] = A[heap_size];
	values[1] = values[heap_size];

	heap_size -= 1;

	Min_heapify(A, 1);

	return min;
};
bool heap_min_priority_queue::Decrease_key(int A[], int i, int key)
{
	int aux;

	if (key > A[i])
	{
		return false;
	}

	A[i] = key;

	while (i > 1 && A[Parent(i)] > A[i])
	{
		//troca de chaves
		aux = A[i];
		A[i] = A[Parent(i)];
		A[Parent(i)] = aux;

		//troca de valores
		aux = values[i];
		values[i] = values[Parent(i)];
		values[Parent(i)] = aux;

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





































class heap_max_priority_queue
{
private:
	int heap_size;
	const int infinite = 9999;

public:
	heap_max_priority_queue();
	void build_max_heap(int A[], int size);
	void Max_heapify(int A[], int i);
	void Insert(int A[], int key);
	int Maximum(int A[]);
	int Extract_max(int A[]);
	bool Increase_key(int A[], int i, int key);
	int Parent(int i);
	int Left(int i);
	int Right(int i);
};

heap_max_priority_queue::heap_max_priority_queue()
{
};
void heap_max_priority_queue::build_max_heap(int A[], int size)
{
	heap_size = size;

	for (int i = trunc(size / 2); i >= 1; i--)
	{
		Max_heapify(A, i);
	}
};
void heap_max_priority_queue::Max_heapify(int A[], int i)
{
	int l = Left(i);
	int r = Right(i);
	int largest, aux;

	if (l <= heap_size && A[l] > A[i])
	{
		largest = l;
	}
	else
	{
		largest = i;
	}
	if (r <= heap_size && A[r] > A[largest])
	{
		largest = r;
	}
	if (largest != i)
	{
		aux = A[i];
		A[i] = A[largest];
		A[largest] = aux;

		Max_heapify(A, largest);
	}
};
void heap_max_priority_queue::Insert(int A[], int key)
{
	heap_size++;

	A[heap_size] = -infinite;

	Increase_key(A, heap_size, key);
};
int heap_max_priority_queue::Maximum(int A[])
{
	return A[1];
}
int heap_max_priority_queue::Extract_max(int A[])
{
	if (heap_size < 1)
	{
		return -1;
	}

	int max = A[1];

	A[1] = A[heap_size];

	heap_size -= 1;

	Max_heapify(A, 1);

	return max;
};
bool heap_max_priority_queue::Increase_key(int A[], int i, int key)
{
	int aux;

	if (key < A[i])
	{
		return false;
	}

	A[i] = key;

	while (i > 1 && A[Parent(i)] < A[i])
	{
		aux = A[i];
		A[i] = A[Parent(i)];
		A[Parent(i)] = aux;
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