#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define myPositiveInfinite 2147483647
#define myNegativeInfinite -2147483647
#define MAXN 100

int Parent(int i){
    return i/2;
}

int Left(int i){
    return i*2;
} 

int Right(int i){
    return 2*i + 1;
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
    int n, data[MAXN + 1], element, position, totalData, median, heapsize = 0;
    double mean = 0, resutl;

    while (scanf("%d", &n) && n != 0)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &element);
            MinPQ_Insert(data, element, &heapsize);   
            position = (i - 1) / 2;
            median = data[position + 1];
            mean += median;         
        }

        resutl = mean/ n;
        printf("%.2lf\n", resutl);
        printf("%lf\n", mean);
    }
    return 0;
}

