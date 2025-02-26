#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    unsigned long long int sumaCuadrados;
    double s;
    
    //Debido a que la suma de impares es n^2, la media va a dar igual a n
    while(scanf("%d", &n) && n != 0){
        sumaCuadrados = (double)n*(n*(double)n-1)/3;
        s = sqrt((double)sumaCuadrados/(n - 1));
        printf("%.6f\n", s);
    }
    
    return 0;
}