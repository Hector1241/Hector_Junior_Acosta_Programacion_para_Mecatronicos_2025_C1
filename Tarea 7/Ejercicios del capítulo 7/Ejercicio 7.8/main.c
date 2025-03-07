#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Min�sculas y may�sculas.
   El programa, al recibir como dato un arreglo unidimensional de tipo
   cadena de caracteres, determina el n�mero de min�sculas y may�sculas
   que hay en cada cadena. */

void minymay(char *cadena); /* Prototipo de funci�n */

int main(void)
{
    int i, n;
    char FRA[20][50]; /* Arreglo unidimensional de cadenas de caracteres */

    printf("\nIngrese el n�mero de filas del arreglo: ");
    scanf("%d", &n);
    getchar(); // Consumir el salto de l�nea despu�s de scanf

    for (i = 0; i < n; i++)
    {
        /* Para cada fila se lee la cadena correspondiente. */
        printf("Ingrese la l�nea %d de texto: ", i + 1);
        fgets(FRA[i], sizeof(FRA[i]), stdin);

        /* Eliminar el salto de l�nea agregado por fgets */
        FRA[i][strcspn(FRA[i], "\n")] = '\0';
    }

    printf("\n\n");

    for (i = 0; i < n; i++)
    {
        minymay(FRA[i]);
    }

    return 0;
}

void minymay(char *cadena)
{
    /* Esta funci�n se utiliza para calcular el n�mero de min�sculas
       y may�sculas que hay en cada cadena. */

    int i = 0, mi = 0, ma = 0;

    while (cadena[i] != '\0') // Corregido el uso de comillas incorrectas
    {
        if (islower(cadena[i]))
            mi++;
        else if (isupper(cadena[i]))
            ma++;
        i++;
    }

    printf("\n\nN�mero de letras min�sculas: %d", mi);
    printf("\nN�mero de letras may�sculas: %d", ma);
}
