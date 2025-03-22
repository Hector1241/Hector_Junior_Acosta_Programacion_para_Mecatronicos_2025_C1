#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

void imprimirLista(struct Nodo* cabeza) {
    while (cabeza != NULL) {
        printf("%d -> ", cabeza->dato);
        cabeza = cabeza->siguiente;
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

    segundo->dato = 2;
    segundo->siguiente = tercero;

    tercero->dato = 3;
    tercero->siguiente = NULL;

    imprimirLista(cabeza);

    free(cabeza);
    free(segundo);
    free(tercero);

    return 0;
}
