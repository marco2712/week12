#include <iostream>
#include <vector>
#include <omp.h>
using namespace std;

// Simula aplicar un filtro (invertir valores)
void aplicarFiltro(vector<vector<int>>& imagen) {
    int filas = imagen.size();
    int columnas = imagen[0].size();

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            imagen[i][j] = 255 - imagen[i][j]; // inversión del color
        }
    }
}

int main() {
    const int NUM_IMAGENES = 4;
    const int FILAS = 1000, COLUMNAS = 1000;

    vector<vector<vector<int>>> imagenes(NUM_IMAGENES, vector<vector<int>>(FILAS, vector<int>(COLUMNAS, 128)));

    double inicio = omp_get_wtime();

    #pragma omp parallel for
    for (int i = 0; i < NUM_IMAGENES; i++) {
        aplicarFiltro(imagenes[i]);
        // Aquí podrías simular "guardar" la imagen procesada
    }

    double fin = omp_get_wtime();

    cout << "Se aplicó el filtro a " << NUM_IMAGENES << " imágenes en " << fin - inicio << " segundos.\n";
    return 0;
}
