#include<iostream>
#include<list>
#include"HeapMaxPriorityQueue.h"

using namespace std;

int main()
{
	int tam = 10, tt;
	//heap_max_priority_queue fila;
	heap_max_priority_queue fila2;

	//fila.build_max_heap(A, tam);
	//fila2.build_min_heap(Q, 6);
	// insert(key, value)
	//ordem na fila: (0, 1), (7, 2), (9, 3), (11, 6), (20, 5), (20, 4)
	//0, 7, 9, 11, 20, 20
	//1, 2, 3, 6, 5, 4

	fila2.Insert(20, 5);
	fila2.Insert(20, 4);
	fila2.Insert(11, 6);
	
	
	fila2.Insert(9, 3);
	
	fila2.Insert(7, 2);
	
	/*
	fila2.Insert(0, 1);
	*/
	

	//cout << fila2.Minimum() << endl;
	//fila2.build_max_heap();

	fila2.ShowQueue();
	//cout << fila2.Minimum(A) << endl;

	cin >> tt;
	return 0;
}