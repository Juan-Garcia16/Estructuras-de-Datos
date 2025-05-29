#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXW 1000
#define MAXH 1000
#define NIL -1
#define BLACK 0
#define GRAY 1
#define WHITE 2
#define myInfinite 2147483647

struct cell{
    int coord_x;
    int coord_y;
};

struct cell ReadMaze(char Maze[][MAXW + 1], int H, int W){ //Al enviarlo por referencia debo indicar el ancho de la matriz.

    int idRow, idColumn;
    char line[W + 1]; //Para caracter de salto de linea es el + 1.
    struct cell source;
    
    for(idRow = 1; idRow <= H; idRow++){
        
        scanf("%s", line); //El nombre del arreglo de caracteres funciona como direccion de memoria.
        for(idColumn = 1; idColumn <= W; idColumn++){
            
            Maze[idRow][idColumn] = line[idColumn - 1];
            if(Maze[idRow][idColumn] == '@'){
                
                source.coord_x = idColumn;
                source.coord_y = idRow;
                Maze[idRow][idColumn] = '.'; //caracter punto para indicar que juanma puede caminar por ahi.
            }
        }
    }
    
    return source;
}

void PrintMaze(char Maze[][MAXW + 1], int H, int W){
    
    int idRow, idColumn;
    
    printf("Maze without juanman's position:\n");
    
    for(idRow = 1; idRow <= H; idRow++){
        
        for(idColumn = 1; idColumn <= W; idColumn++)
            printf("%c", Maze[idRow][idColumn]);
        printf("\n");
    }
}

void assignMovements(struct cell arrayMov[]){
    
    arrayMov[0].coord_x = 0;//neutra
    arrayMov[0].coord_y = 0;
    
    arrayMov[1].coord_x = 0;//arriba 
    arrayMov[1].coord_y = -1;
    
    arrayMov[2].coord_x = 0;//abajo
    arrayMov[2].coord_y = 1;

    arrayMov[3].coord_x = -1;//izquierda
    arrayMov[3].coord_y = 0;
    
    arrayMov[4].coord_x = 1;//derecha
    arrayMov[4].coord_y = 0;
    
}
/*
void BFS_Maze(char Maze[][MAXW + 1], int H, int W, struct cell source, int color[][MAXW + 1], int d[][MAXW + 1], struct cell pi[][MAXW + 1]){
    
    int idRow, idColumn, idHead = 1, idTail = 1, idAdj;
    struct cell NILFather, Q[H * W + 1], U, V, arrayMov[5];
    NILFather.coord_x = NIL;
    NILFather.coord_y = NIL;
    
    assignMovements(arrayMov);
    
    for(idRow = 1; idRow <= H; idRow++){
        
        for(idColumn = 1; idColumn <= W; idColumn++){
            
            color[idRow][idColumn] = WHITE;
            d[idRow][idColumn] = myInfinite;
            pi[idRow][idColumn] = NILFather;
        }
    }
    
    color[source.coord_y][source.coord_x] = GRAY;
    d[source.coord_y][source.coord_x] = 0;
    pi[source.coord_y][source.coord_x] = NILFather;
    Q[idTail] = source;
    idTail++;
    
    while(idHead < idTail){
        
         U = Q[idHead];
         idHead++;
         for(idAdj = 1; idAdj <= 4; idAdj++){
             V.coord_x = U.coord_x + arrayMov[idAdj].coord_x;
             V.coord_y = U.coord_y + arrayMov[idAdj].coord_y;
             if ((V.coord_x >= 1) && (V.coord_x <= W) && 
                (V.coord_y >= 1) && (V.coord_y <= H) &&
                (color[V.coord_y][V.coord_x] == WHITE) &&
                (Maze[V.coord_y][V.coord_x] == '.'))
            {
                color[V.coord_y][V.coord_x] = GRAY;
                d[V.coord_y][V.coord_x] = d[U.coord_y][U.coord_x] + 1;
                pi[V.coord_y][V.coord_x] = U;
                Q[idTail] = V;
                idTail++;    
            }
         }
         color[U.coord_y][U.coord_x] = BLACK;
    }
    
}*/

