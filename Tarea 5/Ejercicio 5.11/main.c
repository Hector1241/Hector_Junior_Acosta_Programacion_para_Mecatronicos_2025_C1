#include <stdio.h>

#define MAX 100  // Definimos el tamaño máximo del arreglo

/* Prototipos de funciones */
void Lectura(int *, int);
int Binaria(int *, int, int);

int main(void)
{
    int RES, ELE, TAM, VEC[MAX];

    // Validación del tamaño del arreglo
    do
    {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    } while (TAM > MAX || TAM < 1);

    Lectura(VEC, TAM);

    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);

    RES = Binaria(VEC, TAM, ELE);  // Se llama a la función de búsqueda binaria

    if (RES != -1)
        printf("\nEl elemento se encuentra en la posición: %d", RES + 1);
    else
        printf("\nEl elemento no se encuentra en el arreglo");

    return 0;
}

void Lectura(int A[], int T)
/* La función Lectura se utiliza para leer un arreglo unidimensional de T elementos. */
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

int Binaria(int A[], int T, int E)
/* Esta función realiza una búsqueda binaria en un arreglo ordenado.
   Si encuentra el elemento, retorna la posición. Si no, retorna -1. */
{
    int IZQ = 0, DER = T - 1, CEN, BAN = -1;

    while (IZQ <= DER && BAN == -1)
    {
        CEN = (IZQ + DER) / 2;
        if (E == A[CEN])
            BAN = CEN;  // Se guarda la posición en caso de encontrar el elemento
        else if (E > A[CEN])
            IZQ = CEN + 1;
        else
            DER = CEN - 1;
    }

    return BAN;
}
