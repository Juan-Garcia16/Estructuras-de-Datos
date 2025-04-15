#include <stdio.h>

int mcd(int a, int b) {
    while (b != 0) {
        int residuo = a % b;
        a = b;
        b = residuo;
    }
    return a;
}

int main() {
    int num1, num2;

    printf("Ingresa dos números: ");
    scanf("%d %d", &num1, &num2);

    printf("El MCD de %d y %d es %d\n", num1, num2, mcd(num1, num2));

    return 0;
}
