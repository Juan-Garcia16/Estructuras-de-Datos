#include <stdio.h>
#include <math.h>
#define MAXN 1415

int binarySearch (long long int A[], int i, int j, int k){
    int r = -1, m;

    while (i <= j)
    {
        m = (i+j)/2;
        if (k == A[m])
        {
            r = m;
            break;
        }
        else {
            if (k > A[m])
                i = m + 1;
            else 
                j = m - 1;
        }
    }

    if (r == -1)
        r = -1*i -1;
    
    return r;
}


int countNumericCenters(int n, long long triangulares[], int tam) {
    int count = 0;

    for (int i = 1; i <= n; i++) {
        long long suma = (long long)i * (i + 1) / 2; 
        long long raiz = (long long) sqrt(suma);

        if (raiz * raiz == suma) {
            if (binarySearch(triangulares, 0, tam, suma)) { 
                count++; 
            }
        }
    }

    return count;
}

int main() {
    int n;
    long long triangulares[MAXN], suma; 
    
    while (scanf("%d", &n) && n != 0){      
        int i = 0;
        while (i < n)
        {
            suma = (i*(i + 1)) / 2;
            triangulares[i] = suma;
            i++;
        }
    
        printf("%d\n", countNumericCenters(n, triangulares, MAXN) - 1);
    }
    
    return 0;
}
