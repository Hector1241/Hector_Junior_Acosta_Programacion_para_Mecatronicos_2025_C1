#include <stdio.h>

/* Arreglo sin elementos repetidos.
   El programa recibe un arreglo unidimensional desordenado de N elementos
   y lo devuelve sin elementos repetidos. */

/* Prototipos de funciones */
void Lectura(int *, int);
void Imprime(int *, int);
void Elimina(int *, int *);

int main(void)
{
    int TAM, ARRE[100];

    /* Se verifica que el tamaño del arreglo sea válido */
    do
    {
        printf("Ingrese el tamaño del arreglo (1-100): ");
        scanf("%d", &TAM);
    } while (TAM > 100 || TAM < 1);

    /* Lectura del arreglo */
    Lectura(ARRE, TAM);

    /* Eliminación de elementos repetidos */
    Elimina(ARRE, &TAM);

    /* Impresión del arreglo sin repeticiones */
    Imprime(ARRE, TAM);

    return 0;
}

void Lectura(int A[], int T)
{
    printf("\n");
    int I;
    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

void Imprime(int A[], int T)
{
    int I;
    printf("\nArreglo sin elementos repetidos:\n");
    for (I = 0; I < T; I++)
    {
        printf("A[%d]: %d\n", I, A[I]);
    }
}

void Elimina(int A[], int *T)
{
    int I = 0, K, L;

    while (I < (*T - 1))
    {
        K = I + 1;
        while (K < *T)
        {
            if (A[I] == A[K])
            {
                for (L = K; L < (*T - 1); L++)
                {
                    A[L] = A[L + 1];
                }
                (*T)--;
            }
            else
            {
                K++;
            }
        }
        I++;
    }
}
