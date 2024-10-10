#include "B.h"
using namespace std;

B::B(int a, int b) {
    this->a = a;
    this->b = b;
}

void B::print() {
    cout << "a:" << a << " b:" << b << endl; // Corregido para imprimir correctamente los valores
}

int B::operate(int x) {
    return a + b + x;
}