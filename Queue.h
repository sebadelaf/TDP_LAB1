#ifndef QUEUE_H
#define QUEUE_H

#include "State.h"

class Queue {
public:
    int front;
    int back;
    int size;
    State **arr;

    void push(State *s);
    State *pop();
    bool find(State *s);
    Queue(); 
    Queue(int size);
    int cantidad_elementos();
};

#endif // QUEUE_H
