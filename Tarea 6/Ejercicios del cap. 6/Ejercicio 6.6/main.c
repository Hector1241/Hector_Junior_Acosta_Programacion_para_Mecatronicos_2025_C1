#include <stdio.h>

#define MAX 50

void Lectura(float A[][MAX], int F, int C);
void Intercambia(float A[][MAX], int F, int C);
void Imprime(float A[][MAX], int F, int C);

int main(void) {
    int F, C;
    float MAT[MAX][MAX];

    do {
        printf("Ingrese el número de filas: ");
        scanf("%d", &F);
    } while (F > MAX || F < 1);  // Verifica que el número de filas sea correcto.

    do {
        printf("Ingrese el número de columnas: ");
        scanf("%d", &C);
    } while (C > MAX || C < 1);  // Verifica que el número de columnas sea correcto.

    Lectura(MAT, F, C);
    Intercambia(MAT, F, C);
    Imprime(MAT, F, C);

    return 0;
}

void Lectura(float A[][MAX], int F, int C) {
    // Esta función lee una matriz de F filas y C columnas.
    int I, J;
    for (I = 0; I < F; I++) {
        for (J = 0; J < C; J++) {
            printf("Ingrese el elemento [%d, %d]: ", I + 1, J + 1);
            scanf("%f", &A[I][J]);
        }
    }
}

void Intercambia(float A[][MAX], int F, int C) {
    // Esta función intercambia las columnas de la matriz.
    int I, J;
    float AUX;
    for (I = 0; I < C / 2; I++) {
        for (J = 0; J < F; J++) {
            AUX = A[J][I];
            A[J][I] = A[J][C - I - 1];
            A[J][C - I - 1] = AUX;
        }
    }
}

void Imprime(float A[][MAX], int F, int C) {
    // Esta función imprime la matriz después de los intercambios.
    int I, J;
    printf("\nMatriz después del intercambio:\n");
    for (I = 0; I < F; I++) {
        for (J = 0; J < C; J++) {
            printf("%5.2f ", A[I][J]);
        }
        printf("\n");
    }
}

