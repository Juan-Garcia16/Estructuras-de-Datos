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

int BinarySearchFirstOccurrence(int A[], int i, int j, int k) {
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

int BinarySearchLastOccurrence(int A[], int i, int j, int k) {
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
    
    int A[MAXN + 1], n, idTank, q, idConsulta, k, position;
    
    while(scanf("%d %d", &n, &q) != EOF){
        
        scanf("%d", &A[1]);
        A[1] = 1; 
        
        for(idTank = 2; idTank <= n; idTank++){
            scanf("%d", &A[idTank]);
            A[idTank] += A[idTank - 1];
        }
        
        for(idConsulta = 1; idConsulta <= q; idConsulta++){
            scanf("%d", &k);
            position = BinarySearch(A, 1, n, k);
            if(position < 0)
                position = -1 * position - 2; 
            
            if(idConsulta == 1)
                printf("%d", position);
            else
                printf(" %d", position);
        }
        printf("\n");
    }

    return 0;
}