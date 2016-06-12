#include<iostream>
#include<math.h>

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

	void ShowQueue();
};
heap_min_priority_queue::heap_min_priority_queue()
{
	heap_size = 0;
	infinite = 9999;
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



int distancias[50];
int caminho[50];
int vertices;
int infinito = 9999;
int indefinido = -1;
int adjacencias[50][50];

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
	//vértice mais próximo
	int vmp = fila.Extract_min();
	while (vmp > 0)
	{
		//percorre todos os vértice para ver se forma aresta
		for (int i = 1; i <= vertices; i++)
		{
			//se for vizinho de vmp
			if (adjacencias[vmp][i] > 0)
			{
				//candidato a próximo vertice do caminho
				candidato  = distancias[vmp] + adjacencias[vmp][i];
				if (candidato < distancias[i])
				{
					distancias[i] = candidato;
					caminho[i] = vmp;
					fila.Decrease_key(i, candidato);
				}
			}
		}
	}
}
void inicializaAdjacencias()
{
	for (int i = 1; i <= vertices; i++)
	{
		for (int j = 1; j <= vertices; j++)
		{
			if (i == j)
			{
				adjacencias[i][j] = 0;
				break;
			}
			adjacencias[i][j] = -1;
		}
	}
}

int main()
{
	int tt;
	int origem, destino, peso, saida[50], contador_caminho = -1;
	int arestas;
	
	//inicializa as arestas do grafo
	inicializaAdjacencias();

	//leitura dos números de vértices e de arestas
	cin >> vertices >> arestas;

	//para cada aresta
	for (int i = 0; i < arestas; i++)
	{
		//leitura da origem, do destino e do peso da aresta
		cin >> origem >> destino >> peso;
		adjacencias[origem][destino] = peso;
	}

	//leitura da origem e do destino do menor caminho
	cin >> origem >> destino;
	
	//executa o algoritmo de menor caminho
	Dijkstra(origem);
	
	//percorre o caminho inverso (destino para origem)
	while(distancias[destino] > 0)
	{
		contador_caminho++;
		saida[contador_caminho] = destino;
		destino = caminho[destino];
	}
	
	//mostra o caminho (origem para destino)
	for (int i = 0; i <= contador_caminho; i++)
	{
		cout << saida[i] << " ";
	}
	
	//para segurar o console
	cin >> tt;
	
	return 0;
}