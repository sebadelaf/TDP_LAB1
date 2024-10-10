#include "Hash.h"

// Constructor
Hash::Hash(){
    for(int i = 0; i < SIZE; i++){
        table[i] = NULL;
    }
}
// Funcion que inserta un state en la tabla
void Hash::insert(State* state){
    int key = state->a0 * 1000 + state->a1; //key es la suma de a0 y a1
    while(table[key] != NULL){ //mientras la tabla en la posicion key no sea nula
        key = (key + 1) % SIZE; //key es igual a la suma de key y 1 modulo SIZE
    }
    table[key] = state; //la tabla en la posicion key es igual a state
}
// Funcion que busca un state en la tabla
bool Hash::find(State* state){
    int key = state->a0 * 1000 + state->a1; //key es la suma de a0 y a1
    while(table[key] != NULL){ //mientras la tabla en la posicion key no sea nula
        if(table[key]->a0 == state->a0 && table[key]->a1 == state->a1){ //si la tabla en la posicion key es igual a state
            return true; //retorna verdadero
        }
        key = (key + 1) % SIZE; //key es igual a la suma de key y 1 modulo SIZE
    }
    return false; //retorna falso
}

void Hash::clear(){
    for(int i = 0; i < SIZE; i++){ //para i desde 0 hasta SIZE
        if(table[i] != NULL){ //si la tabla en la posicion i no es nula
            delete table[i]; //borra la tabla en la posicion i
        }
    }
}


