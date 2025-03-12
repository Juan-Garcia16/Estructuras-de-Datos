#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define myPositiveInfinite 2147483647
#define myNegativeInfinite -2147483647
#define MAXN 1000000

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

int MinPQ_Minimum(int Q[]){
    return Q[1];
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

void MinPQ_DecreaseKey(int Q[], int i, int key){
    int temp;

    if (key > Q[i])
        printf("New key is higher than current\n");
    else
    {
        Q[i] = key;
        while (i > 1 && Q[Parent(i)] > Q[i])
        {
            temp = Q[i];
            Q[i] = Q[Parent(i)];
            Q[Parent(i)] = temp;
            i = Parent(i);
        }
        
    }

}

void MinPQ_Insert(int Q[], int key, int *heapSize){
    *heapSize = *heapSize + 1;
    Q[*heapSize] = myPositiveInfinite;
    MinPQ_DecreaseKey(Q, *heapSize, key);

}

int main(){
    int QA[MAXN + 1], QB[MAXN + 1], m, n, element, idElement;
    int heapSizeA = 0, heapSizeB = 0, intersection = 0;

    scanf("%d %d", &m, &n);

    for (idElement = 1; idElement <= m; idElement++)
    {
       scanf("%d", &element);
       MinPQ_Insert(QA, element, &heapSizeA);
    }
    
    for (idElement = 1; idElement <= n; idElement++)
    {
       scanf("%d", &element);
       MinPQ_Insert(QB, element, &heapSizeB);
    }

    while ((heapSizeA > 0) && (heapSizeB > 0))
    {
        //intersection
        if (MinPQ_Minimum(QA) == MinPQ_Minimum(QB))
        {
            intersection++;
            MinPQ_Extract(QA, &heapSizeA);
            MinPQ_Extract(QB, &heapSizeB);
        }
        else
        {
            if (MinPQ_Minimum(QA) < MinPQ_Minimum(QB))
                MinPQ_Extract(QA, &heapSizeA);
            else
                MinPQ_Extract(QB, &heapSizeB);    
        }
        
    }

    printf("%d %d %d %d\n", m - intersection, intersection, n - intersection, m + n - intersection);

    return 0;
}