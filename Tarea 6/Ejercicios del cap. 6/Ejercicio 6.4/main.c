#include <stdio.h>

/* Simétrico.
   El programa, al recibir como dato un arreglo bidimensional cuadrado,
   determina si el mismo es simétrico. */

#define MAX 100  // Tamaño máximo del arreglo

// Prototipos de funciones
void Lectura(int [][MAX], int);
int Simetrico(int [][MAX], int);

int main(void) {
    int MAT[MAX][MAX], N, RES;

    // Validación del tamaño de la matriz
    do {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &N);
    } while (N > MAX || N < 1);

    Lectura(MAT, N);
    RES = Simetrico(MAT, N);

    if (RES)
        printf("\nEl arreglo bidimensional es simétrico\n");
    else
        printf("\nEl arreglo bidimensional no es simétrico\n");

    return 0;
}

void Lectura(int A[][MAX], int T) {
    /* La función Lectura se utiliza para leer un arreglo bidimensional cuadrado de
       tipo entero de T filas y T columnas. */

    int I, J;
    for (I = 0; I < T; I++)
        for (J = 0; J < T; J++) {
            printf("Fila: %d\tColumna: %d: ", I + 1, J + 1);
            scanf("%d", &A[I][J]);
        }
}

int Simetrico(int A[][MAX], int T) {
    /* La función Simétrico se utiliza para determinar si el arreglo bidimensional
       cuadrado es simétrico. Si es simétrico regresa 1, en caso contrario, 0.
       Observa que en el segundo ciclo solamente se recorre la matriz triangular
       inferior, sin la diagonal principal. */

    int I = 0, J, F = 1;

    while ((I < T) && F) {
        J = 0;
        while ((J < I) && F) {
            if (A[I][J] != A[J][I])
                F = 0;
            J++;
        }
        I++;
    }
    return F;
}
