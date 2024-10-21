#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono> // Librería para medir el tiempo
#include "Jug.h"

// Funcion para leer el archivo de configuracion
bool leerArchivo(const std::string& nombreArchivo, int*& capacidades, int*& objetivo, int& numRecipientes) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        return false;
    }

    std::string linea;

    // Leer la primera linea (capacidades)
    if (std::getline(archivo, linea)) {
        std::istringstream ss(linea);
        numRecipientes = 0;
        int cap;
        while (ss >> cap) {
            numRecipientes++;
        }

        capacidades = new int[numRecipientes];
        ss.clear();
        ss.seekg(0, std::ios::beg);
        int i = 0;
        while (ss >> cap) {
            capacidades[i++] = cap;
        }
    }

    // Leer la segunda linea (estado objetivo)
    if (std::getline(archivo, linea)) {
        std::istringstream ss(linea);
        objetivo = new int[numRecipientes];
        for (int i = 0; i < numRecipientes; i++) {
            ss >> objetivo[i];
        }
    } else {
        std::cerr << "Error: No se encontro el estado objetivo en el archivo." << std::endl;
        delete[] capacidades;
        return false;
    }

    archivo.close();
    return true;
}

int main(int argc, char* argv[]) {
    // Verificamos si se paso el nombre del archivo por terminal
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " <archivo_de_configuracion>" << std::endl;
        return 1;
    }

    // Tomamos el archivo ingresado por terminal
    std::string nombreArchivo = argv[1];

    int* capacidades;
    int* objetivo;
    int numRecipientes;

    // Llamamos a la funcion para leer el archivo
    if (!leerArchivo(nombreArchivo, capacidades, objetivo, numRecipientes)) {
        std::cerr << "Error al leer el archivo de configuracion" << std::endl;
        return 1;
    }

    // Comenzar a medir el tiempo
    auto start = std::chrono::high_resolution_clock::now();

    // Creamos el solver y buscamos la solucion
    Jug jugSolver(1000, 1000, numRecipientes, capacidades);
    State* solucion = jugSolver.solve(objetivo);

    // Mostramos la solucion o un mensaje si no hay solucion
    if (solucion != nullptr) {
        solucion->print();
    } else {
        std::cout << "No se encontro solucion." << std::endl;
    }

    // Paramos de medir el tiempo
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    // Mostrar el tiempo de ejecucion
    std::cout << "Tiempo de ejecucion: " << elapsed.count() << " segundos." << std::endl;

    // Liberamos la memoria asignada
    delete[] capacidades;
    delete[] objetivo;

    return 0;
}
