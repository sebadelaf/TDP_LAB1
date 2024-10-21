#ifndef QUEUE_H
#define QUEUE_H

#include "State.h"

class Queue {
private:
    int size;
    int count;
    State** heap;

    void heapify_up(int index);
    void heapify_down(int index);
    void resize();

public:
    Queue(int size);
    ~Queue();

    void push(State* s);
    State* pop();
    int cantidad_elementos();
    bool find(State* s);
};

#endif // QUEUE_H
