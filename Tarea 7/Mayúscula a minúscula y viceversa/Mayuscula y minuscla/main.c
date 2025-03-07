#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a, s;

    // 1- Pedir ingresar una letra
    printf("\nIngresa una letra: \n");
    a = getchar();

    // 2- Verificar si es letra minúscula (a - z)
    if (a >= 97 && a <= 122)
    {
        // 4- Convertir de minúscula a mayúscula
        s = a - 32;
        // 5- Imprimir la letra convertida
        putchar(s);
    }
    // 3- Verificar si es letra mayúscula (A - Z)
    else if (a >= 65 && a <= 90)
    {
        // 4- Convertir de mayúscula a minúscula
        s = a + 32;
        // 5- Imprimir la letra convertida
        putchar(s);
    }
    // Si no es una letra
    else
    {
        printf("\nNo es una letra");
    }

    return 0;
}
