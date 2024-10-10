#include "Jug.h"

Jug::Jug(int sizeopen,int sizeall){ //constructor para iniciar el algoritmo
    open= new Queue(sizeopen);
    all=new Hash();
    State* s=new State(0,0,nullptr,"");
    open->push(s);
    all->insert(s);
}

State* Jug::fill0(State* s){
    if(s->a0<3){
        State* s1=new State(3,s->a1,s,"llenar a0");
        return s1;
    }
    else{
        return nullptr;
    }
}

State* Jug::fill1(State* s){
    if(s->a1<5){
        State* s1=new State(s->a0,5,s,"llenar a1");
        return s1;
    }
    else{
        return nullptr;
    }
}

State* Jug::empty0(State* s){
    if(s->a0>0){
        State* s1=new State(0,s->a1,s,"vaciar a0");
        return s1;
    }
    return nullptr;
}

State* Jug::empty1(State* s){
    if(s->a1>0){
        State* s1=new State(s->a0,0,s,"vaciar a1");
        return s1;
    }
    else{
        return nullptr;
    }
}

State* Jug::transfer0(State* s) {
    // Transferir desde a0 (jarra de 3 litros) hacia a1 (jarra de 5 litros)
    if (s->a0 > 0 && s->a1 < 5) {
        int transferAmount;

        // Determinar cuánto podemos transferir: lo mínimo entre lo que tiene a0 y el espacio disponible en a1
        int availableSpaceInA1 = 5 - s->a1;

        if (s->a0 > availableSpaceInA1) {
            transferAmount = availableSpaceInA1;
        } else {
            transferAmount = s->a0;
        }

        // Creamos un nuevo estado después de la transferencia
        State* s1 = new State(s->a0 - transferAmount, s->a1 + transferAmount, s, "trasvasijar a0 a a1");
        return s1;
    }
    return nullptr;
}

State* Jug::transfer1(State* s) {
    // Transferir desde a1 (jarra de 5 litros) hacia a0 (jarra de 3 litros)
    if (s->a1 > 0 && s->a0 < 3) {
        int transferAmount;

        // Determinar cuánto podemos transferir: lo mínimo entre lo que tiene a1 y el espacio disponible en a0
        int availableSpaceInA0 = 3 - s->a0;

        if (s->a1 > availableSpaceInA0) {
            transferAmount = availableSpaceInA0;
        } else {
            transferAmount = s->a1;
        }

        // Creamos un nuevo estado después de la transferencia
        State* s1 = new State(s->a0 + transferAmount, s->a1 - transferAmount, s, "trasvasijar a1 a a0");
        return s1;
    }
    return nullptr;
}

State* Jug::solve() {
  while (open->cantidad_elementos()>0) { // mientras la cola open no este vacia
    State *s = open->pop(); // AQUI deberia sacar el mejor elemento

    if (s->a1==4) {
      return(s);
    }

    // esto nunca se deberia hacer!!!
    State *f0 = fill0(s);
    State *f1 = fill1(s);
    State *e0 = empty0(s);
    State *e1 = empty1(s);
    State *t01 = transfer0(s);
    State *t10 = transfer1(s);
    if (f0!=nullptr && !all->find(f0)) {
        open->push(f0);
        all->insert(f0);
    } else if (f0!=nullptr) { // si ya existe, lo borro
        delete(f0);
    }
    if (f1!=nullptr && !all->find(f1)) {
        open->push(f1);
        all->insert(f1);
    } else if (f1!=nullptr) { // si ya existe, lo borro
        delete(f1);
    }
    if (e0!=nullptr && !all->find(e0)) {
        open->push(e0);
        all->insert(e0);
    } else if (e0!=nullptr) { // si ya existe, lo borro
        delete(e0);
    }
    if (e1!=nullptr && !all->find(e1)) {
        open->push(e1);
        all->insert(e1);
    } else if (e1!=nullptr) { // si ya existe, lo borro
        delete(e1);
    }
    if (t01!=nullptr && !all->find(t01)) {
        open->push(t01);
        all->insert(t01);
    } else if (t01!=nullptr) { // si ya existe, lo borro
        delete(t01);
    }
    if (t10!=nullptr && !all->find(t10)) {
        open->push(t10);
        all->insert(t10);
    } else if (t10!=nullptr) { // si ya existe, lo borro
        delete(t10);
    }
  }
  return(nullptr);
}