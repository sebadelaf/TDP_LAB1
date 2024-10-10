#include "A.h"

class B : public A {
    public:
    int b;
    B(int a, int b);
    void print();
    int operate(int b); // virtual indica que genere una tabla de
                        // metodos que sobreescriba, tabla de metodos
};