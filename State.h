#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <string>

class State {
public:
    int* recipientes;
    int numRecipientes;
    State* parent;
    std::string operation;
    int g;
    int h;

    State(int numRecipientes, int* inicial, State* parent, std::string operation, int g, int h);
    ~State();

    int f() const { return g + h; }

    static int calcularHeuristica(int* estadoActual, int* objetivo, int numRecipientes, int* capacidades);

    bool operator<(const State& other) const { return this->f() > other.f(); }

    bool esIgual(State* otroEstado);

    void print();
};

#endif // STATE_H
