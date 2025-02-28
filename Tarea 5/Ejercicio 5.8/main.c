#include <stdio.h>

#define TAM 100  // Definimos el tamaño del arreglo

/* Prototipos de funciones */
void Imprime(int *, int);
void Primo(int, int *);

int main(void)
{
    int P[TAM];  // Arreglo para almacenar los primeros 100 números primos
    int FLA, J = 1, PRI = 3;

    P[0] = 2;  // Primer número primo

    while (J < TAM)
    {
        FLA = 1;
        Primo(PRI, &FLA);  // Se llama a la función para verificar si es primo

        if (FLA)  // Si FLA sigue siendo 1, significa que es primo
        {
            P[J] = PRI;
            J++;
        }

        PRI += 2;  // Solo probamos números impares, ya que los pares no son primos (excepto el 2)
    }

    Imprime(P, TAM);

    return 0;
}

void Primo(int A, int *B)
/* Esta función determina si A es primo, en cuyo caso el valor de *B no se altera. */
{
    int DI = 3;

    while (*B && (DI * DI <= A))
    {
        if (A % DI == 0)
            *B = 0;

        DI += 2;  // Probamos solo divisores impares
    }
}

void Imprime(int Primos[], int T)
/* Esta función imprime el arreglo unidimensional de números primos. */
{
    int I;
    printf("Lista de los primeros %d números primos:\n", T);
    for (I = 0; I < T; I++)
    {
        printf("%d ", Primos[I]);
        if ((I + 1) % 10 == 0)  // Imprimir 10 números por línea
            printf("\n");
    }
}
