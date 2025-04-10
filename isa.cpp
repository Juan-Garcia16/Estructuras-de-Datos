#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define myPositiveInfinite 2147483647   
#define myNegativeInfinite -2147483647 
#define MAXN 100

struct medicamento{
    char name[16];
    int frecuencia;
    int prioridad;
    int tiempo;
};

// Funciones auxiliares
int Parent(int i) {
    
    return i / 2;
}

int Left(int i) {
    
    return 2 * i;
}

int Right(int i) {
    
    return 2 * i + 1;
}

// Funcion MinHeapify para restaurar la propiedad de min-heap
void MinHeapify(medicamento Q[], int i, int heapSize) {
    
    int l, r, least = i; //inicializacion Pablo.
    medicamento temp; 
     
    l = Left(i);
    r = Right(i);

    if ((l <= heapSize) && ((Q[l].tiempo < Q[least].tiempo) ||
		((Q[l].tiempo == Q[least].tiempo) && (Q[l].prioridad < Q[least].prioridad ))))
        least = l;
    else 
        least = i;
        
    if((r <= heapSize) && ((Q[r].tiempo < Q[least].tiempo) ||
		((Q[r].tiempo == Q[least].tiempo) && (Q[r].prioridad < Q[least].prioridad))))       
        least = r;
        
    if(least != i){
        
        temp = Q[i];
        Q[i] = Q[least];
        Q[least] = temp;
        MinHeapify(Q, least, heapSize);
    }
}

// Funcion para obtener el elemento minimo
int MinPQ_Minimum(int Q[]) {
    
    return Q[1];
}

// Funcion para extraer el minimo
medicamento MinPQ_Extract(medicamento Q[], int *heapSize) {
    
    medicamento min;
    min.tiempo = myNegativeInfinite;
    
    if(*heapSize < 1)
        printf("Heap underflow.\n");
        
    else{
        min = Q[1];
        Q[1] = Q[*heapSize];
        *heapSize = *heapSize - 1;
        MinHeapify(Q, 1, *heapSize);
    }
    
    return min;    
}

// Funcion para disminuir la clave de un nodo
void MinPQ_DecreaseKey(medicamento Q[], int i, medicamento key) {
    
    medicamento temp;
    
    if(key.tiempo > Q[i].tiempo)
        printf("New key is higher than current key.\n");
        
    else{
        Q[i] = key;
        while((i > 1) && ((Q[Parent(i)].tiempo > Q[i].tiempo) ||
			 ((Q[Parent(i)].tiempo == Q[i].tiempo) && Q[Parent(i)].prioridad > Q[i].prioridad))){ 
            
            temp = Q[i];
            Q[i] = Q[Parent(i)];
            Q[Parent(i)] = temp;
            i = Parent(i);
        }
    }    
}

// Funcion para insertar un nuevo elemento
void MinPQ_Insert(medicamento Q[], medicamento key, int *heapSize) {
    
    *heapSize = *heapSize + 1;
    Q[*heapSize].tiempo = myPositiveInfinite;
    MinPQ_DecreaseKey(Q, *heapSize, key);
    
}

int main(){
    int t, index, n, k, heapSize = 0;
    medicamento ListaDatos[MAXN + 1], dato, minimo;
    
    scanf("%d", &t);
    for(index = 1; index <= t; index++){
        scanf("%d %d", &n, &k);
        





        for(index = 1; index <= n; index++){
            scanf("%s %d", dato.name, &dato.frecuencia);
            dato.prioridad = index;
            dato.tiempo = dato.frecuencia;
            
            //Insertar en la cola el medicamento.
            MinPQ_Insert(ListaDatos, dato, &heapSize);
        }
        for(index = 1; index <= k; index++){
            minimo = MinPQ_Extract(ListaDatos, &heapSize);
            printf("%d %s\n", minimo.tiempo, minimo.name);
            strcpy(dato.name, minimo.name);
            dato.tiempo += dato.frecuencia;
            MinPQ_Insert(ListaDatos, dato, &heapSize);
        }

    }
    
    return 0;
}