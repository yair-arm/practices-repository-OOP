#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <iomanip>
#include <sstream>
#include <algorithm>

std::string formatearDinero(double valor) {
    // 1. Convertimos el número a string con 2 decimales
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << valor;
    std::string str = ss.str();

    // 2. Separamos la parte entera de la decimal
    size_t puntoPos = str.find('.');
    std::string entera = str.substr(0, puntoPos);
    std::string decimal = str.substr(puntoPos); // incluye el punto

    // 3. Insertamos los puntos de miles
    const size_t n = entera.length();
    for (size_t i = n - 3; i > 0; i -= 3) {
        entera.insert(i, "."); // Cambia "." por "," si prefieres comas
    }

    return entera + decimal;
}

class Empleado {
protected:
    std::string nombre;
    std::string tipoContrato;
    double sueldoCalculado = 0.0;
public:
    Empleado(std::string nom, std::string tc) : nombre(std::move(nom)), tipoContrato(std::move(tc)) {}
    virtual ~Empleado() = default;
    virtual double calcularSalario() = 0;

    void mostrarInfo() {
        std::cout << "Nombre: " << nombre
                << "\nContrato: " << tipoContrato
                << "\nSueldo: $" << formatearDinero(calcularSalario()) << std::endl;
    }
};

class EmpleadoPlanta : public Empleado {
private:
    double sueldoFijo;
public:
    EmpleadoPlanta(const std::string& nom, double sueldo) : Empleado(nom, "De planta"), sueldoFijo(sueldo){}
    ~EmpleadoPlanta() override = default;

    double calcularSalario() override {
        sueldoCalculado = sueldoFijo;
        return sueldoCalculado;
    }
};

class EmpleadoContrato : public Empleado {
private:
    int horasATrabajar = 0;
    double valorHora = 0.0;
public:
    EmpleadoContrato(const std::string& nom, const int hor, const double valH) : Empleado(nom, "Contrato"), horasATrabajar(hor), valorHora(valH){}
    ~EmpleadoContrato() override = default;

    double calcularSalario() override {
        sueldoCalculado = horasATrabajar * valorHora;
        return sueldoCalculado;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    char opsn = 'S';
    std::string opem;
    std::string nombre;
    std::vector<Empleado*> empleados;
    while (opsn == 'S') {
        std::cout << "-------------------- BIENVENIDO A LA BASE DE DATOS DE LOS EMPLEADOS DE ESTA EMPRESA ----------------------- \n";
        std::cout << "¿Desea registrar un nuevo empleado? S/N \n";
        std::cin >> opsn;
        if (opsn == 'S') {
            std::cout << "Ingrese por favor el nombre del nuevo empleado: \t";
            std::getline(std::cin >> std::ws, nombre);
            std::cout << "¿Qué tipo de empleado desea registrar? \nde planta/contrato: \t";
            std::getline(std::cin >> std::ws, opem);
            if (opem == "de planta") {
                double salarioFijo = 0.0;
                std::cout << "Ingrese por favor el salario mensual del empleado de planta " << nombre << ": \t" << std::endl;
                std::cin >> salarioFijo;
                empleados.push_back(new EmpleadoPlanta(nombre, salarioFijo));
                std::cout << "Nuevo empleado registrado correctamente, redireccionando al inicio" << std::endl;
                std::cout << std::endl;
            } else if (opem == "contrato") {
                int horasATrabajar = 0;
                double valorHora = 0.0;
                std::cout << "¿Cuantas horas trabajará el empleado por contrato " << nombre << "? \t" << std::endl;
                std::cin >> horasATrabajar;
                std::cout << "¿Cuánto se le pagará por hora a " << nombre << "? \t" << std::endl;
                std::cin >> valorHora;
                empleados.push_back(new EmpleadoContrato(nombre, horasATrabajar, valorHora));
                std::cout << "Nuevo empleado registrado correctamente, redireccionando al inicio" << std::endl;
                std::cout << std::endl;
            } else {
                std::cout << "Ingrese una opción válida" << std::endl;
            }
        } else if (opsn == 'N') {
            std::cout << "Empleados registrados: " << std::endl;
            for (const auto & empleado : empleados) {
                empleado->mostrarInfo();
                std::cout << std::endl;
            }
            double sumaSalarios = 0;
            for (const auto & empleado : empleados) {
                sumaSalarios += empleado->calcularSalario();
            }
            std::cout << "El total a pagar de nómina para todos los empleados registrados es: $" << formatearDinero(sumaSalarios) << std::endl;
            std::cout << std::endl;
            for (const auto & empleado : empleados) {
                delete empleado;
            }
            empleados.clear();
        }
    }
    return 0;
}
