#include <stdio.h>
#include <stdlib.h>
#define MAXN 100

int binarySearch (int A[], int i, int j, int k){
    int r = -1, m;

    while (i <= j)
    {
        m = (i+j)/2;
        /*m = (i+j) >> 1;*/
        if (k == m)
        {
            r = m;
            break;
        }
        else {
            if (k > A[m])
            {
                i = m - 1;
            }
            else {
                j = m - 1;
            }
        }
    }

    if (r = -1)
        r = -1*i -1;
    
    return r;
}

int main(){
    int TN[MAXN + 1], index, q, idQuery, element;
    int position;
    TN[0] = 0;
    
    for (index = 1; index <= MAXN; index++)
        TN[index] = TN[index - 1] + index;

    scanf("%d", &q);

    for (idQuery = 1; idQuery <= q; idQuery++)
    {
        scanf("%d", &element);
        position = binarySearch(TN, 1, MAXN, element);
        if (position > 0)
            printf("The %d is in the array in the positicion: %d\n", element, position);
        else
            printf("The %d is not in the array. Insertion point %d\n", element, 
                    -1*position - 1);
    }
    return 0;
}