#include <iostream>
using namespace std;

class Memoria {
private:
    int procesosActivos = 0;
    const int MaximosProcesos = 10;
public:
    void ejecutar() {
        procesosActivos++;
    }
    void ejecutar(int n) {
        if ((procesosActivos + n) > 10) {
            throw "Error: Cantidad maxima superada";
        }
        procesosActivos += n;
    }
    friend ostream& operator<< (ostream& os, const Memoria& m) {
        os << "CPU Usage: " << m.procesosActivos << "/10" << endl;
        return os;
    }
};

int main() {
    try {
        Memoria m;
        m.ejecutar();
        cout << m << endl;
        m.ejecutar(11);
        cout << m << endl;
    }
    catch (char const* men) {
        cerr << "Atencion: " << men << endl;
    }

}