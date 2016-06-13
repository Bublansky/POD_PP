#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

class heap_min_priority_queue
{
private:
	int heap_size;
	int infinite;
	int Queue[51][2];

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
	void Increase_Priority(int value, int key);

	void ShowQueue();
};
heap_min_priority_queue::heap_min_priority_queue()
{
	heap_size = 0;
	infinite = 9999;
};
void heap_min_priority_queue::ShowQueue()
{
	for (int i = 1; i <= heap_size; i++)
	{
		cout << Queue[i][0] << ", " << Queue[i][1] << endl;
	}
}
void heap_min_priority_queue::build_min_heap()
{

	for (int i = (int) trunc(heap_size / 2); i >= 1; i--)
	{
		Min_heapify(i);
	}
};
void heap_min_priority_queue::Min_heapify(int i)
{
	int l = Left(i);
	int r = Right(i);
	int smallest, aux1, aux2;

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
		aux1 = Queue[i][0];
		Queue[i][0] = Queue[smallest][0];
		Queue[smallest][0] = aux1;

		//troca os valores
		aux2 = Queue[i][1];
		Queue[i][1] = Queue[smallest][1];
		Queue[smallest][1] = aux2;

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
	Min_heapify(heap_size);
	//build_min_heap();
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
	int aux1, aux2;

	if (key > Queue[i][0])
	{
		return false;
	}

	Queue[i][0] = key;

	while (i > 1 && Queue[Parent(i)][0] > Queue[i][0])
	{
		//troca de chaves
		aux1 = Queue[i][0];
		Queue[i][0] = Queue[Parent(i)][0];
		Queue[Parent(i)][0] = aux1;

		//troca de valores
		aux2 = Queue[i][1];
		Queue[i][1] = Queue[Parent(i)][1];
		Queue[Parent(i)][1] = aux2;

		i = Parent(i);
	}
	return true;
};
void heap_min_priority_queue::Increase_Priority(int value, int key)
{
	int aux1, aux2;

	for (int i = 1; i <= heap_size; i++)
	{
		if (value == Queue[i][1])
		{
			if (key > Queue[i][0])
			{
				return;
			}

			Queue[i][0] = key;

			while (i > 1 && Queue[Parent(i)][0] > Queue[i][0])
			{
				//troca de chaves
				aux1 = Queue[i][0];
				Queue[i][0] = Queue[Parent(i)][0];
				Queue[Parent(i)][0] = aux1;

				//troca de valores
				aux2 = Queue[i][1];
				Queue[i][1] = Queue[Parent(i)][1];
				Queue[Parent(i)][1] = aux2;

				i = Parent(i);
			}
			return;
		}
	}
	

	
};
int heap_min_priority_queue::Parent(int i)
{
	return (int) trunc(i / 2);
};
int heap_min_priority_queue::Left(int i)
{
	return 2 * i;
};
int heap_min_priority_queue::Right(int i)
{
	return 2 * i + 1;
};

/*
struct No
{
	int Vertice, Peso;
	No *Proximo;
};
*/


int distancias[50];
int caminho[50];
int vertices;
int infinito = 9999;
int indefinido = -1;
int adjacencias[50][50];
int destino;
//No adjacency_list[50];


/*
void Dijkstra(int origem)
{
	distancias[origem] = 0;
	//cout << endl << "origem: " << origem;
	heap_min_priority_queue fila;
	for (int i = 1; i <= vertices; i++)
	{
		if (i != origem)
		{
			distancias[i] = infinito;
			caminho[i] = indefinido;
		}
		fila.Insert(distancias[i], i);
	}

	//fila.ShowQueue();
	int candidato;
	//vértice mais próximo
	int vmp;
	vmp = fila.Extract_min();
	//cout << endl << vmp << endl;
	//cout << "primeiro da fila:" << vmp;
	No aux;
	//enquanto a fila de prioridade não está vazia
	//vmp = fila.Extract_min();
	//vmp = fila.Extract_min();
	//cout << endl << vmp << endl << "hello";

	//fila.ShowQueue();

	//cout << endl << "hello";
	while (vmp > 0)
	{
		//cout << endl << vmp << endl << "hello";
		//cout << endl << vmp;
		
		aux = adjacency_list[vmp];
		//cout << endl << "hello2";
		//percorre todos os vizinho de vmp
		while (aux.Proximo != NULL)
		{
			//cout << endl << "hello";
			//candidato a próximo vertice do caminho
			candidato = distancias[vmp] + aux.Peso;
			if (candidato < distancias[aux.Vertice])
			{
				distancias[aux.Vertice] = candidato;
				caminho[aux.Vertice] = vmp;
				fila.Decrease_key(aux.Vertice, candidato);
			}
			aux = *aux.Proximo;
		}
		vmp = fila.Extract_min();
	}
}
*/

