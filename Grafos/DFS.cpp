#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXV 1000
#define BLACK 0
#define GRAY 1
#define WHITE 2
#define NIL -1

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

void DFS_Visit(struct graph *G, int u, int *time, int color[], int pi[], int d[], int f[])
{
    struct edge *tempEdge; //para recorrer la lista de adyasencia
    int v;

    color[u] = GRAY;
    *time = *time + 1;
    d[u] = *time;
    tempEdge = G->Adj[u];

    while (tempEdge != NULL)
    {
        v = tempEdge->vertex;
        if (color[v] == WHITE)
        {
            pi[v] = u;
            DFS_Visit(G, v, &(*time), color, pi, d, f);
        }
        tempEdge = tempEdge->next;
    }
    color[u] = BLACK;
    *time = *time + 1;
    f[u] = *time;
    
}

void DFS(struct graph *G, int color[], int pi[], int d[], int f[])
{
    int u, time = 0;

    for (u = 1; u <= G->n_vertex; u++)
    {
        color[u] = WHITE;
        pi[u] = NIL;
    }
    
    for (u = 1; u <= G->n_vertex; u++)
    {
        if (color[u] == WHITE)
            DFS_Visit(G, u, &time, color, pi, d, f);    
    }
}

void solver(struct graph *G)
{
    //color, padres, descubiertos, finalizados
    int color[MAXV + 1], pi[MAXV + 1], d[MAXV + 1], f[MAXV + 1], u;

    DFS(G, color, pi, d, f);

    //colores
    printf("\n");
    for (u = 1; u <= G->n_vertex; u++)
    {
        if (color[u] == BLACK)
            printf("color[%d]: BLACK\n", u);
        if (color[u] == GRAY)
            printf("color[%d]: GRAY\n", u);
        if (color[u] == WHITE)
            printf("color[%d]: WHITE\n", u);
    }
    //padres
    printf("\n");
    for (u = 1; u <= G->n_vertex; u++)
    {
        if (pi[u] == NIL)
            printf("pi[%d]: NIL\n", u);
        else
            printf("pi[%d]: %d\n", u, pi[u]);
    }
    //descubiertos y finalizados
    printf("\n");
    for (u = 1; u <= G->n_vertex; u++)
        printf("(d[%d], f[%d]): (%d, %d)\n", u, u, d[u], f[u]);
}

int main()
{
    int vertices, edges;
    struct graph *G;

    while(scanf("%d %d", &vertices, &edges) != EOF)
    {
        G = ReadGraph(vertices, edges);
        PrintGraph(G);
        solver(G);
        G = DeleteGraph(G);
        PrintGraph(G);    
    }
    return 0;
}

/*
7 9
7 6
6 3
5 4
5 3
5 2
5 1
4 1
3 2
2 1
*/
