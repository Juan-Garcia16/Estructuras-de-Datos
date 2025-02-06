/*📌 11️⃣ Actividad para ti

💡 Desafío: Suma de números positivos
📌 Escribe un programa que:

Pida al usuario números enteros y los sume.
Deje de pedir números cuando el usuario ingrese un número negativo.
Muestre la suma total de los números positivos ingresados.*/

#include <iostream>
using namespace std;

int main(){
    int num = 0;
    int total = 0;

    cout << "Ingrese un numero positivo para sumar: ";
    cin >> num;
    while (num >= 0)
    {   
        total += num;
        cout << "Ingrese un numero positivo para sumar: ";
        cin >> num;    
    }
    
    
    cout << "total de la suma: " << total << endl;

    return 0;
}