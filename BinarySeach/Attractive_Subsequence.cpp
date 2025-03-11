#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 100000  

int BinarySearch(int A[], int i, int j, int k) {
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

int BinarySearchFirstOcurrence(int A[], int i, int j, int k) {
    int result, result2;
    result = BinarySearch(A, i, j, k);
    
    if (result >= 0) {
        result2 = BinarySearch(A, i, result - 1, k);
        while (result2 >= 0) {
            result = result2;
            result2 = BinarySearch(A, i, result - 1, k);
        }
    }
    return result;
}

int BinarySearchLastOcurrence(int A[], int i, int j, int k) {
    int result, result2;
    result = BinarySearch(A, i, j, k);

    if (result >= 0) {
        result2 = BinarySearch(A, result + 1, j, k);
        while (result2 >= 0) {
            result = result2;
            result2 = BinarySearch(A, result + 1, j, k);
        }
    }
    return result;
}

int main() {
    int A[MAXN + 1], n, q, index, idConsulta, k, element;
    int i, leftIndex, rightIndex;
    long long int result = 0;
    
    A[0] = 0;

    scanf("%d %d", &n,  &q);

    for (index = 1; index <= n; index++){
        
        scanf("%d", &element);
        A[index] = A[index - 1] + element;
    }

    for (idConsulta = 1; idConsulta <= q; idConsulta++) {
        
        result = 0;
        scanf("%d", &k);
        for(i = 0; i <= n; i++){
            leftIndex = BinarySearchFirstOcurrence ( A, i+1, n, A[i]+k);
            
            if(leftIndex >= 0){    
                rightIndex = BinarySearchLastOcurrence ( A, leftIndex, n, A[i]+k);
                result += (rightIndex - (leftIndex - 1));
            }
            
        }
        if(idConsulta == 1)    
            printf("%lld", result);
        else
            printf(" %lld", result);
        
    }
    printf("\n");
    return 0;
}