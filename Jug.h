#include<iostream>
#include<string>
#include"Queue.h"
#include"Hash.h"
using namespace std;
class Jug{
    public:
    Queue *open; //almacena los states pendientes
    Hash *all; //almacena todos los states
    Jug(int sizeopen,int sizeall); //constructor
    //operaciones
    State* fill0(State* origen); //llena
    State* fill1(State* origen);
    State* empty0(State* origen); //vacia
    State* empty1(State* origen);
    State* transfer0(State* origen); //trasvacijar
    State* transfer1(State* origen);
    State* solve(); //retorna el estado solucion
    bool containts(State* s);
    
};