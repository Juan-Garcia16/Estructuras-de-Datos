#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binarySearch(long long int A[], int i, int j, int k) {
    int m, result = -1;

    while (i <= j) {
        m = (i + j) / 2;  

        if (A[m] == k) {
            result = m;
            break;
        } else if (k > A[m]) {
            i = m + 1;
        } else {
            j = m - 1;
        }
    }

    if (result == -1)
        result = (-1) * i - 1;
    
    return result;
}

int main() { 
    int n, resultado = 0;
    long long int triangular[1000000], k;

    for (int i = 0; i < 1000000; i++) {
        triangular[i] = (long long)(i * (i + 1)) / 2; 
    }

    while (scanf("%d", &n) && n != 0) {
        resultado = binarySearch(triangular, 0, 1000000, n);
        
 

        

        printf("%d\n", resultado);
    }

    return 0;
}