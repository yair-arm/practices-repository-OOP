#include <iostream>
#include <windows.h>
using namespace std;

class Calculadora {
public:
    static int suma(int a, int b) {
        return a + b;
    }

    static float suma(float a, float b) {
        return a + b;
    }

    static double suma(double a, double b) {
        return a + b;
    }

    static int resta(int a, int b) {
        return a - b;
    }

    static float resta(float a, float b) {
        return a - b;
    }

    static double resta(double a, double b) {
        return a - b;
    }

    static int multiplicacion(int a, int b) {
        return a * b;
    }

    static float multiplicacion(float a, float b) {
        return a * b;
    }

    static double multiplicacion(double a, double b) {
        return a * b;
    }

    static int division(int a, int b) {
        return a / b;
    }

    static float division(float a, float b) {
        return a / b;
    }

    static double division(double a, double b) {
        return a / b;
    }
};

void Menu() {
    int op = 0;

    while (op < 1 || op > 3) {
        cout << "¿Qué desea hacer?" << endl;
        cout << "1. Operar dos enteros" << endl;
        cout << "2. Operar dos flotantes" << endl;
        cout << "3. Operar dos doble presición" << endl;
        cout << endl;

        cin >> op;

        if (op == 1) {
            int op2;
            cout << "Desea: " << endl;
            cout << "1. Sumar dos enteros" << endl;
            cout << "2. Restar dos enteros" << endl;
            cout << "3. Multiplicar dos enteros" << endl;
            cout << "4. Dividr dos enteros" << endl;
            cout << endl;
            cin >> op2;

            if (op2 == 1) {
                int a, b;

                cout << "Ingrese el primer número entero" << endl;
                cin >> a;
                cout << "Ingrese el segundo número entero" << endl;
                cin >> b;

                int suma = Calculadora::suma(a, b);

                cout << "La suma de sus dos números enteros es: " << suma << endl;
            } else if (op2 == 2) {
                int a, b;

                cout << "Ingrese el primer número entero" << endl;
                cin >> a;
                cout << "Ingrese el segundo número entero" << endl;
                cin >> b;

                int resta = Calculadora::resta(a, b);

                cout << "La resta de sus dos números enteros es: " << resta << endl;
            } else if (op2 == 3) {
                int a, b;

                cout << "Ingrese el primer número entero" << endl;
                cin >> a;
                cout << "Ingrese el segundo número entero" << endl;
                cin >> b;

                int mult = Calculadora::multiplicacion(a, b);

                cout << "La multiplicación de sus dos números enteros es: " << mult << endl;
            } else if (op2 == 4) {
                int a, b;

                cout << "Ingrese el primer número entero" << endl;
                cin >> a;
                cout << "Ingrese el segundo número entero" << endl;
                cin >> b;

                int div = Calculadora::division(a, b);

                cout << "La división de sus dos números enteros es: " << div << endl;
            }
        } else if (op == 2) {
            int op2;
            cout << "Desea: " << endl;
            cout << "1. Sumar dos flotantes" << endl;
            cout << "2. Restar dos flotantes" << endl;
            cout << "3. Multiplicar dos flotantes" << endl;
            cout << "4. Dividr dos flotantes" << endl;
            cout << endl;
            cin >> op2;

            if (op2 == 1) {
                float a, b;

                cout << "Ingrese el primer número entero" << endl;
                cin >> a;
                cout << "Ingrese el segundo número entero" << endl;
                cin >> b;

                float suma = Calculadora::suma(a, b);

                cout << "La suma de sus dos números enteros es: " << suma << endl;
            } else if (op2 == 2) {
                float a, b;

                cout << "Ingrese el primer número entero" << endl;
                cin >> a;
                cout << "Ingrese el segundo número entero" << endl;
                cin >> b;

                float resta = Calculadora::resta(a, b);

                cout << "La resta de sus dos números enteros es: " << resta << endl;
            } else if (op2 == 3) {
                float a, b;

                cout << "Ingrese el primer número entero" << endl;
                cin >> a;
                cout << "Ingrese el segundo número entero" << endl;
                cin >> b;

                float mult = Calculadora::multiplicacion(a, b);

                cout << "La multiplicación de sus dos números enteros es: " << mult << endl;
            } else if (op2 == 4) {
                float a, b;

                cout << "Ingrese el primer número entero" << endl;
                cin >> a;
                cout << "Ingrese el segundo número entero" << endl;
                cin >> b;

                float div = Calculadora::division(a, b);

                cout << "La división de sus dos números enteros es: " << div << endl;
            }
        } else if (op == 3) {
            int op2;
            cout << "Desea: " << endl;
            cout << "1. Sumar dos de doble presición" << endl;
            cout << "2. Restar dos de doble presición" << endl;
            cout << "3. Multiplicar dos de doble presición" << endl;
            cout << "4. Dividr dos de doble presición" << endl;
            cout << endl;
            cin >> op2;

            if (op2 == 1) {
                double a, b;

                cout << "Ingrese el primer número entero" << endl;
                cin >> a;
                cout << "Ingrese el segundo número entero" << endl;
                cin >> b;

                double suma = Calculadora::suma(a, b);

                cout << "La suma de sus dos números enteros es: " << suma << endl;
            } else if (op2 == 2) {
                double a, b;

                cout << "Ingrese el primer número entero" << endl;
                cin >> a;
                cout << "Ingrese el segundo número entero" << endl;
                cin >> b;

                double resta = Calculadora::resta(a, b);

                cout << "La resta de sus dos números enteros es: " << resta << endl;
            } else if (op2 == 3) {
                double a, b;

                cout << "Ingrese el primer número entero" << endl;
                cin >> a;
                cout << "Ingrese el segundo número entero" << endl;
                cin >> b;

                double mult = Calculadora::multiplicacion(a, b);

                cout << "La multiplicación de sus dos números enteros es: " << mult << endl;
            } else if (op2 == 4) {
                double a, b;

                cout << "Ingrese el primer número entero" << endl;
                cin >> a;
                cout << "Ingrese el segundo número entero" << endl;
                cin >> b;

                double div = Calculadora::division(a, b);

                cout << "La división de sus dos números enteros es: " << div << endl;
            }
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Menu();
    return 0;
}