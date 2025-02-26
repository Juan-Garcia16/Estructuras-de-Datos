#include <stdio.h>
#include <math.h>

int main(){
    int t, tCases, k, x, y;
    unsigned long long n, r;

    scanf("%d", &t);

    for (tCases = 1; tCases <= t; tCases++) {
        scanf("%llu", &n);
        //Ultima capa completa de la espiral
        k = (int)(sqrtl(n) / 2); 
        //Cantidad de puntos a moverse desde el inicio de la espiral (k+1) para llegar al punto ingresado
        r = n - (4*(unsigned long long)k*k); 
        
        //Punto en la esquina inferior derecha de cada triangulo cuando k es igual a la capa misma
        if (r == 0) {
            x = (2*k - 1);
            y = -k + 1;
        } 
        //Piso de cada triangulo
        else if (r <= (4*k + 2)) {
            x = (2*k + 1) - r;
            y = -k;
        } 
        //Parte superior izquierda
        else if (r <= 3*(2*k + 1)) {
            x = r - 3*(2*k + 1);
            y = -k + (r - (4*k + 2));
        }
        //Parte superior derecha
        else {
            x = r - 3*(2*k + 1);
            y = k + 1 - x;
        }
        printf("%d %d\n", x, y);
    }  
    return 0;
}