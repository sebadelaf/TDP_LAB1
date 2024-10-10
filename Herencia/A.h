#ifndef A_H
#define A_H
#include <iostream>

class A {
public:
    A();
    A(int a);
    int a;
    virtual int operate(int b); // Método virtual que se puede sobreescribir
};

#endif