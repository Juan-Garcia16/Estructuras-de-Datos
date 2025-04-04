#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define myPositiveInfinite 2147483647
#define myNegativeInfinite -2147483647
#define MAXN 100
//#define MAXN 1000000

int Parent(int i){
    return i/2;
}

int Left(int i){
    return i*2;
} 

int Right(int i){
    return 2*i + 1;
}

void Minheapify(int Q[], int i, int heapSize){
    int l, r, least, temp;

    l = Left(i);
    r = Right(i);
    if (l <= heapSize && Q[l] < Q[i])
        least = l;
    else
        least = i;

    if (r <= heapSize && Q[r] < Q[least])
        least = r;
    
    if (least != i)
    {
        temp = Q[i];
        Q[i] = Q[least];
        Q[least] = temp;

        Minheapify(Q, least, heapSize);
    }
}

void MinPQ_DecreaseKey(int Q[], int i, int key){
    int temp;

    if (key > Q[i])
        printf("New key is higher than current\n");
    else
    {
        Q[i] = key;
        while (i > 1 && Q[Parent(i)] > Q[i]) //i llega a la raiz, por lo cual termina el intercambio
        {
            temp = Q[i];
            Q[i] = Q[Parent(i)];
            Q[Parent(i)] = temp;
            i = Parent(i);
        }
        
    }

}

int MinPQ_Extract(int Q[], int *heapSize){
    int min = myNegativeInfinite;

    if (*heapSize < 1)
        printf("Error: Heap underflow.\n");
    else
    {
        min = Q[1];
        Q[1] = Q[*heapSize];
        *heapSize = *heapSize - 1;
        Minheapify(Q, 1, *heapSize);
    }

    return min;
}

void MinPQ_Insert(int Q[], int key, int *heapSize){
    *heapSize = *heapSize + 1;
    Q[*heapSize] = myPositiveInfinite;
    MinPQ_DecreaseKey(Q, *heapSize, key);
}

int main(){
    int dataSet[MAXN + 1], n, i, j, element, heapSize = 0, median, sum = 0;

    while (scanf("%d", &n) > 0)
    {
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &element);
            MinPQ_Insert(dataSet, element, &heapSize);
            median = (i - 1) / 2;
            
            if (median == 0)
            {
                sum += dataSet[1];
            }
            else
            {
                
                
            }
            
        }
        
    }
    

    return 0;
}
