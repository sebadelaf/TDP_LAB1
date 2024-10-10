#ifndef HASH_H
#define HASH_H

#include "State.h"
#include <iostream>
#include <string>
using namespace std;

#define SIZE 1000000

class Hash {
public:
    State *table[SIZE]; 
    Hash();
    void insert(State* state);
    bool find(State* state);
    void clear();
    ~Hash();
};

#endif // HASH_H
