#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXW 100
#define MAXH 100
#define NIL -1
#define BLACK 0
#define GRAY 1
#define WHITE 2
#define miInfinitive 2147483647

struct cell{
    int coord_x;
    int coord_y;

};

/*
//debido a que se va a enviar por referencia, el ancho debe ser asi
struct cell ReadMaze(char Maze[][MAXW + 1], int H, int W){
    int idRow, idColumn;
    char line[W + 1];// el + 1 es para el fin de cadena
    struct cell source;

    printf("Maze without juanman's position:\n");
    for(idRow = 1; idRow <= H; idRow++){
        //s porque no hay espacios en blanco
        scanf("%s", line);
        for(idColumn = 1; idColumn <= W; idColumn++)
        {
            Maze[idRow][idColumn] = line[idColumn];
            if(Maze[idRow][idColumn] == '@')
            {
                source.coord_x = idColumn;
                source.coord_y = idRow;
                Maze[idRow][idColumn] = '.';//porque se cuenta su propia celda
            }
        }
    }

    return source;
}

void printMaze(char Maze[][MAXW + 1], int H, int W){
    int idRow, idColumn;
    
    for(idRow = 1; idRow <= H; idRow++)
    {
        for(idColumn = 1; idColumn <= W; idColumn++)
            printf("%c", Maze[idRow][idColumn]);
        printf("\n");
    }
}

int main(){
    char Maze[MAXH + 1][MAXW + 1];
    int totalCases, idCase, H, W;
    struct cell source;
    
    scanf("%d", &totalCases);
    for(idCase = 1; idCase <= totalCases; idCase++)
    {
        scanf("%d %d", &W, &H);
        source = ReadMaze(Maze, H, W);
        printMaze(Maze, H, W);
    }

    return 0;
}*/
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
				Maze[idRow][idColumn] = '.'; //caracter punto para indicar que juanma puede caminar por ahí.
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

void BFS_Maze(char Maze[][MAXW + 1], int H, int W, struct cell source, int color[][MAXW + 1], int d[][MAXW + 1], struct cell pi[][MAXW + 1]){
    int idRow, idColumn, idHead = 1, idTail = 1;
    struct cell NILFather, Q[H * W + 1], U;
    NILFather.coord_x = NIL;
    NILFather.coord_y = NIL;

    for(idRow = 1; idRow <= H; idRow++)
    {
        for(idColumn = 1; idColumn <= W; idColumn++)
        {
            color[idRow][idColumn] = WHITE;
            d[idRow][idColumn] = miInfinitive;
            pi[idRow][idColumn] = NILFather;
        }
    }

    color[source.coord_y][source.coord_x] = GRAY;
    d[source.coord_y][source.coord_x] = 0;
    pi[source.coord_y][source.coord_x] = NILFather;
    Q[idTail] = source;
    idTail++;

    while(idHead < idTail)
    {
        U = Q[idHead];
        idHead++;
    }
}


int solver(char Maze[][MAXW + 1], int H, int W, struct cell source){
    int color[MAXH + 1][MAXW + 1];
    int d[MAXH + 1][MAXW + 1];
    struct cell pi[MAXH + 1][MAXW + 1];// para ubicar la cordenada de los padres

    BFS_Maze(Maze, H, W, source, color, d, pi);
}

int main(){
	
	char Maze[MAXH + 1][MAXW + 1];
	int totalCases, idCase, H, W;
	struct cell source;
	
	scanf("%d", &totalCases);
	
	for(idCase = 1; idCase <= totalCases; idCase++){
		
		scanf("%d %d", &W, &H);
		source = ReadMaze(Maze, H, W);
        printf("%d\n", solver(Maze, H, W, source));
		PrintMaze (Maze, H, W);
	}
	
	return 0;
}