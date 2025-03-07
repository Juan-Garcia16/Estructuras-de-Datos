#include <stdio.h>
#include <math.h>
#define MAXN 1415

int binarySearch(long long int A[], int i, int j, long long int k) {
    int m;

    while (i <= j) {
        m = (i + j) / 2;
        
        if (k == A[m]) 
            return m;  
        else if (k > A[m])
            i = m + 1;
        else 
            j = m - 1;
    }

    return -1;
}

int countNumericCenters(int n, long long int triangular[], int size) {
    int count = 0;

    for (int i = 1; i <= n; i++) {
        long long sum = (long long)i * (i + 1) / 2;
        long long root = (long long)sqrt(sum);

        if (root * root == sum) { 
            if (binarySearch(triangular, 0, size - 1, sum) != -1) {  // verifica si es centro numerico
                count++;
            }
        }
    }

    return count;
}

int main() {
    int n;
    long long int triangular[MAXN]; 
    
    // triangulares posibles
    for (int i = 0; i < MAXN; i++) {
        triangular[i] = (long long)(i * (i + 1)) / 2;
    }

    while (scanf("%d", &n) && n != 0) {
        printf("%d\n", countNumericCenters(n, triangular, MAXN));
    }

    return 0;
}
