#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define myPositiveInfinite 2147483647
#define myNegativeInfinite -2147483647
//#define MAXN 100
#define MAXN 1000000

typedef struct {
    char name[20];
    int priority;
} vaccine;

int Parent(int i){
    return i/2;
}

int Left(int i){
    return i*2;
} 

int Right(int i){
    return 2*i + 1;
}

//Ordena monton por monton hasta la raiz, es llamado por extract
void Minheapify(vaccine Q[], int i, int heapSize){
    int l, r, least;
    vaccine temp;

    l = Left(i);
    r = Right(i);
    if (l <= heapSize && Q[l].priority < Q[i].priority)
        least = l;
    else
        least = i;

    if (r <= heapSize && Q[r].priority < Q[least].priority)
        least = r;
    
    if (least != i)
    {
        temp = Q[i];
        Q[i] = Q[least];
        Q[least] = temp;

        Minheapify(Q, least, heapSize);
    }
}

//extraer la raiz, reorganiza el elemento
void MinPQ_Extract(vaccine Q[], int *heapSize){
    //char min[20];
    //min.priority = myNegativeInfinite;

    if (*heapSize < 1)
        printf("Error: Heap underflow.\n");
    else
    {
        //strcpy(min, Q[1].name);
        Q[1] = Q[*heapSize];
        *heapSize = *heapSize - 1;
        Minheapify(Q, 1, *heapSize);
    }
    //return min;
}

//Organizar el arbol
void MinPQ_DecreaseKey(vaccine Q[], int i, int key){
    vaccine temp;

    if (key > Q[i].priority)
        printf("New key is higher than current\n");
    else
    {
        Q[i].priority = key;
        while (i > 1 && Q[Parent(i)].priority > Q[i].priority) //i llega a la raiz, por lo cual termina el intercambio
        {
            temp = Q[i];
            Q[i] = Q[Parent(i)];
            Q[Parent(i)] = temp;
            i = Parent(i);
        }
        
    }

}

void MinPQ_Insert(vaccine Q[], vaccine key, int *heapSize){
    *heapSize = *heapSize + 1;
    Q[*heapSize].priority = myPositiveInfinite;
    MinPQ_DecreaseKey(Q, *heapSize, key.priority);
}

int main(){
    vaccine person, dates[MAXN + 1];
    char name[20];
    int heapSize = 0;

    while (scanf("%s", name) != EOF)
    {
        if (strcmp(name, "V") == 0)
        {
           if (heapSize == 0)
                printf("\n");
            else
            {
                printf("%s\n", dates[1].name);
                MinPQ_Extract(dates, &heapSize);
            }
           
        }
        else
        {
            strcpy(person.name, name);
            scanf("%d", &person.priority);
            person.priority = -1 * person.priority;

            MinPQ_Insert(dates, person, &heapSize);
        }
        
    }
    return 0;
}