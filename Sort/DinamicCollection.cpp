#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 2000000
#define infinity 2147483647

int collection[MAXN + 1];

int BinarySearch(int A[], int i, int j, int k) {
    int m, result = -1;

    while (i <= j) {
        m = (i + j) >> 1; 

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

void myMerge (int A[], int p, int q, int r) {
    int n1 = q - p + 1, n2 = r - q, i, j, k;
    int L[n1+2], R[n2+2];
    
    for (i = 1; i <= n1; i++) L[i] = A[p+i-1];

    for (j = 1; j <= n2; j++) R[j] = A[q+j];

    L[n1+1] = infinity;
    R[n2+1] = infinity;
    i = 1;
    j = 1;

    for(k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void MergeSort (int A[], int p, int r) {
    int q;
    if (p < r) {
        q =  (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        myMerge(A, p, q, r); 
    }
}

int option1(int k, int collection[], int n){
    int position = BinarySearch(collection, 1, n, k), isAdded = 0;
    
    if (position < 0){
        position =  (-1) * position - 1;
        
        if(position > n){
            collection[n + 1] = k;
            isAdded = 1;
        }
        else
            collection[position] = k;
    }    
    return isAdded;
}

int main (){
    int n, q, a, b, k, selection, i, idQuery, newSize, left, rigth, r;
    
    scanf("%d %d", &n, &q);
    
    
    for(i = 1; i <= n; i++)
        scanf("%d", &collection[i]);    
        
    MergeSort(collection, 1, n);
        
    for(idQuery = 1; idQuery <= q; idQuery++){
        
        scanf("%d", &selection);
        
        if(selection == 1){
            
            scanf("%d", &k);
            newSize = option1(k, collection, n);
            if (newSize == 1)
                n = n+1;    
        }
        
        else{
            scanf("%d %d", &a, &b);
            left = BinarySearchFirstOccurrence(collection, 1, n, a);
            rigth = BinarySearchLastOccurrence(collection, 1, n, b);
            
            if(left < 0)
                left = -1 * left -1;
            
            if(rigth < 0)
                rigth = -1 * rigth - 2;
        
            r = rigth - left + 1;
            
            printf("%d\n", r);   
        }
    }  
    return 0;
}