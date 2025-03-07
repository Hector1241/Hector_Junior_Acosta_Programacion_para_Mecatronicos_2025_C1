#include <stdio.h>
#include <string.h>

/* Cuenta caracteres.
   El programa, al recibir como datos una cadena de caracteres y un car�cter,
   cuenta cu�ntas veces se encuentra el car�cter en la cadena. */

int cuenta(char *, char); /* Prototipo de funci�n. */

int main(void)
{
    char car, cad[50];
    int res;

    printf("\nIngrese la cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin);

    /* Eliminar el salto de l�nea agregado por fgets */
    cad[strcspn(cad, "\n")] = '\0';

    printf("\nIngrese el car�cter: ");
    car = getchar();

    res = cuenta(cad, car);
    printf("\n\n%c se encuentra %d veces en la cadena %s\n", car, res, cad);

    return 0;
}

int cuenta(char *cad, char car)
{
    /* Esta funci�n se utiliza para obtener el n�mero de veces que se encuentra
       el car�cter en la cadena. */
    int i = 0, r = 0;

    while (cad[i] != '\0') // Comillas corregidas
    {
        if (cad[i] == car)
            r++;
        i++;
    }
    return r;
}
