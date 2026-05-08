#include <iostream>
#include <stdexcept>
#include <string>
#include <windows.h>

class ManaInsuficienteException : public std::runtime_error {
public:
    ManaInsuficienteException() : std::runtime_error ("¡Error! El heroe no tiene suficiente mana para este hechizo."){}
};

class Entidad {
public:
    virtual void mostrarEstado() = 0;
    virtual ~Entidad() = default;
};

class Guerrero : virtual public Entidad {
protected:
    int fuerza = 0;
public:
    explicit Guerrero (int f) : fuerza(f) {}
    ~Guerrero() override = default;
};

class Mago : virtual public Entidad {
protected:
    int mana = 0;
public:
    explicit Mago (int m) : mana(m){}
    ~Mago() override = default;
};

class MagoGuerrero : public Guerrero, public Mago {
public:
    MagoGuerrero(const int f, const int m) : Guerrero(f), Mago(m) {}
    ~MagoGuerrero() override = default;
    void mostrarEstado() override {
        std::cout<<"Fuerza: "<<fuerza<<std::endl;
        std::cout<<"Mana: "<<mana<<std::endl;
        std::cout << "\n";
    }
    void atacar() const {
        std::cout<<"Se hizo "<<fuerza<<" de daño."<<std::endl;
        std::cout << "\n";
    }
    void atacar(const std::string& h) {
        int resmana=0;
        if (h=="fuego") {
            resmana=5;
            if (mana>resmana) {
                mana-=resmana;
                std::cout<<"¡¡Lanzaste una bola de fuego!!, consumiste 5 de mana"<< std::endl;
                std::cout << "\n";
            } else {
                throw ManaInsuficienteException();
            }
        } else if (h=="rayo") {
            resmana=3;
            if (mana>resmana) {
                mana-=resmana;
                std::cout<<"¡¡Lanzaste un rayo!!, consumiste 3 de mana"<< std::endl;
                std::cout << "\n";
            }else {
                throw ManaInsuficienteException();
            }
        }
    }
    MagoGuerrero operator+(const MagoGuerrero& otro) const {
        int nuevaFuerza=fuerza+otro.fuerza;
        int nuevaMana=mana+otro.mana;
        return {nuevaFuerza,nuevaMana};
    }
};
int main() {
    SetConsoleOutputCP(CP_UTF8);
    try {
        Entidad* p1 = new MagoGuerrero(5,10);
        auto* mg1 = dynamic_cast<MagoGuerrero*>(p1);

        mg1->mostrarEstado();
        Entidad* p2 = new MagoGuerrero(10,20);
        auto* mg2 = dynamic_cast<MagoGuerrero*>(p2);
        MagoGuerrero mg3 = *mg1 + *mg2;
        mg3.mostrarEstado();
        mg1->atacar();
        mg1->atacar("fuego");
        mg1->mostrarEstado();
        mg1->atacar("rayo");
        mg1->mostrarEstado();
        mg1->atacar("rayo");
        delete p1;
        delete p2;
    } catch (const ManaInsuficienteException& a) {
        std::cout << a.what() << std::endl;
    }
    return 0;
}