#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXV 1000

struct edge
{
    int vertex;
/*  int weight;  */
    struct edge *next;
};


struct graph
{
    int n_vertex; //cuanto vertuces tuebe
    int m_edges; //cuantas arista tiene
    struct edge *Adj[MAXV + 1]; //arreglo punteros de lista de adyascencia
};

//Devuelve un puntero, recibe numero de vertices y total de aristas
struct graph *ReadGraph(int vertices, int edges)
{
    int idVertex, idEdge, u, v; //vertice u, vertice v
    struct graph *G;
    struct edge *tempEdge; //arista temporal para moverse recorriendo la lista de adyascencua

    G = (struct graph *) malloc(sizeof(struct graph));
    G->n_vertex = vertices; //total vertices
    G->m_edges = edges; //total aristas

    for(idVertex = 1; idVertex <= G->n_vertex; idVertex++)
        G->Adj[idVertex] = NULL; 

    for(idEdge = 1; idEdge <= G->m_edges; idEdge++)
    {
        scanf("%d %d", &u, &v); //de donde sale (u) a donde llega (v)
        tempEdge = (struct edge *) malloc(sizeof(struct edge));
        tempEdge->vertex = v; // a donde esta llegando
        tempEdge->next = G->Adj[u]; //siemrpe todo se va metiendo en la cabeza de la lista
        G->Adj[u] = tempEdge; //actualizar la cabeza de la lista

        if(u != v) //si son diferentes, se inserta la lista que va de v a u
        {
            tempEdge = (struct edge *) malloc(sizeof(struct edge));
            tempEdge->vertex = u;
            tempEdge->next = G->Adj[v];
            G->Adj[v] = tempEdge; //lista de adyascencia vertice v
        }
    }
    return G; //puntero al padre
}


void PrintGraph(struct graph *G)
{
    int idVertex;
    struct edge *tempEdge;

    if(G != NULL)
    {
        printf("Representation for graph's adjacent lists: \n");
        for(idVertex = 1; idVertex <= G->n_vertex; idVertex++)
        {
            printf("[%d]: ", idVertex);
            tempEdge = G->Adj[idVertex];
            while(tempEdge != NULL)
            {
                printf(" -> %d", tempEdge->vertex);
                tempEdge = tempEdge->next;
            }
            printf(" -> NULL\n");
        }
    }
    else
        printf("Empty Graph.\n");
}


struct graph *DeleteGraph(struct graph *G)
{
    int idVertex;
    struct edge *ActualEdge, *NextEdge;

    for(idVertex = 1; idVertex <= G->n_vertex; idVertex++)
    {
        ActualEdge = G->Adj[idVertex]; //cabeza de la lsita
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

int main()
{
    int vertices, edges;
    struct graph *G;

    while(scanf("%d %d", &vertices, &edges) != EOF)
    {
        G = ReadGraph(vertices, edges);
        PrintGraph(G);
        G = DeleteGraph(G);
        PrintGraph(G);    
    }
    return 0;
}

/*
6 8
6 5
6 4
6 2
5 3
5 1
4 1
3 2
2 1
*/