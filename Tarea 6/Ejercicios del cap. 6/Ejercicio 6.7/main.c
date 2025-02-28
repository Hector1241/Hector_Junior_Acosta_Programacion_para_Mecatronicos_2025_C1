#include <stdio.h>

#define MESES 12
#define PRODUCTOS 15

void Lectura1(int A[PRODUCTOS][MESES]);
void Lectura2(float A[], int N);
void Funcion1(int A[][MESES], int F, int C, float V1[], float V2[]);
void Funcion2(float A[], int C);
void Funcion3(float A[], int C);

int main(void) {
    int FAB[PRODUCTOS][MESES] = {0}; // Inicialización en 0 del arreglo.
    float COS[PRODUCTOS], VEN[PRODUCTOS];

    Lectura1(FAB);
    Lectura2(COS, PRODUCTOS);
    Funcion1(FAB, PRODUCTOS, MESES, COS, VEN);
    Funcion2(VEN, PRODUCTOS);
    Funcion3(VEN, PRODUCTOS);

    return 0;
}

void Lectura1(int A[][MESES]) {
    /* Esta función se utiliza para almacenar las ventas mensuales. */
    int MES, PRO, CAN;
    printf("\nIngrese mes, tipo de producto y cantidad vendida (-1 para terminar): ");
    scanf("%d %d %d", &MES, &PRO, &CAN);

    while (MES != -1 && PRO != -1 && CAN != -1) {
        if (MES >= 1 && MES <= MESES && PRO >= 1 && PRO <= PRODUCTOS) {
            A[PRO - 1][MES - 1] += CAN;
        } else {
            printf("Error: Mes o producto fuera de rango.\n");
        }

        printf("Ingrese mes, tipo de producto y cantidad vendida (-1 para terminar): ");
        scanf("%d %d %d", &MES, &PRO, &CAN);
    }
}

void Lectura2(float A[], int N) {
    /* Esta función lee los costos de los productos. */
    int I;
    for (I = 0; I < N; I++) {
        printf("Ingrese costo del producto %d: ", I + 1);
        scanf("%f", &A[I]);
    }
}

void Funcion1(int A[][MESES], int F, int C, float V1[], float V2[]) {
    /* Calcula el monto de ventas anual de cada producto. */
    int I, J;
    float SUM;
    printf("\n");

    for (I = 0; I < F; I++) {
        SUM = 0.0f;
        for (J = 0; J < C; J++) {
            SUM += A[I][J];
        }
        V2[I] = V1[I] * SUM;
        printf("\nTotal de ventas del producto %d: %8.2f", I + 1, V2[I]);
    }
}

void Funcion2(float A[], int C) {
    /* Calcula el monto total de ventas de la fábrica. */
    int I;
    float SUM = 0.0f;

    for (I = 0; I < C; I++) {
        SUM += A[I];
    }
    printf("\n\nTotal de ventas de la fábrica: %.2f", SUM);
}

void Funcion3(float A[], int C) {
    /* Determina el producto más vendido y su monto total de ventas. */
    int I, TPR = 0;
    float VEN = A[0];

    for (I = 1; I < C; I++) {
        if (VEN < A[I]) {
            TPR = I;
            VEN = A[I];
        }
    }
    printf("\n\nTipo de Producto más vendido: %d \t Ventas: %.2f", TPR + 1, VEN);
}
