#include <iostream>
using namespace std;

class Producto {
private:
    int cantidad = 0;

public:
    void llenar() {
        cantidad = 10;
    }
    void llenar (int n) {
        if (n >= 50) {
            throw "Error: Cantidad maxima superada";
        }
        cantidad = n;
    }
    void mostrar() const {
        cout << "La cantidad de producto dispobile es: " << cantidad << endl;
    }
};

int main() {
    Producto p1;

    // 2. LA ZONA DE PRUEBAS (try): Aquí metemos lo que podría fallar
    try {
        p1.llenar(20); // Esto funciona bien
        p1.mostrar();

        cout << "Intentando llenar con 100..." << endl;
        p1.llenar(100); // ¡AQUÍ SALTA LA EXCEPCIÓN!

        // Esta línea de abajo nunca se ejecutará si lo de arriba falla:
        p1.mostrar();

    }
    // 3. EL ESCUDO (catch): Atrapa el mensaje que lanzamos con throw
    catch (const char* error) {
        cerr << "ATENCION: " << error << endl;
    }

    cout << "El programa sigue vivo gracias al catch." << endl;
    return 0;
}