#ifndef HASH_H
#define HASH_H

#include "State.h"

class Hash {
private:
    State** table;  // Tabla hash que almacena punteros a estados

    // Función para generar una clave única para un estado basado en sus recipientes
    int generateKey(State* state);

public:
    Hash();
    ~Hash();
    void insert(State* state);  // Insertar un estado en la tabla
    bool find(State* state);    // Buscar un estado en la tabla
};

#endif // HASH_H
