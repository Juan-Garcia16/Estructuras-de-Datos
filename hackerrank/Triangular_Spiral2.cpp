#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXT 1000000

long long int arr[MAXT / 2];

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        long long int x, y, n, layer;
        scanf("%lld %lld", &x, &y);

        bool found = false;

        if (y <= 0)
        {
            unsigned long long int x_component = abs(y) + 1;
            long long int end = 2 * (-1 * x_component) + 1;
            long long int start = 2 * x_component - 1;

            if (x >= end && x <= start)
            {
                long long int ref = (start - 1) * (start - 1) + 1;

                if (start == x)
                {
                    n = (start + 1) * (start + 1);
                }
                else
                {
                    n = ref + abs(x - start + 1);
                }

                found = true;
            }
        }

        if (!found)
        {
            long long int diff = abs(x);
            long long int layer = y + diff;
            long long int ref = (2 * layer) * (2 * layer - 1) + 1;

            if (x < 0)
            {
                n = ref - diff;
            }
            else
            {
                n = ref + diff;
            }
        }

        printf("%lld\n", n);
    }
    return 0;
}