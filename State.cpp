#include "State.h"
#include <cmath>

State::State(int numRecipientes, int* inicial, State* parent, std::string operation, int g, int h) {
    this->numRecipientes = numRecipientes;
    this->recipientes = new int[numRecipientes];
    for (int i = 0; i < numRecipientes; i++) {
        this->recipientes[i] = inicial[i];
    }
    this->parent = parent;
    this->operation = operation;
    this->g = g;
    this->h = h;
}

State::~State() {
    delete[] recipientes;
}

// Heurística optimizada
int State::calcularHeuristica(int* estadoActual, int* objetivo, int numRecipientes, int* capacidades) {
    int h = 0;

    for (int i = 0; i < numRecipientes; i++) {
        int diferencia = std::abs(estadoActual[i] - objetivo[i]);

        if (diferencia > 0) {
            // Añadimos el coste básico de la diferencia
            h += diferencia;

            // Penalizar recipientes que no están contribuyendo si están llenos o vacíos
            if (estadoActual[i] == 0 && objetivo[i] > 0) {
                h += 2; // Penaliza recipientes vacíos que deberían estar llenos
            } else if (estadoActual[i] == capacidades[i] && objetivo[i] < capacidades[i]) {
                h += 2; // Penaliza recipientes llenos innecesariamente
            }

            // Considerar trasvases efectivos entre recipientes
            for (int j = 0; j < numRecipientes; j++) {
                if (i != j && capacidades[j] >= diferencia) {
                    h -= 1; // Descuento en la heurística porque un trasvase es posible
                    break;
                }
            }

            // Priorizamos recipientes que pueden contener el objetivo exacto
            if (capacidades[i] >= objetivo[i] && capacidades[i] < 2 * objetivo[i]) {
                h -= 1; // Reduce la heurística si el recipiente es crítico
            }
        }
    }

    return h;
}

bool State::esIgual(State* otroEstado) {
    for (int i = 0; i < numRecipientes; i++) {
        if (this->recipientes[i] != otroEstado->recipientes[i]) {
            return false;
        }
    }
    return true;
}

void State::print() {
    if (parent != nullptr) {
        parent->print();
    }
    std::cout << "Recipientes: ";
    for (int i = 0; i < numRecipientes; i++) {
        std::cout << recipientes[i] << " ";
    }
    std::cout << " Operacion: " << operation << " Coste: g=" << g << ", h=" << h << ", f=" << f() << std::endl;
}
