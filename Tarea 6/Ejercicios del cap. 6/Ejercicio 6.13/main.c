#include <stdio.h>

#define MES 12
#define DEP 3
#define AÑO 8

void Lectura(float A[MES][DEP][AÑO], int F, int C, int P);
void Funcion1(float A[MES][DEP][AÑO], int F, int C, int P);
void Funcion2(float A[MES][DEP][AÑO], int F, int C, int P);
void Funcion3(float A[MES][DEP][AÑO], int F, int C, int P);

int main(void) {
    float PRO[MES][DEP][AÑO];

    Lectura(PRO, MES, DEP, AÑO);
    Funcion1(PRO, MES, DEP, 2);
    Funcion2(PRO, MES, DEP, AÑO);
    Funcion3(PRO, MES, DEP, AÑO);

    return 0;
}

void Lectura(float A[][DEP][AÑO], int F, int C, int P) {
    int K, I, J;
    for (K = 0; K < P; K++)
        for (I = 0; I < F; I++)
            for (J = 0; J < C; J++) {
                printf("Año: %d\tMes: %d\tDepartamento: %d: ", K + 1, I + 1, J + 1);
                scanf("%f", &A[I][J][K]);
            }
}

void Funcion1(float A[][DEP][AÑO], int F, int C, int P) {
    int I, J;
    float SUM = 0.0;

    for (I = 0; I < F; I++)
        for (J = 0; J < C; J++)
            SUM += A[I][J][P - 1]; // Segundo año (P=2, P-1=1)

    printf("\n\nVentas totales de la empresa en el segundo año: %.2f\n", SUM);
}

void Funcion2(float A[][DEP][AÑO], int F, int C, int P) {
    int I, J;
    float SUM1 = 0, SUM2 = 0, SUM3 = 0;

    for (I = 0; I < F; I++)
        for (J = 0; J < C; J++) {
            switch (J + 1) {
                case 1: SUM1 += A[I][J][P - 1]; break;
                case 2: SUM2 += A[I][J][P - 1]; break;
                case 3: SUM3 += A[I][J][P - 1]; break;
            }
        }

    if (SUM1 > SUM2 && SUM1 > SUM3) {
        printf("\n\nDepartamento con mayores ventas en el último año: Hilos");
        printf("\nVentas: %.2f\n", SUM1);
    } else if (SUM2 > SUM3) {
        printf("\n\nDepartamento con mayores ventas en el último año: Lanas");
        printf("\nVentas: %.2f\n", SUM2);
    } else {
        printf("\n\nDepartamento con mayores ventas en el último año: Licra");
        printf("\nVentas: %.2f\n", SUM3);
    }
}

void Funcion3(float A[][DEP][AÑO], int F, int C, int P) {
    int K, I, J, DE = -1, ME = -1, AN = -1;
    float VEN = -1.0;

    for (K = 0; K < P; K++)
        for (I = 0; I < F; I++)
            for (J = 0; J < C; J++)
                if (A[I][J][K] > VEN) {
                    VEN = A[I][J][K];
                    DE = J;
                    ME = I;
                    AN = K;
                }

    printf("\n\nDepartamento: %d\tMes: %d\tAño: %d", DE + 1, ME + 1, AN + 1);
    printf("\tVentas: %.2f\n", VEN);
}
