#include <stdio.h>
#include <stdlib.h>
#define myInfinite 2147483647 
#define MAXN 500000 

void myMerge(int A[], int p, int q, int r)
{
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

int BinarySearch (int A[], int i, int j, int k){
    int r = -1, m;

    while (i <= j)
    {
        m = (i + j)/2;
        /*m = (i+j) >> 1;*/
        if (k == A[m])
        {
            r = m;
            break;
        }
        else 
        {
            if (k > A[m])
                i = m + 1;
            else 
                j = m - 1;
        }
    }

    if (r == -1)
        r = -1 * i - 1;

    return r;
}

int main(){
    int A[MAXN + 1], i, position, n, q, idQuery, sum, element;
    long long int result;

    scanf("%d %d", &n, &q);
    for(i = 1; i <= n; i++)
        scanf("%d", &A[i]);

    MergeSort(A, 1, n);

    for(idQuery = 1; idQuery <= q; idQuery++)
    {
        result = 0;
        scanf("%d", &sum);
        for(i = 1; i < n; i++)
        {
            element = sum - A[i];
            if(element > A[i])
            {
                position = BinarySearch(A, i + 1, n, element);
                if (position < 0)
                    position = -1 * position - 2;

                result += position - i;
            }
        }
        printf("%lld\n", result);
    }
    
    return 0;
}