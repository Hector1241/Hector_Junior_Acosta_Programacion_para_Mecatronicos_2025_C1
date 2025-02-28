#include <stdio.h>

#define MAX 100  // Definimos el tama�o m�ximo del arreglo

/* Prototipos de funciones */
void Lectura(int *, int);
int Busca(int *, int, int);

int main(void)
{
    int RES, ELE, TAM, VEC[MAX];

    // Validaci�n del tama�o del arreglo
    do
    {
        printf("Ingrese el tama�o del arreglo: ");
        scanf("%d", &TAM);
    } while (TAM > MAX || TAM < 1);

    Lectura(VEC, TAM);

    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);

    RES = Busca(VEC, TAM, ELE);  // Se llama a la funci�n de b�squeda

    if (RES)
        printf("\nEl elemento se encuentra en la posici�n: %d", RES);
    else
        printf("\nEl elemento no se encuentra en el arreglo");

    return 0;
}

void Lectura(int A[], int T)
/* Esta funci�n se utiliza para leer un arreglo unidimensional de T elementos de tipo entero. */
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

int Busca(int A[], int T, int E)
/* Esta funci�n busca el elemento E en el arreglo A.
   Si se encuentra, regresa la posici�n (1-based index). Si no, regresa 0. */
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
        RES = I + 1;  // Se suma 1 para que la posici�n sea 1-based
    return RES;
}
