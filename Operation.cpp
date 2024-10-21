#include "Operation.h"
#include <algorithm>

Operation::Operation(Tipo tipo, int i, int j) {
    this->tipo = tipo;
    this->i = i;
    this->j = j;
    if (tipo == LLENAR) {
        descripcion = "llenar " + std::to_string(i);
    } else if (tipo == VACIAR) {
        descripcion = "vaciar " + std::to_string(i);
    } else if (tipo == TRASVASAR) {
        descripcion = "trasvasar " + std::to_string(i) + " a " + std::to_string(j);
    }
}

State* Operation::aplicar(State* origen, const int* capacidades) {
    int* nuevoEstado = new int[origen->numRecipientes];
    for (int k = 0; k < origen->numRecipientes; k++) {
        nuevoEstado[k] = origen->recipientes[k];
    }

    if (tipo == LLENAR) {
        if (nuevoEstado[i] < capacidades[i]) {
            nuevoEstado[i] = capacidades[i];
        } else {
            delete[] nuevoEstado;
            return nullptr;
        }
    } else if (tipo == VACIAR) {
        if (nuevoEstado[i] > 0) {
            nuevoEstado[i] = 0;
        } else {
            delete[] nuevoEstado;
            return nullptr;
        }
    } else if (tipo == TRASVASAR) {
        // Asegurarse de que el trasvase funcione correctamente
        if (nuevoEstado[i] > 0 && nuevoEstado[j] < capacidades[j]) {
            int trasvasar = std::min(nuevoEstado[i], capacidades[j] - nuevoEstado[j]);
            nuevoEstado[i] -= trasvasar;
            nuevoEstado[j] += trasvasar;
        } else {
            delete[] nuevoEstado;
            return nullptr;
        }
    }

    State* nuevo = new State(origen->numRecipientes, nuevoEstado, origen, descripcion, origen->g + 1, 0);
    delete[] nuevoEstado;
    return nuevo;
}
