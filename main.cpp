#include <iostream>
using namespace std;

class Persona {
public:
    string nombre;
    int edad;
    string genero;
    string tipoSangre;
    string ID;
    float altura;
    float peso;
    string personalidad;

    void saludar() {
        cout << "Hola mi nombre es " << this->nombre <<"."<< endl;
        cout << "Hola mi edad es " << this->edad <<"."<< endl;
    }

    float IMC () {
        return (this->peso) / (this->altura*this->altura);
    }

    void mostrarIMC() {
        cout << "Mi IMC es de: " << this->IMC() << endl;
    }
};

void start () {
    Persona per;
    per.saludar();
    per.nombre = "Yair";
    per.edad = 18;
    per.saludar();
    per.peso = 54;
    per.altura = 173;
    per.mostrarIMC();
}

int main() {
    start();
    return 0;
}