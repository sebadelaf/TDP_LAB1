#ifndef JUG_H
#define JUG_H

    #include "Queue.h"
#include "Hash.h"
#include "Operation.h"

class Jug {
public:
    Queue* open;
    Hash* all;
    int numRecipientes;
    int* capacidades;
    Operation** operaciones;
    int totalOperaciones;
    int capacidadOperaciones;

    Jug(int sizeopen, int sizeall, int numRecipientes, int* capacidades);
    ~Jug();

    State* solve(int* objetivo);
    void agregarOperacion(Operation* op);
};

#endif // JUG_H
