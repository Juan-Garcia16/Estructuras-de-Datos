#include <stdio.h>
#include <math.h>

int main(){
    int n, s = 20;
    n = (-1 + sqrt(1 + 8 * s)) / 2;
    printf("%d %lf", n, (double)n);

}