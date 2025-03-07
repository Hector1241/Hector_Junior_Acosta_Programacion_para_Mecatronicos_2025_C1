#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Minúsculas y mayúsculas.
   El programa, al recibir como dato un arreglo unidimensional de tipo
   cadena de caracteres, determina el número de minúsculas y mayúsculas
   que hay en cada cadena. */

void minymay(char *cadena); /* Prototipo de función */

int main(void)
{
    int i, n;
    char FRA[20][50]; /* Arreglo unidimensional de cadenas de caracteres */

    printf("\nIngrese el número de filas del arreglo: ");
    scanf("%d", &n);
    getchar(); // Consumir el salto de línea después de scanf

    for (i = 0; i < n; i++)
    {
        /* Para cada fila se lee la cadena correspondiente. */
        printf("Ingrese la línea %d de texto: ", i + 1);
        fgets(FRA[i], sizeof(FRA[i]), stdin);

        /* Eliminar el salto de línea agregado por fgets */
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
    /* Esta función se utiliza para calcular el número de minúsculas
       y mayúsculas que hay en cada cadena. */

    int i = 0, mi = 0, ma = 0;

    while (cadena[i] != '\0') // Corregido el uso de comillas incorrectas
    {
        if (islower(cadena[i]))
            mi++;
        else if (isupper(cadena[i]))
            ma++;
        i++;
    }

    printf("\n\nNúmero de letras minúsculas: %d", mi);
    printf("\nNúmero de letras mayúsculas: %d", ma);
}
