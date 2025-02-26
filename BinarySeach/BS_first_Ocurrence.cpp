#include <stdio.h>
#include <stdlib.h>

int binarySearch (int A[], int i, int j, int k){
    int r = -1, m;

    while (i <= j)
    {
        m = (i+j)/2;
        /*m = (i+j) >> 1;*/
        if (k == A[m])
        {
            r = m;
            break;
        }
        else {
            if (k > A[m])
            {
                i = m + 1;
            }
            else {
                j = m - 1;
            }
        }
    }

    return r;
}

int BinarySearchFirstOcurrence(int A[], int i, int j, int k){
    int r = binarySearch(A, i, j, k), r2;
    
    if (r < 0) {
        return r;
    }

    if (r > 0)
    {
        r2 = binarySearch(A, i, r-1, k);

        while (r2 >= 0)
        {
            r = r2;
            r2 = binarySearch(A, i, r-1, k);
        }
    }
    return r;
}

