#include "Queue.h"

int main(){

    Queue *q = new Queue(2);

    State *s = new State(0,0,nullptr,"init");
    q->push(s);

    State *s1 = new State(3,0,s,"fill a0");

    q->push(s1);

    State *s2 = new State(3,5,s1,"fill a1");

    q->push(s2);

    State *s3 = new State(0,5,s2,"pour a0");

    q->push(s3);

    cout << "Size: " << q->cantidad_elementos() << endl;

    while(q->cantidad_elementos() > 0){
    	cout << "Size: " << q->cantidad_elementos() << endl;
        State *s = q->pop();
        if(s != nullptr){
        	cout << s->a0 << s->a1 <<endl;
        }
    }
    return 0;
}
