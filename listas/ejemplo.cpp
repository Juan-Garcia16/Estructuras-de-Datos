#include <stdio.h>

void sumarAyB(int a, int b, int c){
    c = a + b;
}

void sumarAyBprima(int a, int b, int *c){ //c se recibe por referencia
    *c = a + b;
}

int main(){
    int a = 10, b = 15, c = 0;

    sumarAyB(a, b, c);
    printf("El resutado de %d + %d es %d\n", a, b, c);

    sumarAyBprima(a, b, &c);// se envia la direccion de memoria de c
    printf("El resutado de %d + %d es %d\n", a, b, c);

    return 0;
}