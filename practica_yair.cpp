#include <iostream>
#include <stdexcept>
#include <utility>
using namespace std;

class Articulo {
private:
    string nombre;
    double precio;
    int stock;
public:
    Articulo(string n, double p, int s): nombre(std::move(n)), precio(p), stock(s) {
        if (p < 0.0) {
            throw logic_error("El precio no puede ser negativo");
        }
        if (s < 0) {
            throw out_of_range("El stock no puede ser negativo");
        }
    }

    void vender(int cantidad) {
        if (cantidad>stock) {
            throw runtime_error("No hay stock suficiente");
        }
        stock-=cantidad;
    }
    void comprar (int cantidad) {
        stock+=cantidad;
    }

    bool operator==(const Articulo& otro) const{
        return nombre == otro.nombre;
    }
    Articulo operator+(const Articulo& otro)const {
        if (*this==otro) {
            return {nombre,precio,stock+otro.stock};
        } else {
            throw logic_error("Los artículos son diferentes");
        }
    }

    friend ostream& operator<<(ostream& eop, const Articulo& otro) {
        eop << "Nombre: " << otro.nombre << "/ precio: " << otro.precio << "/ stock: " << otro.stock;
        return eop;
    }
};

int main() {
    try {
        Articulo a1("Alfajores Arequipe", 3000, 15 );
        Articulo a2("Alfajores Nutella", 3500, 15 );
        Articulo a3("Oreo", 4500, 15 );
        Articulo a4("Oreo", 4500, 15 );
        Articulo a5=a3+a4;
        a1.vender(6);
        cout << a1 << endl;
        cout << a5 << endl;
    } catch (exception& e) {
        cerr << e.what() << endl;
    }
}