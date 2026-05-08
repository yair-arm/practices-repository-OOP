#include <iostream>
using namespace std;

#define N 3   // tamaño de la matriz

class Matriz {
private:
    int mat[N][N];   // los datos están encapsulados aquí
    int filas;
    int columnas;

public:
    // Constructor: inicializa tamaño y pone todo en cero
    Matriz(int f = N, int c = N) {
        filas = f;
        columnas = c;
        for (int i = 0; i < filas; i++)
            for (int j = 0; j < columnas; j++)
                mat[i][j] = 0;
    }

    // Método: llenar la matriz con datos del usuario
    void llenar() {
        cout << "Ingresa los " << filas * columnas << " elementos:\n";
        for (int i = 0; i < filas; i++)
            for (int j = 0; j < columnas; j++) {
                cout << "mat[" << i << "][" << j << "]: ";
                cin >> mat[i][j];
            }
    }

    // Método: mostrar la matriz en pantalla
    void mostrar() {
        cout << "\n";
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++)
                cout << mat[i][j] << "\t";
            cout << "\n";
        }
    }

    // Método: multiplicar esta matriz por otra, retorna el resultado
    Matriz multiplicar(Matriz& B) {
        Matriz C;   // matriz resultado, empieza en cero
        for (int i = 0; i < filas; i++)
            for (int j = 0; j < B.columnas; j++)
                for (int k = 0; k < columnas; k++)
                    C.mat[i][j] += mat[i][k] * B.mat[k][j];
        return C;
    }
};

int main() {
    Matriz A, B, C;

    cout << "=== Matriz A ===\n";
    A.llenar();
    cout << "\n=== Matriz B ===\n";
    B.llenar();

    C = A.multiplicar(B);

    cout << "\n=== Matriz A ===";
    A.mostrar();
    cout << "\n=== Matriz B ===";
    B.mostrar();
    cout << "\n=== A x B ===";
    C.mostrar();

    return 0;
}