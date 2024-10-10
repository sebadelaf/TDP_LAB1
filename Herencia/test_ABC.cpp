#include "B.h"
#include "C.h"
// problema de la doble inclusión de una clase en este caso A
int main() {
    A **o = new A*[4];
    o[0] = new B(1,2);
    o[1] = new B(3,4);
    o[2] = new C(1);
    o[3] = new C(2);
    for (int k = 0; k < 4; k++) {
        std::cout<<"k:"<<k<<"operation"<<o[k]->operate(k);
    }
    return 0;
}
//esto asi no compila por el problema anteriormente mencionado por lo que se debe resolver 
//este problema con un pragma