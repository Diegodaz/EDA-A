#include <iostream>
#include <vector>
#include <cmath>
#include <random>

struct Punto {
    std::vector<double> coordenadas;
};

Punto generarPuntoAleatorio(int dimensiones) {
    Punto punto;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 1.0);

    for (int i = 0; i < dimensiones; ++i) {
        punto.coordenadas.push_back(dis(gen));
    }

    return punto;
}

double calcularDistanciaEuclidiana(const Punto& p1, const Punto& p2) {
    double sumaDeCuadrados = 0.0;

    for (size_t i = 0; i < p1.coordenadas.size(); ++i) {
        double diferencia = p1.coordenadas[i] - p2.coordenadas[i];
        sumaDeCuadrados += diferencia * diferencia;
    }

    return sqrt(sumaDeCuadrados);
}

int main() {
    std::vector<int> dimensiones = {10, 50, 100, 500, 1000, 2000, 5000};

    for (int dim : dimensiones) {
        std::cout << "Dimension: " << dim << "\n";

        std::vector<Punto> puntos;
        for (int i = 0; i < 100; ++i) {
            puntos.push_back(generarPuntoAleatorio(dim));
        }

        int numPuntos = puntos.size();
        int numDistancias = (numPuntos * (numPuntos - 1)) / 2;
        std::cout << "Numero de distancias a calcular: " << numDistancias << "\n";

        int contadorDistancias = 0;

        // Calcular distancias para los primeros 5 pares de puntos
        for (int i = 0; i < std::min(numPuntos, 5); ++i) {
            for (int j = i + 1; j < std::min(numPuntos, 5); ++j) {
                double distancia = calcularDistanciaEuclidiana(puntos[i], puntos[j]);
                std::cout << "Distancia entre puntos " << i << " y " << j << ": " << distancia << "\n";
                contadorDistancias++;
            }
        }

        std::cout << "Distancias calculadas: " << contadorDistancias << "\n\n";
    }

    return 0;
}
