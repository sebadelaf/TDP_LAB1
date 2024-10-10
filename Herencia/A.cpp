#include "A.h"
A::A(){
    this->a=1;
}
A::A(int a) { this->a = a; }

int A::operate(int b) { return a + b; }

