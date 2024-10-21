#include "Hash.h"
#include "State.h"
#include <cmath>

const int TABLE_SIZE = 10000;

Hash::Hash() {
    table = new State*[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = nullptr;
    }
}

Hash::~Hash() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != nullptr) {
            delete table[i];
        }
    }
    delete[] table;
}

// Generar una clave única para un estado basado en los volúmenes de los recipientes
int Hash::generateKey(State* state) {
    int key = 0;
    for (int i = 0; i < state->numRecipientes; i++) {
        key += state->recipientes[i] * pow(31, i);
    }
    return key % TABLE_SIZE;
}

// Insertar un estado en la tabla hash
void Hash::insert(State* state) {
    int key = generateKey(state);
    table[key] = state;
}

// Buscar un estado en la tabla hash
bool Hash::find(State* state) {
    int key = generateKey(state);

    if (table[key] != nullptr) {
        bool igual = true;
        for (int i = 0; i < state->numRecipientes; i++) {
            if (table[key]->recipientes[i] != state->recipientes[i]) {
                igual = false;
                break;
            }
        }
        return igual;
    }
    return false;
}
