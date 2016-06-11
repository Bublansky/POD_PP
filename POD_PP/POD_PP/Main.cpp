#include"HeapMinPriorityQueue.h"



int main()
{
	int tt;
	int origem, destino;
	//heap_max_priority_queue fila;
	heap_min_priority_queue fila2;

	/*
	fila2.Insert(20, 5);
	fila2.Insert(20, 4);
	fila2.Insert(9, 3);
	fila2.Insert(7, 2);
	fila2.Insert(0, 1);
	*/
	//fila2.Insert(11, 6);
	//cout << fila2.Minimum() << endl;
	//fila2.build_max_heap();
	int k = fila2.Extract_min();

	//cout << fila2.Minimum(A) << endl;

	cin >> tt;
	return 0;
}