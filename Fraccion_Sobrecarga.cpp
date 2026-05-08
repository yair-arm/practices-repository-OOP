#include <iostream>
using namespace std;

class Fraccion {
private:
    int numerador = 0;
    int denominador = 0;
public:
    Fraccion(int num, int dem) : numerador(num), denominador(dem) {}

    Fraccion operator+(const Fraccion &f) {
        int nuevoNumerador = numerador * f.denominador + denominador * f.numerador;
        int nuevoDenominador = denominador * f.denominador;

        return Fraccion(nuevoNumerador, nuevoDenominador);
    }

    bool operator==(const Fraccion &f) {
        return(numerador * f.denominador == denominador * f.numerador);
    }

    void mostrar() {
        cout << numerador << "/" << denominador << endl;
    }
};

int main() {
    Fraccion f1(1, 4), f2(1,2);
    Fraccion f3 = f1 + f2;
    f3.mostrar();
}