#include<iostream>
#include<list>
#include"HeapPriorityQueue.h"

using namespace std;





int main()
{
	int Q[7] = {0, 5, 4, 6, 3, 2, 1};
	int tam = 10, tt;
	//heap_max_priority_queue fila;
	heap_min_priority_queue fila2;

	//fila.build_max_heap(A, tam);
	fila2.build_min_heap(Q, 6);
	fila2.Insert(Q, 20, 5);
	fila2.Insert(Q, 20, 4);
	fila2.Insert(Q, 11, 6);
	fila2.Insert(Q, 9, 3);
	fila2.Insert(Q, 7, 2);
	fila2.Insert(Q, 0, 1);

	cout << fila2.Minimum(Q) << endl;
	//cout << fila2.Minimum(A) << endl;

	///*
	for each (int k in Q)
	{
		cout << k << ", ";
	}

	//*/
	cin >> tt;
	return 0;
}