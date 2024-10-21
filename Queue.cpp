#include "Queue.h"
#include <algorithm>

Queue::Queue(int size) {
    this->size = size;
    count = 0;
    heap = new State*[size];
}

Queue::~Queue() {
    delete[] heap;
}

void Queue::resize() {
    int newSize = size * 2;
    State** newHeap = new State*[newSize];
    for (int i = 0; i < count; i++) {
        newHeap[i] = heap[i];
    }
    delete[] heap;
    heap = newHeap;
    size = newSize;
}

void Queue::push(State* s) {
    if (count == size) {
        resize();
    }
    heap[count] = s;
    heapify_up(count);
    count++;
}

State* Queue::pop() {
    if (count == 0) {
        return nullptr;
    }
    State* minState = heap[0];
    heap[0] = heap[count - 1];
    count--;
    heapify_down(0);
    return minState;
}

void Queue::heapify_up(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index]->f() < heap[parent]->f()) {
            std::swap(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void Queue::heapify_down(int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < count && heap[leftChild]->f() < heap[smallest]->f()) {
        smallest = leftChild;
    }
    if (rightChild < count && heap[rightChild]->f() < heap[smallest]->f()) {
        smallest = rightChild;
    }
    if (smallest != index) {
        std::swap(heap[index], heap[smallest]);
        heapify_down(smallest);
    }
}

int Queue::cantidad_elementos() {
    return count;
}

bool Queue::find(State* s) {
    for (int i = 0; i < count; i++) {
        if (heap[i]->esIgual(s)) {
            return true;
        }
    }
    return false;
}
