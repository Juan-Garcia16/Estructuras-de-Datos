#include <stdio.h>
#include <math.h>
#define MAXN 1415

int generateTriangular(long long triangular[], int limit) {
    long long sum = 0;
    int i = 1, size = 0;

    while (sum <= limit) {
        sum = (long long)i * (i + 1) / 2; 
        if (sum > limit) break; // no almacenar si ya supera el limite
        triangular[size] = sum;
        size++;
        i++;
    }
    
    return size; // sizeano real del array
}

int binarySearch(long long int A[], int i, int j, int k){
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

int countNumericCenters(int n, long long triangular[], int size) {
    int count = 0;

    for (int i = 1; i <= n; i++) {
        long long int sum = (long long)i * (i + 1) / 2; 
        long long int root = (long long) sqrt(sum);

        if (root * root == sum) { // raiz exacta
            if (binarySearch(triangular, 0, size, sum)) { // centro numerico
                count++; 
            }
        }
    }

    return count;
}

int main() {
    int n;
    long long int triangular[MAXN]; 
    int size = generateTriangular(triangular, 1000000);

    while (scanf("%d", &n) && n != 0) {    
        printf("%d\n", countNumericCenters(n, triangular, size));
    }
    
    return 0;
}
