#include <stdio.h>

#define MAX 50  // Definimos el tamaño máximo de la matriz

void Lectura(int A[][MAX], int F, int C);
void Traspuesta(int M1[][MAX], int M2[][MAX], int F, int C);
void Imprime(int A[][MAX], int F, int C);

int main(void) {
    int MAT[MAX][MAX], TRA[MAX][MAX];
    int FIL, COL;

    do {
        printf("Ingrese el número de filas de la matriz: ");
        scanf("%d", &FIL);
    } while (FIL > MAX || FIL < 1);
    /* Se verifica que el número de filas sea correcto. */

    do {
        printf("Ingrese el número de columnas de la matriz: ");
        scanf("%d", &COL);
    } while (COL > MAX || COL < 1);
    /* Se verifica que el número de columnas sea correcto. */

    Lectura(MAT, FIL, COL);
    Traspuesta(MAT, TRA, FIL, COL);

    printf("\nMatriz Traspuesta:\n");
    Imprime(TRA, COL, FIL);

    return 0;
}

void Lectura(int A[][MAX], int F, int C) {
    /* Esta función lee los elementos de la matriz. */
    int I, J;
    for (I = 0; I < F; I++) {
        for (J = 0; J < C; J++) {
            printf("Ingrese el elemento [%d][%d]: ", I + 1, J + 1);
            scanf("%d", &A[I][J]);
        }
    }
}

void Traspuesta(int M1[][MAX], int M2[][MAX], int F, int C) {
    /* Calcula la traspuesta de la matriz. */
    int I, J;
    for (I = 0; I < F; I++) {
        for (J = 0; J < C; J++) {
            M2[J][I] = M1[I][J];
        }
    }
}

void Imprime(int A[][MAX], int F, int C) {
    /* Muestra la matriz traspuesta. */
    int I, J;
    for (I = 0; I < F; I++) {
        for (J = 0; J < C; J++) {
            printf("%d ", A[I][J]);
        }
        printf("\n");
    }
}
