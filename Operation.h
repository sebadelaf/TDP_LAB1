#ifndef OPERATION_H
#define OPERATION_H

#include "State.h"
#include <string>

class Operation {
public:
    enum Tipo { LLENAR, VACIAR, TRASVASAR };
    Tipo tipo;
    int i, j;
    std::string descripcion;

    Operation(Tipo tipo, int i, int j = -1);

    State* aplicar(State* origen, const int* capacidades);
};

#endif // OPERATION_H
