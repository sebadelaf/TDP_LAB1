#include "Jug.h"
#include "Hash.h"

Jug::Jug(int sizeopen, int sizeall, int numRecipientes, int* capacidades) {
    this->numRecipientes = numRecipientes;
    this->capacidades = capacidades;
    open = new Queue(sizeopen);
    all = new Hash();

    // Crear el estado inicial (todos los recipientes vacios)
    int* inicial = new int[numRecipientes]();
    int h = State::calcularHeuristica(inicial, inicial, numRecipientes, capacidades);
    State* s = new State(numRecipientes, inicial, nullptr, "", 0, h);
    open->push(s);
    all->insert(s);
    delete[] inicial;

    capacidadOperaciones = 10;
    totalOperaciones = 0;
    operaciones = new Operation*[capacidadOperaciones];

    // Inicializar las operaciones
    for (int i = 0; i < numRecipientes; i++) {
        agregarOperacion(new Operation(Operation::LLENAR, i));
        agregarOperacion(new Operation(Operation::VACIAR, i));
        for (int j = 0; j < numRecipientes; j++) {
            if (i != j) {
                agregarOperacion(new Operation(Operation::TRASVASAR, i, j));
            }
        }
    }
}

Jug::~Jug() {
    for (int i = 0; i < totalOperaciones; i++) {
        delete operaciones[i];
    }
    delete[] operaciones;
    delete open;
    delete all;
}

void Jug::agregarOperacion(Operation* op) {
    if (totalOperaciones == capacidadOperaciones) {
        int nuevaCapacidad = capacidadOperaciones * 2;
        Operation** nuevoArreglo = new Operation*[nuevaCapacidad];
        for (int i = 0; i < totalOperaciones; i++) {
            nuevoArreglo[i] = operaciones[i];
        }
        delete[] operaciones;
        operaciones = nuevoArreglo;
        capacidadOperaciones = nuevaCapacidad;
    }
    operaciones[totalOperaciones++] = op;
}

State* Jug::solve(int* objetivo) {
    while (open->cantidad_elementos() > 0) {
        State* s = open->pop();

        // Verificar si alcanzamos el estado objetivo
        bool esObjetivo = true;
        for (int i = 0; i < numRecipientes; i++) {
            if (s->recipientes[i] != objetivo[i]) {
                esObjetivo = false;
                break;
            }
        }
        if (esObjetivo) {
            return s;
        }

        // Aplicar todas las operaciones a partir del estado actual
        for (int i = 0; i < totalOperaciones; i++) {
            State* nuevoEstado = operaciones[i]->aplicar(s, capacidades);
            if (nuevoEstado != nullptr && !all->find(nuevoEstado)) {
                nuevoEstado->g = s->g + 1;
                nuevoEstado->h = State::calcularHeuristica(nuevoEstado->recipientes, objetivo, numRecipientes, capacidades);
                open->push(nuevoEstado);
                all->insert(nuevoEstado);
            } else {
                delete nuevoEstado;  // Liberar memoria si el estado no es necesario
            }
        }
    }
    return nullptr;
}
