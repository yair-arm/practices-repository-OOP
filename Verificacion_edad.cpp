#include <iostream>
using namespace std;

class Evento {
public:
    void VerificarEdad(int edad) {
        try {
            if (edad < 0) {
                throw invalid_argument("La edad no puede ser negativa");
            }
            if (edad < 18) {
                throw logic_error("La edad no puede ser menor a 18");
            } cout << "Bienvenido al evento!" << endl;
        } catch (const std::invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
        } catch (const std::logic_error& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
};

int main() {
    Evento evento;
    int edad;
    cout << "Ingrese su edad" << endl;
    cin >> edad;
    evento.VerificarEdad(edad);
}