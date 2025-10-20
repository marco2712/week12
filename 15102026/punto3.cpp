#include <iostream>
#include <vector>
#include <omp.h>
using namespace std;

int main() {
    const int N = 5;          // número de vectores
    const int SIZE = 1000000; // tamaño de cada vector
    vector<vector<int>> datos(N, vector<int>(SIZE, 1)); // inicializa con 1
    vector<long long> suma(N, 0);

    double inicio = omp_get_wtime();

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        long long local_sum = 0;
        for (int j = 0; j < SIZE; j++) {
            local_sum += datos[i][j];
        }
        suma[i] = local_sum;
    }

    double fin = omp_get_wtime();

    cout << "Suma total por vector:\n";
    for (int i = 0; i < N; i++)
        cout << "Vector " << i << ": " << suma[i] << endl;

    cout << "Tiempo total: " << fin - inicio << " segundos\n";
    return 0;
}
