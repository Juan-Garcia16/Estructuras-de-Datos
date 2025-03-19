#include <stdio.h>
#define MAXN 200000
#define infinity 2147483647

int BinarySearch(long long int A[], int i, int j, long long int k) {
    int m, result = -1;

    while (i <= j) {
        m = (i + j) >> 1; 

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


void myMerge (long long int A[], int p, int q, int r) {
    int n1 = q - p + 1, n2 = r - q, i, j, k;
    int L[n1+2], R[n2+2];
    
    for (i = 1; i <= n1; i++) L[i] = A[p+i-1];

    for (j = 1; j <= n2; j++) R[j] = A[q+j];

    L[n1+1] = infinity;
    R[n2+1] = infinity;
    i = 1;
    j = 1;

    for(k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void MergeSort (long long int A[], int p, int r) {
    int q;
    if (p < r) {
        q =  (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        myMerge(A, p, q, r); 
    }
}

int main(){
    int n, i, totalCases, idCase, index;
    long long int acoCoral[MAXN + 1], acoWater[MAXN + 1], A[MAXN + 1];
    long long int x, colMax, h;

    scanf("%d", &totalCases);
    for(idCase = 1; idCase <= totalCases; idCase++)
    {
        scanf("%d %lld", &n, &x);
        for (i = 1; i <= n; i++)
            scanf("%lld", &A[i]);
        
        MergeSort(A, 1, n) ;

        acoCoral[1] = A[1];
        acoWater[1] = 0;

        for (i = 2; i <= n; i++)
        {
            acoCoral[i] = acoCoral[i-1] + A[i];
            acoWater[i] = (i * A[i]) - acoCoral[i];
        }

        index = BinarySearch(acoWater, 1, n, x);

        if (index >= 0)
            h = A[index];
        else
        {
            colMax = -1 * index - 2;
            h = A[colMax] + (x - acoWater[colMax]) / colMax;
        }

        printf("%lld\n", h);
        
    }

    return 0;
}