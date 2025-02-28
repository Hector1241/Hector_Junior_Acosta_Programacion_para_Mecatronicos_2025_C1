#include <stdio.h>

/* Sim�trico.
   El programa, al recibir como dato un arreglo bidimensional cuadrado,
   determina si el mismo es sim�trico. */

#define MAX 100  // Tama�o m�ximo del arreglo

// Prototipos de funciones
void Lectura(int [][MAX], int);
int Simetrico(int [][MAX], int);

int main(void) {
    int MAT[MAX][MAX], N, RES;

    // Validaci�n del tama�o de la matriz
    do {
        printf("Ingrese el tama�o del arreglo: ");
        scanf("%d", &N);
    } while (N > MAX || N < 1);

    Lectura(MAT, N);
    RES = Simetrico(MAT, N);

    if (RES)
        printf("\nEl arreglo bidimensional es sim�trico\n");
    else
        printf("\nEl arreglo bidimensional no es sim�trico\n");

    return 0;
}

void Lectura(int A[][MAX], int T) {
    /* La funci�n Lectura se utiliza para leer un arreglo bidimensional cuadrado de
       tipo entero de T filas y T columnas. */

    int I, J;
    for (I = 0; I < T; I++)
        for (J = 0; J < T; J++) {
            printf("Fila: %d\tColumna: %d: ", I + 1, J + 1);
            scanf("%d", &A[I][J]);
        }
}

int Simetrico(int A[][MAX], int T) {
    /* La funci�n Sim�trico se utiliza para determinar si el arreglo bidimensional
       cuadrado es sim�trico. Si es sim�trico regresa 1, en caso contrario, 0.
       Observa que en el segundo ciclo solamente se recorre la matriz triangular
       inferior, sin la diagonal principal. */

    int I = 0, J, F = 1;

    while ((I < T) && F) {
        J = 0;
        while ((J < I) && F) {
            if (A[I][J] != A[J][I])
                F = 0;
            J++;
        }
        I++;
    }
    return F;
}
