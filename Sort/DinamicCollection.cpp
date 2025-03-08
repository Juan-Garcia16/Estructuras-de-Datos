#include <stdio.h>
#include <stdlib.h>
#define myInfinite 2147483647 
#define MAXN 500000 

void myMerge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1, n2 = r - q, i, j, k;
    int L[n1 + 1], R[n2 + 1];

    for(i = 1; i <= n1; i++)
        L[i] = A[p + i - 1];
    
    for(j = 1; j <= n2; j++)
        R[j] = A[q + j];

    L[n1 + 1] = myInfinite;
    R[n2 + 1] = myInfinite; 
    i = 1;
    j = 1;

    for(k = p; k <= r; k++)
    {
        if(L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        } 
        else 
        {
            A[k] = R[j];
            j++;
        }
    } 
}

void MergeSort(int A[], int p, int r){
    if (p < r){
        int q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        myMerge(A, p, q, r);
    }
}

int binarySearch(int A[], int i, int j,int k){
    int r = -1, m;

    while (i <= j)
    {
        m = (i + j) >> 1;
        if (k == A[m])
        {
            r = m;
            break;
        } else if (k > A[m])
            i = m + 1;
        else
            j = m - 1;    
    }
    
    return r;
}

int BinarySearchFirstOcurrence(int A[], int i, int j, int k){
    int r = binarySearch(A, i, j, k), r2;
    
    if (r < 0) 
        return r;

    if (r > 0)
    {
        r2 = binarySearch(A, i, r-1, k);
        while (r2 >= 0)
        {
            r = r2;
            r2 = binarySearch(A, i, r-1, k);
        }
    }
    return r;
}


int main(){

}