#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <string>
using namespace std;

class State {
public:
    int a0;
    int a1;
    State *parent;
    std::string operation;

    State(int a0, int a1, State *parent, std::string operation);
    void print();
};

#endif // STATE_H
