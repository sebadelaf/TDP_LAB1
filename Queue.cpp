#include "Queue.h"
//define constructor sin argumentos
Queue::Queue(){
    arr = nullptr;
    front = -1;
    back = -1;
    size = -1;
}
//define constructor con el arreglo de tamaño n
Queue::Queue(int n){
    arr = new State*[n];  // Crear arreglo de punteros a State de tamaño n
    size = n;
    front = -1;
    back = -1;
}
//indica la cantidad de elementos de la cola
int Queue::cantidad_elementos() {
    // Caso vacío
    if (front == -1 && back == -1) return 0;
    // Un solo bloque de elementos
    if (back >= front) return back - front + 1;
    // Caso en el que el back está antes del front
    else return size - front + back + 1;
}
//elimina y retorna un elemento de la cola
State* Queue::pop() {
    if (front == -1 && back == -1) return nullptr;  // Si está vacía
    else {
        State* s = arr[front];  // Obtenemos el elemento en la posición front
        // Caso en el que hay solo un elemento
        if (cantidad_elementos() == 1) {
            front = back = -1;  // Vaciamos la cola
        }
        else if (front == size - 1) {
            front = 0;  // Caso circular, regresamos al inicio
        }
        else {
            front++;  // Avanzamos el front
        }
        return s;  // Retornamos el elemento
    }
}

void Queue::push(State* s) {
    if (cantidad_elementos() == size) {
        // Duplicamos el tamaño
        State** arr_temp = new State*[size * 2];
        int j = 0;  // Índice para el nuevo arreglo

        // Copiamos todos los elementos en una sola pasada
        for (int i = front; i != back; i = (i + 1) % size) {
            arr_temp[j++] = arr[i];
        }
        arr_temp[j++] = arr[back];  // Copiamos el último elemento (back)

        // Ajustamos front y back al nuevo arreglo
        front = 0;
        back = size - 1;
        size = size * 2;
        delete[] arr;
        arr = arr_temp;
    }

    // Inserción del nuevo elemento
    if (front == -1 && back == -1) {
        front = back = 0;
    } else if (back == size - 1) {
        back = 0;
    } else {
        back++;
    }

    arr[back] = s;
}


bool Queue::find(State* s) {
    if (front==-1 && back==-1) {
        return (false);
    }
    if (back>=front) {
        for(int k=front; k<=back; k++){
            if(arr[k]->a0==s->a0 && arr[k]->a1==s->a1) {
                return true;
            }
        }
    } else {
        for(int k=front; k<=size-1; k++){
            if(arr[k]->a0==s->a0 && arr[k]->a1==s->a1) {
                return true;
            }
        }
        for(int k=0; k<=back; k++) {
            if(arr[k]->a0==s->a0 && arr[k]->a1==s->a1) {
                return true;
            }
        }
    }
    return (false);
}
