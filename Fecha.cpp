#include <iostream>
using namespace std;

class Fecha {
private:
    int dia;
    int mes;
    int anio;

    static int diasmes(const int mes) {
    if (mes == 2) return 28;
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) return 30;
    return 31;
    }

public:
    Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}

    Fecha operator+(const int& sumando) const {
        int nuevosdias = dia + sumando;
        int nuevomes = mes;
        int nuevoanio = anio;

        while (nuevosdias > diasmes(nuevomes)) {
            nuevosdias -= diasmes(nuevomes);
            nuevomes++;
            if (nuevomes > 12) {
                nuevomes = 1;
                nuevoanio++;
            }
        }
        return Fecha {nuevosdias, nuevomes, nuevoanio};
    }
    void mostrar() const {
        cout << dia << "/" << mes << "/" << anio << endl;
    }
};

int main() {
    Fecha fecha1(1, 5, 2026);
    int sumando = 365;
    Fecha nuevafecha = fecha1 + sumando;
    nuevafecha.mostrar();
}