// Johann's Function

/*unsigned long long JohannsFunction(int n)
{
    int i, j;
    unsigned long long result = 0;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= i; j++)
        {
            result += j;
        }
    }

    return result;
}

En la funcion de Johann, lo que se hace es que por cada iteracion, con i desde 1 hasta n, le suma al valor actual de result los numeros de 1 hasta i. Por lo tanto, result se puede plantear como relacion de recurrencia

result(1) = 1
result(2) = result(1) + (1 + 2) = (1) + (1 + 2)
result(3) = result(2) + (1 + 2 + 3) = (1) + (1 + 2) + (1 + 2 + 3)

En ese caso, podemos decir que es la sumatoria de la sumatoria de Gauss. Como ya sabemos que
la sumatoria de Gauss es (n(n + 1))/2, entonces podemos decir que la sumatoria de la sumatoria de Gauss va a ser la sumatoria desde i = 1 hasta n de (i(i + 1))/2

Por propiedades de sumatorias, sacamos el 1/2 a multiplicar, y nos queda la sumatoria desde i = 1 hasta n de i(i + 1)

Aplicamos distributiva y nos queda la sumatoria de (i^2 + i)

Estas sumatorias tienen solucion establecida. La solucion de i^2 es (n(n + 1)(2*n + 1))/6

Asi nos queda (1/2)((n(n + 1)(2*n + 1))/6 + (n(n + 1))/2)

Factorizamos el (n(n + 1))/2 y queda

((n(n + 1))/4)((2*n + 1)/3 + 1) y operamos la suma dentro del parentesis, entonces queda:

((n(n + 1))/4)((2*n + 4)/3) En el numerador se factoriza el 2, y queda

((n(n + 1))/4)(2(n + 2)/3) por lo que el dos de arriba se divide con en 4 de abajo y el (1/4) pasa a ser (1/2)

((n(n + 1))/2)((n + 2)/3) y al operar, queda que la solucion de la relacion de recurrencia es

(n(n + 1)(n + 2))/6

Por lo que toda la funcion de Johann se puede reemplazar por esa expresion, reduciendo el numero de operaciones y haciendo que el algoritmo sea mas eficiente computacionalmente.
*/

#include <cstdio>

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        unsigned long long int n, result;//unsigned long long porque n puede ser hasta 10^6, lo cual cabe en el int, pero luego por las multiplicaciones se puede desbordar
        scanf("%llu", &n);

        result = (n*(n + 1)*(n + 2))/6;

        printf("%llu\n", result);
    }

    return 0;
}