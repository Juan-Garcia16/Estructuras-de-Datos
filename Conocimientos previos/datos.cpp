#include <iostream>
using namespace std;

int datos() {
    int entero = 10;
    float flotante = 3.14;
    double doble = 3.14159265359;
    char caracter = 'a';
    bool booleano = true;

    cout << "Entero: " << entero << endl;
    cout << "Flotante: " << flotante << endl;
    cout << "Doble: " << doble << endl;
    cout << "Caracter: " << caracter << endl;
    cout << "Booleando: " << booleano << endl;
    cout << "---------------------" << endl;

    return 0;
}

int operadores() {
    int a = 15, b = 3;

    cout << "Suma: " << a + b << endl;
    cout << "Resta: " << a - b << endl;
    cout << "Multiplicacion: " << a * b << endl;
    cout << "Division: " << a / b << endl;
    cout << "Modulo: " << a % b << endl;
    cout << "---------------------" << endl;

    int x = 5, y = 10;

    cout << "x == y: " << (x == y) << endl;
    cout << "x != y: " << (x != y) << endl;
    cout << "x < y: " << (x < y) << endl;
    cout << "x > y: " << (x > y) << endl;
    cout << "x <= y: " << (x <= y) << endl;
    cout << "x >= y: " << (x >= y) << endl;

    return 0;

    return 0;
}

int operadores_logicos(){
    bool a = true, b = false;
    
    cout << "---------------------" << endl;
    cout << "AND (&&)" << (a && b) << endl;
    cout << "OR (||)" << (a || b) << endl;
    cout << "NOT (!)" << !a << endl;

    return 0;
}


/* Actividad avanzada: Calculadora con validación de entrada
Instrucciones:

Escribe un programa en C++ que actúe como una calculadora mejorada.
El usuario ingresará dos números y un operador (+, -, *, /, %).

Validaciones:
Si el usuario ingresa un operador inválido, mostrar un mensaje de error.
Si el usuario intenta dividir por cero, mostrar un mensaje de advertencia y no realizar la operación.
El operador % solo debe permitirse si ambos números son enteros.
Muestra el resultado de la operación.
*/
int actividad(){
    int a, b;
    char operador;
    int resultado;

    cout << "CALCULADORA" << endl;
    cout << "Ingrese el primer número: ";
    cin >> a;
    cout << "Ingrese el segundo número: ";
    cin >> b;
    cout << "Ingrese la operación (+, -, *, /, %): ";
    cin >> operador;

    if (operador != '+' && operador != '-' && operador != '*' && operador != '/' && operador != '%')
    {
        cout << "Error: El operador no es valido" << endl; 
        return 0;
    } else if (operador == '+')
    {
        resultado = a + b;
    } else if (operador == '-')
    {
        resultado = a - b;
    } else if (operador == '*')
    {
        resultado = a * b;
    } else if (operador == '/')
    {
        if (b == 0)
        {
            cout << "Error: No se puede dividir por cero." << endl;
            return 0;
        } else {
            resultado = a / b;
        }
    } else if (operador == '%')
    {
        if ((a == static_cast<int>(a)) && (b == static_cast<int>(b))) {
            resultado = a % b;
        } else {
            cout << "No es un número entero.\n";
            return 0;
        }
    }

    cout << "El resultado es: " << resultado << endl;
    return 0;
}

int main() {
    datos();
    operadores();
    operadores_logicos();
    actividad();
}
