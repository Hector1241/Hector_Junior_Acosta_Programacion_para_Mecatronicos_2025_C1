#include <stdio.h>

#define TAM 50  /* Definimos el tamaño del arreglo de calificaciones */

void Lectura(int *, int);
void Frecuencia(int *, int, int *, int);
void Impresion(int *, int);
void Mayor(int *, int);

int main(void)
{
    int CAL[TAM], FRE[6] = {0};  /* Declaración de los arreglos */

    /* Lectura de calificaciones */
    Lectura(CAL, TAM);

    /* Cálculo de frecuencias */
    Frecuencia(CAL, TAM, FRE, 6);

    /* Impresión de frecuencias */
    printf("\nFrecuencia de Calificaciones\n");
    Impresion(FRE, 6);

    /* Determinación de la mayor frecuencia */
    Mayor(FRE, 6);

    return 0;
}

void Lectura(int VEC[], int T)
{
    int I;
    printf("\nIngrese las calificaciones (0-5):\n");
    for (I = 0; I < T; I++)
    {
        do
        {
            printf("Calificación del alumno %d: ", I + 1);
            scanf("%d", &VEC[I]);
            if (VEC[I] < 0 || VEC[I] > 5)
                printf("Error: La calificación debe estar entre 0 y 5.\n");
        } while (VEC[I] < 0 || VEC[I] > 5); // Validación de entrada
    }
}

void Impresion(int VEC[], int T)
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("\nFrecuencia de la calificación %d: %d", I, VEC[I]);
    }
    printf("\n");
}

void Frecuencia(int A[], int P, int B[], int T)
{
    int I;
    for (I = 0; I < P; I++)
    {
        if (A[I] >= 0 && A[I] < 6) // Validación
            B[A[I]]++;
    }
}

void Mayor(int *X, int T)
{
    int I, MFRE = 0, MVAL = X[0];

    for (I = 1; I < T; I++)
    {
        if (MVAL < X[I])
        {
            MFRE = I;
            MVAL = X[I];
        }
    }

    printf("\nMayor frecuencia de calificaciones: %d \tValor: %d\n", MFRE, MVAL);
}
