#include <stdio.h>

#define MAX 100  // Definimos el tamaño máximo del arreglo

/* Prototipos de funciones */
void Lectura(int *, int);
int Busca(int *, int, int);

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

    RES = Busca(VEC, TAM, ELE);  // Se llama a la función de búsqueda

    if (RES)
        printf("\nEl elemento se encuentra en la posición: %d", RES);
    else
        printf("\nEl elemento no se encuentra en el arreglo");

    return 0;
}

void Lectura(int A[], int T)
/* Esta función se utiliza para leer un arreglo unidimensional de T elementos de tipo entero. */
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

int Busca(int A[], int T, int E)
/* Esta función busca el elemento E en el arreglo A.
   Si se encuentra, regresa la posición (1-based index). Si no, regresa 0. */
{
    int I = 0, BAN = 0, RES = 0;

    while ((I < T) && (E >= A[I]) && !BAN)
    {
        if (A[I] == E)
            BAN = 1;
        else
            I++;
    }

    if (BAN)
        RES = I + 1;  // Se suma 1 para que la posición sea 1-based
    return RES;
}
