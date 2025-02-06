#include <iostream>
using namespace std;

/*📌 9️⃣ Actividad para ti

💡 Desafío: Clasificador de números
📌 Escribe un programa que haga lo siguiente:

Pedir al usuario que ingrese un número.
Determinar si el número es positivo, negativo o cero.
Verificar si el número ingresado es par o impar.
Mostrar un mensaje con los resultados.*/

int main(){
    int num;

    cout << "Ingrese un numero: ";
    cin >> num;

    if (num > 0)
    {
        cout << "El numero es positivo" << endl;
    } else if (num < 0)
    {
        cout << "El numero negativo" << endl;
    } else {
        cout << "El numero es 0" << endl;
    }
    
    if ((num % 2) == 0)
    {
        cout << "El numero es par" << endl;
    } else {
        cout << "El numero es impar" << endl;
    }
    
    return 0;
}