void Dijkstra(int origem)
{
	distancias[origem] = 0;
	heap_min_priority_queue fila;
	for (int i = 0; i < vertices; i++)
	{
		if (i != origem)
		{
			distancias[i] = infinito;
			caminho[i] = indefinido;
		}
		fila.Insert(distancias[i], i);
	}
	int candidato;
	//vertice mais proximo
	int vmp;

	vmp = fila.Extract_min();
	//cout << vmp << endl;
	//fila.ShowQueue();
	while (vmp >= 0)
	{
		//cout << fila.Minimum();
		//cout << endl << "vmp: " << vmp << endl;
		if (vmp == destino)
		{
			//return;
		}
		//cout << vmp << endl;
		//percorre todos os vertice para ver se forma aresta
		for (int i = 0; i < vertices; i++)
		{
			//se for vizinho de vmp
			if (adjacencias[vmp][i] >= 0)
			{
				//candidato a proximo vertice do caminho
				candidato = distancias[vmp] + adjacencias[vmp][i];
				if (candidato < distancias[i])
				{
					distancias[i] = candidato;
					caminho[i] = vmp;
					fila.Increase_Priority(i, candidato);
				}
			}
		}
		vmp = fila.Extract_min();
	}
}
void inicializaAdjacencias()
{
	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
		{
			if (i == j)
			{
				adjacencias[i][j] = 0;
				break;
			}
			adjacencias[i][j] = -1;
			adjacencias[j][i] = -1;	
		}
	}
}
int main2()
{
	int t;

	heap_min_priority_queue fila;

	fila.Insert(9999, 0);
	fila.Insert(0, 1);
	fila.Insert(9999, 2);
	fila.Insert(9999, 3);
	fila.Insert(9999, 4);
	fila.Insert(9999, 5);
	fila.Insert(9999, 6);
	fila.Insert(9999, 7);
	fila.Insert(9999, 8);
	fila.Insert(9999, 9);
	
	//extraiu o 1
	cout << fila.Extract_min() << endl;
	fila.Increase_Priority(0, 38);
	fila.Increase_Priority(2, 32);
	//extraiu o 2
	cout << fila.Extract_min() << endl;
	fila.Increase_Priority(0, 34);
	fila.Increase_Priority(3, 36);
	fila.Increase_Priority(6, 106);
	fila.Increase_Priority(8, 105);
	//extraiu o 0
	cout << fila.Extract_min() << endl;
	fila.Increase_Priority(7, 52);
	fila.Increase_Priority(8, 89);
	//extraiu o 3
	cout << fila.Extract_min() << endl;

	cin >> t;

	return 1;
}

int main()
{
	//int tt;
	int origem, peso, saida[50], contador_caminho = -1;
	int arestas;
	//No aux, *aux2;
	
	//inicializa as arestas do grafo
	
	//inicializaListaAdjacencias();

	//leitura dos números de vértices e de arestas
	cin >> vertices >> arestas;

	inicializaAdjacencias();

	//para cada aresta
	for (int i = 0; i < arestas; i++)
	{
		//leitura da origem, do destino e do peso da aresta
		cin >> origem >> destino >> peso;
		adjacencias[origem][destino] = peso;
		adjacencias[destino][origem] = peso;

	}

	//leitura da origem e do destino do menor caminho
	cin >> origem >> destino;
	

	//cout << "começou dijkstra";
	//executa o algoritmo de menor caminho
	Dijkstra(origem);
	//cout << "terminou dijkstra";

	/*
	for (int j = 0; j < vertices; j++)
	{
		cout << distancias[j] << ", ";
	}
	cout << endl << endl;
	for (int k = 0; k < vertices; k++)
	{
		cout << caminho[k] << ", ";
	}
	cout << endl;
	*/
	//cout << endl << "the end";
	//cin >> tt;

	//percorre o caminho inverso (destino para origem)
	//         /*-------------------------------------------------------
	while(destino != origem)
	{
		contador_caminho++;
		saida[contador_caminho] = destino;
		destino = caminho[destino];
	}
	//mostra o caminho (origem para destino)
	
	cout << origem << " ";
	for (int l = contador_caminho; l >= 0 ; l--)
	{
		cout << saida[l] << " ";
	}
	//       //--------------------------------------------------------*/

	//cout << endl << endl << endl << "finished";

	//para segurar o console
	//cin >> tt;
	
	return 0;
}
