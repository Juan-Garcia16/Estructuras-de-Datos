#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXV 1000
#define NIL -1
#define BLACK 0
#define GRAY 1
#define WHITE 2
#define myInfinite -2147483647

struct edge
{
    int vertex;
/*  int weight;  */
    struct edge *next;
};


struct graph
{
    int n_vertex;
    int m_edges;
    struct edge *Adj[MAXV + 1];
};


struct graph *ReadGraph(int vertices, int edges)
{
    int idVertex, idEdge, u, v;
    struct graph *G;
    struct edge *tempEdge;

    G = (struct graph *) malloc(sizeof(struct graph));
    G->n_vertex = vertices;
    G->m_edges = edges;

    for(idVertex = 1; idVertex <= G->n_vertex; idVertex++)
        G->Adj[idVertex] = NULL;

    for(idEdge = 1; idEdge <= G->m_edges; idEdge++)
    {
        scanf("%d %d", &u, &v);
        tempEdge = (struct edge *) malloc(sizeof(struct edge));
        tempEdge->vertex = v;
        tempEdge->next = G->Adj[u];
        G->Adj[u] = tempEdge;

        if(u != v)
        {
            tempEdge = (struct edge *) malloc(sizeof(struct edge));
            tempEdge->vertex = u;
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

void BFS(struct graph *G, int source, int colors[], int d[], int pi[])
{
    //simular cola por medio de un arreglo, es mas rapida que con listas
    int u, v, Q[MAXV + 1], idTail, idHead;
    struct edge *tempEdge;

    for(u = 1; u <= G->n_vertex; u++)
    {
        colors[u] = WHITE;
        d[u] = myInfinite;
        pi[u] = NIL;
    }

    colors[source] = GRAY;
    d[source] = 0;
    pi[source] = NIL;
    //La cola esta vacia si head y tail estan en la misma casilla
    idHead = 1;
    idTail = 1;
    Q[idTail] = source;
    idTail++;
    //simulacion de la cola
    while (idHead < idTail)
    {
        u = Q[idHead];
        idHead++;
        tempEdge = G->Adj[u];
        while (tempEdge != NULL)
        {
            v = tempEdge->vertex;
            if (colors[v] == WHITE)
            {
                colors[v] = GRAY;
                d[v] = d[u] + 1;
                pi[v] = u;
                Q[idTail] = v; //encolar
                idTail++;
            }
            tempEdge = tempEdge->next;
        }
        colors[u] = BLACK;
    }
    
}

void path(int current, int source, int pi[])
{
    if (current == source)
        printf("%d", source);
    else
    {
        path(pi[current], source, pi);
        printf(" -> %d", current);
    }
    
}

void solver(struct graph *G, int source) 
{
    int colors[MAXV + 1], d[MAXV + 1], pi[MAXV + 1];
    int idVertex, farthestVertex = NIL, maxDistance = -1;

    BFS(G, source, colors, d, pi);
    
    printf("\n");
    //colores
    for (idVertex = 1; idVertex <= G->n_vertex; idVertex++)
    {
        if (colors[idVertex] == BLACK)
            printf("color[%d] = BLACK\n", idVertex);
        if (colors[idVertex] == GRAY)
            printf("color[%d] = GRAY\n", idVertex);
        if (colors[idVertex] == WHITE)
            printf("color[%d] = WHITE\n", idVertex);
    }

    printf("\n");
    //distancias
    for (idVertex = 1; idVertex <= G->n_vertex; idVertex++)
    {
        if (maxDistance < d[idVertex])
        {
            maxDistance = d[idVertex];
            farthestVertex = idVertex;
        }

        if (d[idVertex] == myInfinite)
            printf("d[%d] = infinite\n", idVertex);
        else
            printf("d[%d] = %d\n", idVertex, d[idVertex]);
    }

    printf("\n");
    //padres
    for (idVertex = 1; idVertex <= G->n_vertex; idVertex++)
    {
        if (pi[idVertex] == NIL)
            printf("pi[%d] = NIL\n", idVertex);
        else
            printf("pi[%d] = %d\n", idVertex, pi[idVertex]);
    }
    printf("\n");
    printf("Farthest vertex: %d, distance: %d\n", farthestVertex, maxDistance);
    path(farthestVertex, source, pi);
    printf("\n");

}

int main()
{
    int vertices, edges;
    struct graph *G;

    while(scanf("%d %d", &vertices, &edges) != EOF)
    {
        G = ReadGraph(vertices, edges);
        PrintGraph(G);
        solver(G, 5); //ejemplo del cuaderno en clase
        G = DeleteGraph(G);
        PrintGraph(G);
    }
    return 0;
}

/*
de los mas grandes a los mas grandes
vertices y aristas
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
