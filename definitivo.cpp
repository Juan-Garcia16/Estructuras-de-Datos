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
    int acumulador[MAXN+1], n, i, count = 0;
    long long int triangular[MAXN+1], result;


    for (i = 1; i <= MAXN; i++)
    {
        triangular[i] = (long long int)i*(i + 1) / 2; 
    }
    

    for (i = 1; i <= MAXN; i++)
    {   
        result = binarySearch(triangular, 0, MAXN, triangular[i+1] + triangular[i]);
        if (result > 0)
            count++;
        
        acumulador[i] = count;   
    }

    
    for (i = 1; i <= MAXN; i++)
    {
        printf("%d ", acumulador[i]);
    }

    printf("\n\n\n");

    for (i = 1; i <= MAXN; i++)
    {
        printf("%lld ", triangular[i]);
    }

    return 0;
}


/*    for (i = 1; i < n; i++)
    {
        printf("%lld ", triangular[i]);
    }

    printf("\n\n\n %lld \n %d", triangular[0], count);
    */