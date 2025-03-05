#include <stdio.h>
#include <stdlib.h>
#define MAXN 500000
#define myInfinite 2147483647

int main(){
    int A[MAXN + 1], i, j, n , q, idQuery, sum;
    long long int resutl;

    scanf("%d %d", &n, &q);
    for(i = 1; i <= n; i++)
        scanf("%d", &A[i]);

    for(idQuery = 1; idQuery <= q; idQuery++){
        
        resutl = 0;
        scanf("%d", &sum);
        for(i = 1; i <= n; i++)
        {
            for(j = i + 1; j <= n; j++)
            {
                if(A[i] + A[j] <= sum)
                    resutl++;
                else
                    break;
            }
        }
        printf("%lld\n", resutl);
    }
    return 0;
}

















void myMerge(int A[], int p, int q, int r){
    int n1 = q - p + 1, n2 = r - q, i, j, k;
    int L[n1 + 2], R[n2 + 2];

    for(i = 1; i <= n1; i++)
        L[i] = A[p + i - 1];
    
    for(j = 1; j <= n2; j++)
        R[j] = A[q + j];

    L[n1 + 1] = myInfinite;
    R[n2 + 1] = myInfinite; 
    i = 1;
    j = 1;

    for(k = p; k <= r; k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    } 
}

void mergeSort(int A[], int p, int r){
    int q;

    if (p < r){
        q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        myMerge(A, p, q, r);
    }
}

int main(){
    int A[MAXN + 1], n, i, totalCases, idCase;

    scanf("%d", &totalCases);
    
    for(idCase = 1; idCase <= totalCases; idCase++){
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
            scanf("%d", &A[i]);

        mergeSort(A, 1, n);
    }
    return 0;
}
