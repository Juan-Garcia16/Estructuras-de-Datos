#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


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

int main(int n) {
    long long int k, triangular, kplus1;
    int n;
    
    while(scanf("%llu", &n) && n != 0){
        k = (-1 + sqrt(1 + 8*(double)n))/2;
        kplus1 = k + 1;
        
        if(k % 2 == 0)
            k /= 2;
        else 
            kplus1 /= 2;
        triangular = k*kplus1;
        
        if(triangular == n)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}