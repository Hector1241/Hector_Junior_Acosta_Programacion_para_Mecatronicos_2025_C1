#include <stdio.h>

/*
    Funci�n: hanoi
    ------------------------
    Resuelve recursivamente el problema de la Torre de Hanoi.

    Par�metros:
        n: N�mero de discos a mover.
        origen: Torre de origen (A).
        auxiliar: Torre auxiliar (B).
        destino: Torre destino (C).
*/
void hanoi(int n, char origen, char auxiliar, char destino) {
    if (n == 1) {
        // Caso base: mover un solo disco directamente al destino.
        printf("Mover disco 1 desde la torre %c a la torre %c\n", origen, destino);
        return;
    }

    // Paso 1: mover n-1 discos del origen al auxiliar.
    hanoi(n - 1, origen, destino, auxiliar);

    // Paso 2: mover el disco restante al destino.
    printf("Mover disco %d desde la torre %c a la torre %c\n", n, origen, destino);

    // Paso 3: mover los n-1 discos desde el auxiliar al destino.
    hanoi(n - 1, auxiliar, origen, destino);
}

int main() {
    int num_discos;

    // Solicitar al usuario la cantidad de discos.
    printf("Ingrese la cantidad de discos: ");
    scanf("%d", &num_discos);

    printf("\n--- Soluci�n de la Torre de Hanoi para %d discos ---\n\n", num_discos);

    // Llamada inicial a la funci�n recursiva.
    hanoi(num_discos, 'A', 'B', 'C');

    return 0;
}
