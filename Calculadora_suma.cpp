#include <iostream>
#include <windows.h>
using namespace std;

class Calculadora_suma {
    public:
    int suma(int a, int b) {
        int suma = a + b;
        return suma;
    }

    int suma(int a, int b, int c) {
        int suma = a + b + c;
        return suma;
    }

    float suma(float a, float b) {
        float suma = a + b;
        return suma;
    }
};

void Menu() {
    Calculadora_suma calc;
    int op = 0;

    while (op < 1 || op > 3) {
        cout << "¿Qué desea hacer?" << endl;
        cout << "1. Sumar dos enteros" << endl;
        cout << "2. Sumar tres enteros" << endl;
        cout << "3. Sumar dos flotantes" << endl;
        cout << endl;

        cin >> op;

        if (op == 1) {
            int suma;
            int a, b;

            cout << "Ingrese el primer número entero" << endl;
            cin >> a;
            cout << "Ingrese el segundo número entero" << endl;
            cin >> b;

            suma = calc.suma(a, b);

            cout << "La suma de sus dos enteros es de: " << suma << endl;
        } else if (op == 2) {
            int suma;
            int a, b, c;

            cout << "Ingrese el primer número entero" << endl;
            cin >> a;
            cout << "Ingrese el segundo número entero" << endl;
            cin >> b;
            cout << "Ingrese el tercer número entero" << endl;
            cin >> c;

            suma = calc.suma(a, b, c);

            cout << "La suma de sus tres enteros es de: " << suma << endl;
        } else if (op == 3) {
            float a, b;

            cout << "Ingrese su primer flotante" << endl;
            cin >> a;
            cout << "Ingrese su segundo flotante" << endl;
            cin >> b;

            float suma = calc.suma(a, b);

            cout << "La suma de sus flotantes es de: " << suma << endl;
        } else {
            cout << "Número ingresado no válido, por favor ingrese un número entre 1 y 3" << endl;
            cout << endl;
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Menu();
    return 0;
}