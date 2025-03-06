
#include <stdio.h>

int binarySearch(int A[], int i, int j, int k)
{
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

int binarySearchFirstOcurrence(int A[], int i, int j, int k)
{
    int r = binarySearch(A, i, j, k), r2;

    while (r > 0)
    {
        r2 = binarySearch(A, i, r - 1, k);
        
        if (r2 > 0)
        {
            r = r2;
            r2 = binarySearch(A, i, r - 1, k);
        }
        
    }
    
    return r;
}