#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int main(){
    int *p;

    p = (int *)malloc(sizeof(int));

    printf("Direccion de memoria apuntada por el puntero p: %d\n", p);

    *p = 821;
    printf("Direccion de memoria apuntada por el puntero p: %d\n", &p);
    printf("Direccion de memoria apuntada por el puntero p: %d\n", *p);
    return 0;
}*/

/*
typedef struct 
{
    int a;
    float b;
    double c;
    char *p;
} estructura;

int main(){
    estructura *q;
    int n = 10;

    q = (estructura *)malloc(sizeof(estructura));

    q->a = 8;
    q->b = 10.31;
    q->c = 10.32;
    q->p = (char *)malloc(n);

    strcpy(q->p, "cadena");

    printf("%d %.2f %.2lf %s", q->a, q->b, q->c, q->p); //*(q->p) apuntaria solo a c, mientras que por ser %s recorre todo hasta el \0
    //

    return 0;
}*/
