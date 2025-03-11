#include <stdio.h>
#define MAX 1000000

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

int main(){
    int n, PosicionRanas[2*MAX + 1], LiriosLibres[MAX + 1], lirioLibre, contador = 1, q, salto;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d ", &PosicionRanas[i]);

    for (int i = 1; i <= 2*n; i++)
    {
        lirioLibre = BinarySearch(PosicionRanas, 1, n, i);

        if (lirioLibre < 0)
        {
            LiriosLibres[contador] = i;
            contador++;
        }
        
    }
    
    scanf("%d", &q);

    for (int i = 1; i <= q; i++)
    {
        scanf("%d", &salto);

        int lirioOcupado = PosicionRanas[salto];
        //int lirioOcupado = PosicionRanas[BinarySearch(PosicionRanas, 1, n, salto)];
        //valor en la posicion salto

        int lirioCercano = BinarySearch(LiriosLibres, 1, n, lirioOcupado);
        lirioCercano = -1 * lirioCercano - 1;

        int lirioVacio = LiriosLibres[lirioCercano];

        PosicionRanas[salto] = lirioVacio;
        LiriosLibres[lirioCercano] = lirioOcupado;

        printf("%d\n", PosicionRanas[salto]);
    }

    return 0;
}