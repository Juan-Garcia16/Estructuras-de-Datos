#include <stdio.h>
#include <stdlib.h>
/*
int main (){
    int k, n, w, total, prestamo;
    
    scanf("%d %d %d", &k, &n, &w);
    
    total = (k*(w*(w+1)))/2;
    
    prestamo = total - n;
    if (prestamo <= 0)
    {
        printf("0");
    } else {
        printf("%d\n", prestamo);
    }
    return 0;
}
*/
/*
#include <math.h>
int main(){
    int t, n, atletas, ganador;

    scanf("%d", &t);
    while (t--)
    {   
        scanf("%d", &n);
        atletas = pow(2,n);
        ganador = atletas - 1;
        printf ("%d\n", ganador);
    }
    return 0;
}
*/

int main(){
    int w;

    scanf("%d", &w);
    if (w % 2 == 0 && w > 2)
    {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}