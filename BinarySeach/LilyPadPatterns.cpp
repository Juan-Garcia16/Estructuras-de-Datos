#include <stdio.h>
#define MAX 1200000

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
    int n, PosicionRanas[MAX + 1], LiriosLibres[MAX + 1], lirioLibre, contador = 1, q, salto;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d ", &PosicionRanas[i]);
    
    scanf("%d", &q);
    
    for (int i = 1; i <= MAX + 1; i++)
    {
        lirioLibre = BinarySearch(PosicionRanas, 1, n + 1, i);

        if (lirioLibre < 0)
        {
            LiriosLibres[contador] = i;
            contador++;
        }
        
    }

    for (int i = 1; i <= q; i++)
    {
        scanf("%d", &salto);

        int lirioOcupado = PosicionRanas[salto];

        int lirioCercano = BinarySearch(LiriosLibres, 1, contador - 1, lirioOcupado);
        lirioCercano = -1 * lirioCercano - 1;

        int lirioVacio = LiriosLibres[lirioCercano];

        PosicionRanas[salto] = lirioVacio;
        LiriosLibres[lirioCercano] = lirioOcupado;

        printf("%d\n", PosicionRanas[salto]);
    }

    return 0;
}
//terminado