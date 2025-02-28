 #include <stdio.h>

#define MAX 50  // Definici�n del tama�o m�ximo de la matriz

// Prototipo de funciones
void Lectura(int [][MAX], int, int);
void Suma(int[][MAX], int[][MAX], int[][MAX], int, int);
void Imprime(int [][MAX], int, int);

int main(void) {
    int MA[MAX][MAX], MB[MAX][MAX], MC[MAX][MAX]; // Declaraci�n de los arreglos
    int FIL, COL;

    do {
        printf("Ingrese el n�mero de filas de los arreglos: ");
        scanf("%d", &FIL);
    } while (FIL > MAX || FIL < 1); // Verifica que el n�mero de filas sea v�lido

    do {
        printf("Ingrese el n�mero de columnas de los arreglos: ");
        scanf("%d", &COL);
    } while (COL > MAX || COL < 1); // Verifica que el n�mero de columnas sea v�lido

    printf("\nLectura del Arreglo MA\n");
    Lectura(MA, FIL, COL);

    printf("\nLectura del Arreglo MB\n");
    Lectura(MB, FIL, COL);

    Suma(MA, MB, MC, FIL, COL);

    printf("\nImpresi�n del Arreglo MC\n");
    Imprime(MC, FIL, COL);

    return 0;
}

void Lectura(int A[][MAX], int F, int C) {
    // Funci�n para leer un arreglo bidimensional
    int I, J;
    for (I = 0; I < F; I++)
        for (J = 0; J < C; J++) {
            printf("Ingrese el elemento [%d][%d]: ", I + 1, J + 1);
            scanf("%d", &A[I][J]);
        }
}

void Suma(int M1[][MAX], int M2[][MAX], int M3[][MAX], int F, int C) {
    // Funci�n para sumar dos arreglos bidimensionales
    int I, J;
    for (I = 0; I < F; I++)
        for (J = 0; J < C; J++)
            M3[I][J] = M1[I][J] + M2[I][J];
}

void Imprime(int A[][MAX], int F, int C) {
    // Funci�n para imprimir un arreglo bidimensional
    int I, J;
    printf("\nMatriz resultante (MC):\n");
    for (I = 0; I < F; I++) {
        for (J = 0; J < C; J++)
            printf("%4d", A[I][J]); // Imprime valores alineados
        printf("\n");
    }
}
