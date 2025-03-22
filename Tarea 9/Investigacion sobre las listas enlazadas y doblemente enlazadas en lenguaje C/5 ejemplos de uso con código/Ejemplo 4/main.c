#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo* siguiente;
    struct Nodo* anterior;
};

void imprimirAdelante(struct Nodo* cabeza) {
    while (cabeza != NULL) {
        printf("%d <-> ", cabeza->dato);
        cabeza = cabeza->siguiente;
    }
    printf("NULL\n");
}

void imprimirAtras(struct Nodo* cola) {
    while (cola != NULL) {
        printf("%d <-> ", cola->dato);
        cola = cola->anterior;
    }
    printf("NULL\n");
}

int main() {
    struct Nodo* cabeza = NULL;
    struct Nodo* segundo = NULL;
    struct Nodo* tercero = NULL;

    cabeza = (struct Nodo*)malloc(sizeof(struct Nodo));
    segundo = (struct Nodo*)malloc(sizeof(struct Nodo));
    tercero = (struct Nodo*)malloc(sizeof(struct Nodo));

    cabeza->dato = 1;
    cabeza->siguiente = segundo;
    cabeza->anterior = NULL;

    segundo->dato = 2;
    segundo->siguiente = tercero;
    segundo->anterior = cabeza;

    tercero->dato = 3;
    tercero->siguiente = NULL;
    tercero->anterior = segundo;

    imprimirAdelante(cabeza);
    imprimirAtras(tercero);

    free(cabeza);
    free(segundo);
    free(tercero);

    return 0;
}
