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
