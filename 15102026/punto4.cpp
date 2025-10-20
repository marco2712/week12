#include <iostream>
#include <vector>
#include <omp.h>
using namespace std;

int main() {
    const int N = 5;          // número de vectores
    const int SIZE = 1000000; // tamaño de cada vector
    int valor_buscado = 42;

    vector<vector<int>> datos(N, vector<int>(SIZE, 0));
    datos[3][500000] = 42; // insertar el valor buscado en un vector

    vector<bool> encontrado(N, false);

    double inicio = omp_get_wtime();

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (datos[i][j] == valor_buscado) {
                encontrado[i] = true;
                break; // sale del vector actual
            }
        }
    }

    double fin = omp_get_wtime();

    cout << "Resultado de búsqueda:\n";
    for (int i = 0; i < N; i++)
        cout << "Vector " << i << ": " << (encontrado[i] ? "Encontrado" : "No encontrado") << endl;

    cout << "Tiempo total: " << fin - inicio << " segundos\n";
    return 0;
}
