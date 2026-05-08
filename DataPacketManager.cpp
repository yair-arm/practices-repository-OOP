#include <iostream>
#include <stdexcept>

class Paquete {
private:
    int tamañoBytes = 0;
    const int Limite_Buffer = 1024;
public:
    // Constructor explicito, ya que la clase paquete puede confundirse con un tipo de dato int por el compilador
    explicit Paquete (int t) : tamañoBytes(t){}

    void cargarDato() {
        tamañoBytes += 64;
    }
    void cargarDato(int c) {
        if (tamañoBytes + c > Limite_Buffer) {
            throw std::runtime_error("Error: Buffer limit reached, please charge a lower one");
        }
        tamañoBytes += c;
    }
    Paquete operator+(const Paquete& otro) const {
        Paquete res(tamañoBytes);
        res.cargarDato(otro.tamañoBytes);
        return res;
    }
    friend std::ostream& operator<<(std::ostream& os, const Paquete& otro) {
        os << "[Packet: " << otro.tamañoBytes << " / 1024 bytes]" << std::endl;
        return os;
    }
};

int main () {
    Paquete p1(0);
    Paquete p2(0);
    p1.cargarDato();
    std::cout << p1 << std::endl << std::flush;
    try {
        p1.cargarDato(91);
        std::cout << p1 << std::endl;
        p2.cargarDato(100);
        std::cout << p2 << std::endl;
        const Paquete p3 = p1 + p2;
        std::cout << p3 << std::endl;
    } catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}
