#include "State.h"

State::State(int a0, int a1, State *parent, string operation){
    this->a0 = a0;
    this->a1= a1;
    this->parent=parent;
    this->operation= operation;
};

void State::print() {
    if (parent != nullptr) {
        parent->print();
    }
    cout << "a0: " << a0 << " a1: " << a1 << " parent: "<< parent << " operation: " << operation << endl;
}
