#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 14142

int BinarySearch(int A[], int i, int j, int k)
{
    int r = -1, m;
    while (i <= j)
    {
        m = (i + j) / 2;
        if (A[m] == k)
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
int main()
{

    int TN[MAXN + 1], index, q, insertionPoint;
    int position, totalcases, idcase, s, totalpages, forgottenpage;
    TN[0] = 0;
    for (index = 1; index <= MAXN; index++)
        TN[index] = TN[index - 1] + index;
    scanf("%d", &totalcases);

    for (idcase = 1; idcase <= totalcases; idcase++)
    {
        scanf("%d", &s);
        position = BinarySearch(TN, 1, MAXN, s);
        if (position >= 0)
        {
            totalpages = position + 1;
            forgottenpage = position + 1;
        }
        else
        {
            insertionPoint = -1 * position - 1;
            totalpages = insertionPoint;
            forgottenpage = TN[insertionPoint] - s;
        }
        printf("%d %d\n", forgottenpage, totalpages);
    }

    return 0;
}