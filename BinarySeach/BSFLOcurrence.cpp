#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 1000  // Tamaño máximo del array

int BinarySearch(int A[], int i, int j, int k) {
    int m, result = -1;

    while (i <= j) {
        m = (i + j) / 2;  // Equivalente a (i + j) >> 1

        if (A[m] == k) {
            result = m;
            break;
        } else if (k > A[m]) {
            i = m + 1;
        } else {
            j = m - 1;
        }
    }

    if (result == -1)
        result = (-1) * i - 1;
    
    return result;
}

int BinarySearchFirstOccurrence(int A[], int i, int j, int k) {
    int result, result2;
    result = BinarySearch(A, i, j, k);
    
    if (result >= 0) {
        result2 = BinarySearch(A, i, result - 1, k);
        while (result2 >= 0) {
            result = result2;
            result2 = BinarySearch(A, i, result - 1, k);
        }
    }
    return result;
}

int BinarySearchLastOccurrence(int A[], int i, int j, int k) {
    int result, result2;
    result = BinarySearch(A, i, j, k);

    if (result >= 0) {
        result2 = BinarySearch(A, result + 1, j, k);
        while (result2 >= 0) {
            result = result2;
            result2 = BinarySearch(A, result + 1, j, k);
        }
    }
    return result;
}

int main() {
    int A[MAXN + 1], n, index, q, idQuery, element;
    int position;

    scanf("%d", &n);

    // Llenado del array desde el índice 1
    for (index = 1; index <= n; index++)
        scanf("%d", &A[index]);

    scanf("%d", &q);

    for (idQuery = 1; idQuery <= q; idQuery++) {
        scanf("%d", &element);
        position = BinarySearchFirstOccurrence(A, 1, n, element);
        
        if (position >= 0) {
            printf("The first occurrence of %d in the array is at position: %d\n", element, position);
            position = BinarySearchLastOccurrence(A, position, n, element);
            printf("The last occurrence of %d in the array is at position: %d\n", element, position);
        } else {
            printf("The %d is not in the array. Insertion point: %d\n", element, -1 * position - 1);
        }
    }

    return 0;
}