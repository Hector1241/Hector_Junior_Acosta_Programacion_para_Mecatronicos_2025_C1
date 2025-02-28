#include <stdio.h>

#define PRO 24
#define MES 12
#define AÑO 10

void Lectura(float A[PRO][MES][AÑO], int F, int C, int P);
void Funcion1(float A[PRO][MES][AÑO], int F, int C, int P);
void Funcion2(float A[PRO][MES][AÑO], int F, int C, int P);
void Funcion3(float A[PRO][MES][AÑO], int F, int C, int P);

int main(void) {
    float LLU[PRO][MES][AÑO];

    Lectura(LLU, PRO, MES, AÑO);
    Funcion1(LLU, PRO, MES, AÑO);
    Funcion2(LLU, PRO, MES, AÑO);
    Funcion3(LLU, 18, MES, 5);

    return 0;
}

void Lectura(float A[][MES][AÑO], int F, int C, int P) {
    int K, I, J;
    for (K = 0; K < P; K++)
        for (I = 0; I < F; I++)
            for (J = 0; J < C; J++) {
                printf("Año: %d\tProvincia: %d\tMes: %d: ", K + 1, I + 1, J + 1);
                scanf("%f", &A[I][J][K]);
            }
}

void Funcion1(float A[][MES][AÑO], int F, int C, int P) {
    int I, K, J, EMAY = -1;
    float ELLU = -1.0, SUM;

    for (I = 0; I < F; I++) {
        SUM = 0.0;
        for (K = 0; K < P; K++)
            for (J = 0; J < C; J++)
                SUM += A[I][J][K];

        SUM /= P * C;
        if (SUM > ELLU) {
            ELLU = SUM;
            EMAY = I;
        }
    }

    printf("\n\nProvincia con mayor registro de lluvias: %d", EMAY + 1);
    printf("\nRegistro: %.2f\n", ELLU);
}

void Funcion2(float A[][MES][AÑO], int F, int C, int P) {
    int I, J, EMEN = -1;
    float ELLU = 1000, SUM;

    for (I = 0; I < F; I++) {
        SUM = 0;
        for (J = 0; J < C; J++)
            SUM += A[I][J][P - 1];

        SUM /= C;
        if (SUM < ELLU) {
            ELLU = SUM;
            EMEN = I;
        }
    }

    printf("\n\nProvincia con menor registro anual de lluvias en el último año: %d", EMEN + 1);
    printf("\nRegistro anual: %.2f\n", ELLU);
}

void Funcion3(float A[][MES][AÑO], int F, int C, int P) {
    int J, EMES = -1;
    float ELLU = -1.0;

    if (F > PRO || P > AÑO) {
        printf("\n\nError: Índices fuera de rango.\n");
        return;
    }

    for (J = 0; J < C; J++) {
        if (A[F - 1][J][P - 1] > ELLU) {
            ELLU = A[F - 1][J][P - 1];
            EMES = J;
        }
    }

    printf("\n\nMes con mayor lluvia en provincia 18, año 5: %d", EMES + 1);
    printf("\nRegistro: %.2f\n", ELLU);
}
