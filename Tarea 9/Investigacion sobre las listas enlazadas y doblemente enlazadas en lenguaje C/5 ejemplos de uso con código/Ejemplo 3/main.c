#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

void eliminarNodo(struct Nodo** cabeza, int valor) {
    struct Nodo* temp = *cabeza, *prev = NULL;

    if (temp != NULL && temp->dato == valor) {
        *cabeza = temp->siguiente;
        free(temp);
        return;
    }

    while (temp != NULL && temp->dato != valor) {
        prev = temp;
        temp = temp->siguiente;
    }

    if (temp == NULL) return;

    prev->siguiente = temp->siguiente;
    free(temp);
}

void imprimirLista(struct Nodo* cabeza) {
    while (cabeza != NULL) {
        printf("%d -> ", cabeza->dato);
        cabeza = cabeza->siguiente;
    }
    printf("NULL\n");
}

int main() {
    struct Nodo* cabeza = NULL;
    cabeza = (struct Nodo*)malloc(sizeof(struct Nodo));
    cabeza->dato = 1;
    cabeza->siguiente = (struct Nodo*)malloc(sizeof(struct Nodo));
    cabeza->siguiente->dato = 2;
    cabeza->siguiente->siguiente = (struct Nodo*)malloc(sizeof(struct Nodo));
    cabeza->siguiente->siguiente->dato = 3;
    cabeza->siguiente->siguiente->siguiente = NULL;

    imprimirLista(cabeza);

    eliminarNodo(&cabeza, 2);
    imprimirLista(cabeza);

    return 0;
}
