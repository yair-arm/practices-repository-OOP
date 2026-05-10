/*
 * NominaV2.cpp — Sistema de Nómina (versión mejorada)
 *
 * Mejoras respecto a Nomina.cpp:
 *  1. Smart pointers (unique_ptr) para manejo automático de memoria (RAII).
 *  2. Bug de underflow en formatearDinero() corregido para valores < 1000.
 *  3. Encabezado impreso una sola vez, fuera del bucle.
 *  4. Validación robusta de entradas numéricas y de opción S/N.
 *  5. Comparación case-insensitive del tipo de empleado.
 *  6. calcularSalario() marcado como const (no modifica el objeto).
 *  7. Atributo redundante 'sueldoCalculado' eliminado de la clase base.
 *  8. Manejo del caso en que se finaliza sin haber registrado empleados.
 *  9. Pausa al final para que el usuario lea el resumen antes de cerrar.
 */

#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <memory>    // std::unique_ptr, std::make_unique
#include <limits>    // std::numeric_limits

// ─── Utilidades ───────────────────────────────────────────────────────────────

/**
 * Formatea un valor double como dinero con separadores de miles.
 * Corrección: se usa 'int' en lugar de 'size_t' para el índice del bucle,
 * evitando el underflow que ocurría cuando la parte entera tenía < 3 dígitos.
 */
std::string formatearDinero(double valor) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << valor;
    std::string str = ss.str();

    size_t puntoPos = str.find('.');
    std::string entera  = str.substr(0, puntoPos);
    std::string decimal = str.substr(puntoPos); // incluye el punto

    int n = static_cast<int>(entera.length());
    for (int i = n - 3; i > 0; i -= 3) {
        entera.insert(static_cast<size_t>(i), ".");
    }

    return entera + decimal;
}

/**
 * Lee un valor numérico de tipo T desde la entrada estándar.
 * Repite la solicitud hasta recibir un número positivo válido,
 * evitando que el programa quede en un estado de error indefinido.
 */
template <typename T>
T leerNumero(const std::string& prompt) {
    T valor;
    while (true) {
        std::cout << prompt;
        if (std::cin >> valor && valor > 0) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return valor;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  [!] Entrada invalida. Ingrese un numero positivo.\n";
    }
}

/** Convierte un string a minúsculas para comparación case-insensitive. */
std::string aMinusculas(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

// ─── Jerarquía de clases ──────────────────────────────────────────────────────

class Empleado {
protected:
    std::string nombre;
    std::string tipoContrato;
public:
    Empleado(std::string nom, std::string tc)
        : nombre(std::move(nom)), tipoContrato(std::move(tc)) {}

    virtual ~Empleado() = default;

    // Marcado const: calcular el salario no debe modificar el estado del objeto.
    [[nodiscard]] virtual double calcularSalario() const = 0;

    void mostrarInfo() const {
        std::cout << "  Nombre  : " << nombre
                  << "\n  Contrato: " << tipoContrato
                  << "\n  Sueldo  : $" << formatearDinero(calcularSalario())
                  << "\n";
    }

    [[nodiscard]] const std::string& getNombre() const { return nombre; }
};

class EmpleadoPlanta : public Empleado {
private:
    double sueldoFijo;
public:
    EmpleadoPlanta(const std::string& nom, double sueldo)
        : Empleado(nom, "De planta"), sueldoFijo(sueldo) {}

    ~EmpleadoPlanta() override = default;

    [[nodiscard]] double calcularSalario() const override {
        return sueldoFijo;
    }
};

class EmpleadoContrato : public Empleado {
private:
    int    horasATrabajar;
    double valorHora;
public:
    EmpleadoContrato(const std::string& nom, int hor, double valH)
        : Empleado(nom, "Contrato"), horasATrabajar(hor), valorHora(valH) {}

    ~EmpleadoContrato() override = default;

    [[nodiscard]] double calcularSalario() const override {
        return horasATrabajar * valorHora;
    }
};

// ─── Programa principal ───────────────────────────────────────────────────────

int main() {
    SetConsoleOutputCP(CP_UTF8);

    // unique_ptr gestiona la memoria automáticamente; no se necesita delete manual.
    std::vector<std::unique_ptr<Empleado>> empleados;
    char opcion;

    // El encabezado se muestra una sola vez, antes del bucle.
    std::cout << "========================================================\n"
              << "      BIENVENIDO AL SISTEMA DE NOMINA DE LA EMPRESA\n"
              << "========================================================\n\n";

    do {
        std::cout << "Empleados registrados: " << empleados.size() << "\n";
        std::cout << "Desea registrar un nuevo empleado? (S/N): ";
        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        opcion = static_cast<char>(toupper(opcion)); // acepta 's' y 'n' también

        if (opcion == 'S') {
            std::string nombre, tipoEmpleado;

            std::cout << "\nIngrese el nombre del empleado: ";
            std::getline(std::cin, nombre);

            std::cout << "Tipo de empleado (de planta / contrato): ";
            std::getline(std::cin, tipoEmpleado);
            tipoEmpleado = aMinusculas(tipoEmpleado); // normaliza la entrada

            if (tipoEmpleado == "de planta") {
                auto salario = leerNumero<double>("Salario mensual fijo: $");
                empleados.push_back(std::make_unique<EmpleadoPlanta>(nombre, salario));
                std::cout << "[OK] Empleado de planta registrado correctamente.\n\n";

            } else if (tipoEmpleado == "contrato") {
                int    horas     = leerNumero<int>   ("Horas a trabajar    : ");
                auto valorHora = leerNumero<double>("Valor por hora      : $");
                empleados.push_back(std::make_unique<EmpleadoContrato>(nombre, horas, valorHora));
                std::cout << "[OK] Empleado por contrato registrado correctamente.\n\n";

            } else {
                std::cout << "[!] Tipo invalido. Ingrese exactamente \"de planta\" o \"contrato\".\n\n";
            }

        } else if (opcion != 'N') {
            // Valida que la opción sea S o N; si no, advierte y vuelve a preguntar.
            std::cout << "[!] Opcion invalida. Ingrese S o N.\n\n";
        }

    } while (opcion != 'N');

    // ── Resumen final de nómina ───────────────────────────────────────────────
    std::cout << "\n========================================================\n"
              << "                  RESUMEN DE NOMINA\n"
              << "========================================================\n";

    if (empleados.empty()) {
        std::cout << "No se registro ningun empleado.\n";
    } else {
        double totalNomina = 0.0;
        for (const auto& emp : empleados) {
            emp->mostrarInfo();
            totalNomina += emp->calcularSalario();
            std::cout << "  ─────────────────────────────────────────────\n";
        }
        std::cout << "\n  TOTAL A PAGAR DE NOMINA: $" << formatearDinero(totalNomina) << "\n";
    }

    std::cout << "========================================================\n"
              << "Presione Enter para salir...";
    std::cin.get(); // pausa para que el usuario lea antes de cerrar

    return 0;
    // Al salir de main, el vector se destruye y todos los unique_ptr
    // liberan su memoria automáticamente. No se necesita delete ni clear().
}
