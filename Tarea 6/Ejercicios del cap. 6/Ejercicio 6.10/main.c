#include <stdio.h>

#define MAX 50  // Definición de la constante MAX

void Cuadrado(int A[][MAX], int N);
void Imprime(int A[][MAX], int N);

int main(void) {
    int CMA[MAX][MAX] = {0};  // Inicializar la matriz en 0
    int TAM;

    do {
        printf("Ingrese el tamaño impar de la matriz: ");
        scanf("%d", &TAM);
    } while ((TAM > MAX || TAM < 1) || (TAM % 2 == 0));
    // Se verifica que sea impar y dentro del rango permitido

    Cuadrado(CMA, TAM);
    Imprime(CMA, TAM);

    return 0;
}

void Cuadrado(int A[][MAX], int N) {
    /* Esta función genera un cuadrado mágico. */
    int I = 1, FIL = 0, COL = N / 2, NUM = N * N;

    while (I <= NUM) {
        A[FIL][COL] = I;

        if (I % N != 0) {
            FIL = (FIL - 1 + N) % N;
            COL = (COL + 1) % N;
        } else {
            FIL++;
        }
        I++;
    }
}

void Imprime(int A[][MAX], int N) {
    /* Esta función imprime el cuadrado mágico en formato de matriz. */
    int I, J;
    printf("\nCuadrado mágico de orden %d:\n", N);

    for (I = 0; I < N; I++) {
        for (J = 0; J < N; J++) {
            printf("%4d ", A[I][J]);
        }
        printf("\n");
    }
}
