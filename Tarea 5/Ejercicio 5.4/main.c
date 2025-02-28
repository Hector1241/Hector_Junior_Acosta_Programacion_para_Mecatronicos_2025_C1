#include <stdio.h>

#define MAX 10  /* Se define una constante para el tamaño de los arreglos */

void Lectura(int VEC[], int T);
void Imprime(int VEC[], int T);
void Producto(int *X, int *Y, int *Z, int T);  // Se corrige la declaración de Producto

int main(void)
{
    int VE1[MAX], VE2[MAX], VE3[MAX];

    /* Lectura de los dos vectores */
    Lectura(VE1, MAX);
    Lectura(VE2, MAX);

    /* Cálculo del producto */
    Producto(VE1, VE2, VE3, MAX);

    /* Impresión del resultado */
    printf("\nProducto de los Vectores:\n");
    Imprime(VE3, MAX);

    return 0;
}

void Lectura(int VEC[], int T)
{
    int I;
    printf("\nIngrese los elementos del vector:\n");
    for (I = 0; I < T; I++)
    {
        printf("Elemento %d: ", I + 1);
        scanf("%d", &VEC[I]);
    }
}

void Imprime(int VEC[], int T)
{
    int I;
    printf("\nElementos del vector resultante:\n");
    for (I = 0; I < T; I++)
    {
        printf("VEC[%d] = %d\n", I + 1, VEC[I]);
    }
}

void Producto(int *X, int *Y, int *Z, int T)
{
    int I;
    for (I = 0; I < T; I++)
    {
        Z[I] = X[I] * Y[I];  // Producto de cada elemento de los vectores
    }
}
