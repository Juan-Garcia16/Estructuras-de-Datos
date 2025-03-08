#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 100

int binarySearch(long long int A[], int i, int j, int k){
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

int main(){
    int acumulador[MAXN+1], n, i, count = 0, j;
    long long int triangular[MAXN+1], result;


    for (i = 1; i <= MAXN; i++)
    {
        triangular[i] = (long long int)i*(i + 1) / 2; 
    }
    

    for (i = 2; i <= MAXN; i++)
    {   
        result = binarySearch(triangular, 1, MAXN, triangular[i] + triangular[i-1]);
        if (result > 0)
            j = result;  
        
        if (i == j)
        {
            count++;    
        }
        
        acumulador[i] = count;   
    }

    while (scanf("%d", &n) && n != 0)
    {
        printf("%d\n", acumulador[n]);
    }
    

    return 0;
}