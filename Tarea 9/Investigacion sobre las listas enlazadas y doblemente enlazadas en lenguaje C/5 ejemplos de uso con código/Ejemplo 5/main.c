#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo* siguiente;
    struct Nodo* anterior;
};

void insertarInicio(struct Nodo** cabeza, int nuevoDato) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = nuevoDato;
    nuevoNodo->siguiente = *cabeza;
    nuevoNodo->anterior = NULL;

    if (*cabeza != NULL) {
        (*cabeza)->anterior = nuevoNodo;
    }

    *cabeza = nuevoNodo;
}

void imprimirLista(struct Nodo* cabeza) {
    while (cabeza != NULL) {
        printf("%d <-> ", cabeza->dato);
        cabeza = cabeza->siguiente;
    }
    printf("NULL\n");
}

int main() {
    struct Nodo* cabeza = NULL;

    insertarInicio(&cabeza, 3);
    insertarInicio(&cabeza, 2);
    insertarInicio(&cabeza, 1);

    imprimirLista(cabeza);

    return 0;
}
