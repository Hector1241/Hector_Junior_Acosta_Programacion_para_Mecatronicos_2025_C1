#include <stdio.h>
#include <string.h>

/* Cuenta caracteres.
   El programa, al recibir como datos una cadena de caracteres y un carácter,
   cuenta cuántas veces se encuentra el carácter en la cadena. */

int cuenta(char *, char); /* Prototipo de función. */

int main(void)
{
    char car, cad[50];
    int res;

    printf("\nIngrese la cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin);

    /* Eliminar el salto de línea agregado por fgets */
    cad[strcspn(cad, "\n")] = '\0';

    printf("\nIngrese el carácter: ");
    car = getchar();

    res = cuenta(cad, car);
    printf("\n\n%c se encuentra %d veces en la cadena %s\n", car, res, cad);

    return 0;
}

int cuenta(char *cad, char car)
{
    /* Esta función se utiliza para obtener el número de veces que se encuentra
       el carácter en la cadena. */
    int i = 0, r = 0;

    while (cad[i] != '\0') // Comillas corregidas
    {
        if (cad[i] == car)
            r++;
        i++;
    }
    return r;
}
