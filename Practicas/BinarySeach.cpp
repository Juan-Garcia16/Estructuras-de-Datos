#include <stdio.h>

int binarySearch(int A[], int i, int j, int k){
    int r = -1, m;

    while (i <= j)
    {
        m = (i + j) / 2;
        if (k == A[m])
        {
            r = m;
            break;
        }
        else if (k > A[m])
            i = m + 1;
        else
            j = m - 1;
    }

    if (r == -1)
        r = -1 * i - 1;

    return r;
}

int main(){
    int A[100], index, n, queries, idQueries, k, position;

    scanf("%d", &n);
    for (index = 1; index <= n; index++)
        scanf("%d", &A[index]);

    scanf("%d", &queries);
    for (idQueries = 1; idQueries <= queries; idQueries++)
    {
        k = 0;
        scanf("%d", &k);
        position = binarySearch(A, 1, n, k);

        if (position >= 0)
            printf("El numero %d se encuentra en la posicion %d\n", k, position);
        else
            printf("El numero %d NO esta en el arreglo, punto de insersion %d\n", k,position);
    }
    
    return 0;
}