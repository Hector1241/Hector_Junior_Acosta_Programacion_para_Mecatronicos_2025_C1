#include <stdio.h>

#define MAX 50  // Definici�n de la constante MAX

void Cuadrado(int A[][MAX], int N);
void Imprime(int A[][MAX], int N);

int main(void) {
    int CMA[MAX][MAX] = {0};  // Inicializar la matriz en 0
    int TAM;

    do {
        printf("Ingrese el tama�o impar de la matriz: ");
        scanf("%d", &TAM);
    } while ((TAM > MAX || TAM < 1) || (TAM % 2 == 0));
    // Se verifica que sea impar y dentro del rango permitido

    Cuadrado(CMA, TAM);
    Imprime(CMA, TAM);

    return 0;
}

void Cuadrado(int A[][MAX], int N) {
    /* Esta funci�n genera un cuadrado m�gico. */
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
    /* Esta funci�n imprime el cuadrado m�gico en formato de matriz. */
    int I, J;
    printf("\nCuadrado m�gico de orden %d:\n", N);

    for (I = 0; I < N; I++) {
        for (J = 0; J < N; J++) {
            printf("%4d ", A[I][J]);
        }
        printf("\n");
    }
}