void DFS_Visit_Maze(char Maze[][MAXW + 1], 
            int H, int W, struct cell U, int *time,
            int color[][MAXW + 1], 
            int d[][MAXW + 1], 
            int f[][MAXW + 1], 
            struct cell pi[][MAXW + 1],
            struct cell arrayMov[])
{
    int idRow, idColumn, idAdj;
    struct cell V; 

    color[U.coord_y][U.coord_x] = GRAY;
    *time = *time + 1;
    d[U.coord_y][U.coord_x] = *time;
    
    for(idAdj = 1; idAdj <= 4; idAdj++){
        V.coord_x = U.coord_x + arrayMov[idAdj].coord_x;
        V.coord_y = U.coord_y + arrayMov[idAdj].coord_y;
        if ((V.coord_x >= 1) && (V.coord_x <= W) && 
            (V.coord_y >= 1) && (V.coord_y <= H) &&
            (color[V.coord_y][V.coord_x] == WHITE) &&
            (Maze[V.coord_y][V.coord_x] == '.'))
        {
            pi[V.coord_y][V.coord_x] = U;  
            DFS_Visit_Maze(Maze, H, W, U, &(*time), color, d, f, pi, arrayMov);
        }
    }
    color[U.coord_y][U.coord_x] = BLACK;
    *time = *time + 1;
    f[U.coord_y][U.coord_x] = *time;
}

void DFS_Maze(char Maze[][MAXW + 1], 
            int H, int W, struct cell source,
            int color[][MAXW + 1], 
            int d[][MAXW + 1], 
            int f[][MAXW + 1], 
            struct cell pi[][MAXW + 1])
{
    
    int idRow, idColumn, idAdj, time = 0;
    struct cell NILFather, U, arrayMov[5];
    NILFather.coord_x = NIL;
    NILFather.coord_y = NIL;
    
    
    for(idRow = 1; idRow <= H; idRow++)
    {   
        for(idColumn = 1; idColumn <= W; idColumn++)
        {
            color[idRow][idColumn] = WHITE;
            pi[idRow][idColumn] = NILFather;
        }
    }

    DFS_Visit_Maze(Maze, H, W, source, &time, color, d, f, pi, arrayMov);

    /*
    for(idRow = 1; idRow <= H; idRow++)
    {   
        for(idColumn = 1; idColumn <= W; idColumn++)
        {
            U.coord_x = idColumn;
            U.coord_y = idRow;
            if((Maze[U.coord_y][U.coord_x] == '.') && 
                (color[U.coord_y][U.coord_x] == WHITE))// verificar si es caminable
            {
                DFS_Visit_Maze(Maze, H, W, U, &time, color, d, f, pi, arrayMov);
            }
        }
    }*/
}

int solver(char Maze[][MAXW + 1], int H, int W, struct cell source){
    
    int color[MAXH + 1][MAXW + 1], idRow, idColumn;
    int d[MAXH + 1][MAXW + 1], result = 0;
    int f[MAXH + 1][MAXW + 1];
    struct cell pi[MAXH + 1][MAXW + 1];
    
    DFS_Maze(Maze, H, W, source, color, d, f, pi);
    result = (f[source.coord_y][source.coord_x] + 1 - d[source.coord_y][source.coord_x]) / 2;
    return result;
}




int main(){
    
    char Maze[MAXH + 1][MAXW + 1];
    int totalCases, idCase, H, W;
    struct cell source;
    
    scanf("%d", &totalCases);
    
    for(idCase = 1; idCase <= totalCases; idCase++){
        
        scanf("%d %d", &W, &H);
        source = ReadMaze(Maze, H, W);
        printf("Case %d: %d\n", idCase, solver(Maze, H, W, source));
    }
    
    return 0;
}