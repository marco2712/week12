#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>
using namespace std;

int main() {
    const int NUM_OBJETOS = 5;
    const double g = 9.81; // gravedad
    vector<double> alturas = {10.0, 25.5, 50.0, 75.0, 100.0};
    vector<double> tiempos(NUM_OBJETOS, 0.0);

    double inicio = omp_get_wtime();

    #pragma omp parallel for
    for (int i = 0; i < NUM_OBJETOS; i++) {
        tiempos[i] = sqrt((2 * alturas[i]) / g);
    }

    double fin = omp_get_wtime();

    cout << "Tiempos de caída libre:\n";
    for (int i = 0; i < NUM_OBJETOS; i++) {
        cout << "Objeto " << i + 1 << " (altura = " << alturas[i] << " m): "
             << tiempos[i] << " s\n";
    }

    cout << "Tiempo total de ejecución: " << fin - inicio << " segundos\n";
    return 0;
}
