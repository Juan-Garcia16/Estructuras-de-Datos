#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXV 10000
#define myInfinite 2147483647
#define NIL -1
#define TRUE 1
#define FALSE 0

struct edge
{
    int vertex;
    int weight;
    struct edge *next;
};

struct graph
{
    int n_vertex;
    int m_edges;
    struct edge *Adj[MAXV + 1];
};

struct nodePQ
{
	int vertex;
	int distance;
};


int Parent(int i)
{
	return i >> 1; /* return i / 2; */
}


int Left(int i)
{
	return i << 1; /* return 2 * i; */
}


int Right(int i)
{
	return (i << 1) + 1; /* return 2 * i + 1; */
}


void MinHeapify(struct nodePQ Q[], int i, int heapSize, int positionVertex[])
{
	int l, r, least, tempPosition;
	struct nodePQ tempNode;
	l = Left(i);
	r = Right(i);

	if((l <= heapSize) && (Q[l].distance < Q[i].distance))
		least = l;
	else
		least = i;

	if((r <= heapSize) && (Q[r].distance < Q[least].distance))
		least = r;

	if(least != i)
	{
		tempPosition = positionVertex[Q[i].vertex];
		tempNode = Q[i];

		positionVertex[Q[i].vertex] = positionVertex[Q[least].vertex];
		Q[i] = Q[least];

		positionVertex[Q[least].vertex] = tempPosition;
		Q[least] = tempNode;

		MinHeapify(Q, least, heapSize, positionVertex);
	}
}


int MinPQ_Extract(struct nodePQ Q[], int *heapSize, int positionVertex[])
{
	int myMin = 0;

	if(*heapSize >= 1)
	{
		myMin = Q[1].vertex;

		positionVertex[Q[*heapSize].vertex] = 1;
		Q[1] = Q[*heapSize];

		*heapSize = *heapSize - 1;
		MinHeapify(Q, 1, *heapSize, positionVertex);
	}
	return myMin;
}


void MinPQ_DecreaseKey(struct nodePQ Q[], int i, int key, int positionVertex[])
{
	int tempPosition;
	struct nodePQ tempNode;

	if(key < Q[i].distance)
	{
		Q[i].distance = key;

		while((i > 1) && (Q[Parent(i)].distance > Q[i].distance))
		{
			tempPosition = positionVertex[Q[i].vertex];
			tempNode = Q[i];

			positionVertex[Q[i].vertex] = positionVertex[Q[Parent(i)].vertex];
			Q[i] = Q[Parent(i)];

			positionVertex[Q[Parent(i)].vertex] = tempPosition;
			Q[Parent(i)] = tempNode;

			i = Parent(i);
		}
	}
}


void MinPQ_Insert(struct nodePQ Q[], int key, int vertex, int *heapSize, int positionVertex[])
{
	*heapSize = *heapSize + 1;
	Q[*heapSize].distance = myInfinite;
	Q[*heapSize].vertex = vertex;
	positionVertex[vertex] = *heapSize;
	MinPQ_DecreaseKey(Q, *heapSize, key, positionVertex);
}


struct graph *ReadGraph(int vertices, int edges)
{
    int idVertex, idEdge, u, v, w;
    struct graph *G;
    struct edge *tempEdge;

    G = (struct graph *) malloc(sizeof(struct graph));
    G->n_vertex = vertices;
    G->m_edges = edges;

    for(idVertex = 1; idVertex <= G->n_vertex; idVertex++)
        G->Adj[idVertex] = NULL;

    for(idEdge = 1; idEdge <= G->m_edges; idEdge++)
    {
        scanf("%d %d %d", &u, &v, &w);
/*
        u++;
        v++;
*/
        tempEdge = (struct edge *) malloc(sizeof(struct edge));
        tempEdge->vertex = v;
        tempEdge->weight = w;
        tempEdge->next = G->Adj[u];
        G->Adj[u] = tempEdge;

        if(u != v)
        {
            tempEdge = (struct edge *) malloc(sizeof(struct edge));
            tempEdge->vertex = u;
            tempEdge->weight = w;
            tempEdge->next = G->Adj[v];
            G->Adj[v] = tempEdge;
        }
    }
    return G;
}


