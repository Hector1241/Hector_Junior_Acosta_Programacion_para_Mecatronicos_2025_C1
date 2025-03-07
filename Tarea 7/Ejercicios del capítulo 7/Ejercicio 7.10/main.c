 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Suma y promedio.
   El programa, al recibir como datos varias cadenas de caracteres que
   contienen n�meros reales, los suma y obtiene el promedio de los mismos. */

int main(void)
{
    char c, cad[10];
    int i = 0;
    float sum = 0.0;

    printf("\nDesea ingresar una cadena de caracteres (S/N)? ");
    c = getchar();
    getchar(); // Consumir el salto de l�nea despu�s de getchar()

    while (c == 'S' || c == 's') // Acepta may�sculas y min�sculas
    {
        printf("\nIngrese la cadena de caracteres: ");
        fgets(cad, sizeof(cad), stdin);

        // Eliminar el salto de l�nea agregado por fgets
        cad[strcspn(cad, "\n")] = '\0';

        i++;
        sum += atof(cad);

        printf("\nDesea ingresar otra cadena de caracteres (S/N)? ");
        c = getchar();
        getchar(); // Consumir el salto de l�nea despu�s de getchar()
    }

    if (i > 0) // Evitar divisi�n por cero
    {
        printf("\nSuma: %.2f", sum);
        printf("\nPromedio: %.2f\n", sum / i);
    }
    else
    {
        printf("\nNo se ingresaron valores v�lidos.\n");
    }

    return 0;
}