void PrintGraph(struct graph *G)
{
    int idVertex;
    struct edge *tempEdge;

    if(G != NULL)
    {
        printf("\n Representation for graph's adjacent lists: \n\n");
        for(idVertex = 1; idVertex <= G->n_vertex; idVertex++)
        {
            printf("[%d]: ", idVertex);
            tempEdge = G->Adj[idVertex];
            while(tempEdge != NULL)
            {
                printf(" -> (%d, %d)", tempEdge->vertex, tempEdge->weight);
                tempEdge = tempEdge->next;
            }
            printf(" -> NULL\n");
        }
    }
    else
        printf("\n Empty Graph.\n");
}


struct graph *DeleteGraph(struct graph *G)
{
    int idVertex;
    struct edge *ActualEdge, *NextEdge;

    for(idVertex = 1; idVertex <= G->n_vertex; idVertex++)
    {
        ActualEdge = G->Adj[idVertex];
        while(ActualEdge != NULL)
        {
            NextEdge = ActualEdge->next;
            free(ActualEdge);
            ActualEdge = NextEdge;
        }
    }
    free(G);
    G = NULL;
    return G;
}


void Prim(struct graph *G, int d[], int pi[], int s)
{
	int u, v, w, heapSize = 0;
	struct nodePQ Q[MAXV + 1];
	int positionVertex[MAXV + 1], inQueue[MAXV + 1];
	struct edge *tempEdge;

	for(u = 1; u <= G->n_vertex; u++)
	{
		pi[u] = NIL;
		inQueue[u] = TRUE;

		if(u == s)
		{
			MinPQ_Insert(Q, 0, s, &heapSize, positionVertex);
			d[s] = 0;
		}
		else
		{
			MinPQ_Insert(Q, myInfinite, u, &heapSize, positionVertex);
			d[u] = myInfinite;
		}
	}

	while(heapSize >= 1)
	{
		u = MinPQ_Extract(Q, &heapSize, positionVertex);
		inQueue[u] = FALSE;

		if(d[u] == myInfinite)
			break;

		tempEdge = G->Adj[u];
		while(tempEdge != NULL)
		{
			v = tempEdge->vertex;
			w = tempEdge->weight;

			if((inQueue[v] == TRUE) && (d[v] > w)) //para dijkstra
			{
				d[v] = w; //para dijkstra
				pi[v] = u;
				MinPQ_DecreaseKey(Q, positionVertex[v], d[v], positionVertex);
			}
			tempEdge = tempEdge->next;
		}
	}
}


void solver(struct graph *G, int source)
{
    int d[MAXV + 1], pi[MAXV + 1], idVertex, weightMST = 0;
    Prim(G, d, pi, source);

    printf("\n");
    for(idVertex = 1; idVertex <= G->n_vertex; idVertex++)
    {
        printf("d[%d]: %d\n", idVertex, d[idVertex]);
        weightMST += d[idVertex];
    }
    printf("\n");

    for(idVertex = 1; idVertex <= G->n_vertex; idVertex++)
    {
        if(pi[idVertex] == NIL)
            printf("pi[%d]: NIL\n", idVertex);
        else
            printf("pi[%d]: %d\n", idVertex, pi[idVertex]);
    }
    printf("\n");

    printf("Total weight of the minimum spanning tree: %d\n", weightMST);
}


int main()
{
    int vertices, edges, source = 9;
    struct graph *G;

    while(scanf("%d %d", &vertices, &edges) != EOF)
    {
        G = ReadGraph(vertices, edges);
        PrintGraph(G);
        solver(G, source);
        G = DeleteGraph(G);
        PrintGraph(G);
    }
    return 0;
}

/*
9 14
9 8 7
9 7 6
9 3 2
8 7 1
8 2 11
8 1 8
7 6 2
6 5 10
6 4 14
6 3 4
5 4 9
4 3 7
3 2 8
2 1 4
*/
