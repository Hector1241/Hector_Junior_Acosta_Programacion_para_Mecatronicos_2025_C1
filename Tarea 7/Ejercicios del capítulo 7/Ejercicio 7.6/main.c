#include <stdio.h>
#include <string.h>

/* Funciones de la biblioteca string.h para el manejo de cadenas de caracteres. */
int main(void) {
    char cad0[50] = "Hola M�xico";
    char cad1[20], cad2[20], cad3[20] = ", buenos d�as!!!";

    strcpy(cad1, cad0);
    printf("\nPrueba de la funci�n strcpy. Se copia la cadena cad0 a cad1: %s\n", cad1);

    strcpy(cad1, cad3);
    printf("\nPrueba de la funci�n strcpy. Se copia la cadena cad3 a cad1: %s\n", cad1);

    strcpy(cad1, "XX");
    printf("\nPrueba de la funci�n strcpy. Se copia la cadena XX a cad1: %s\n", cad1);

    strncpy(cad2, cad0, 4);
    cad2[4] = '\0';
    printf("\nPrueba de la funci�n strncpy. Se copian 4 caracteres de cad0 a cad2: %s\n", cad2);

    strncpy(cad2, cad3, 3);
    cad2[3] = '\0';
    printf("\nPrueba de la funci�n strncpy. Se copian 3 caracteres de cad3 a cad2: %s\n", cad2);

    strcat(cad0, cad3);
    printf("\nPrueba de la funci�n strcat. Se incorpora la cadena cad3 a cad0: %s\n", cad0);

    strcat(cad1, " YY");
    printf("\nPrueba de la funci�n strcat. Se incorpora la cadena YY a cad1: %s\n", cad1);

    strcat(cad2, " ");
    strncat(cad2, cad0, 4);
    printf("\nPrueba de la funci�n strncat. Se incorporan 4 caracteres de cad0 a cad2: %s\n", cad2);

    char *posicion = strstr(cad0, "M�xico");
    if (posicion)
        printf("\nPrueba de la funci�n strstr. Se localiza la cadena 'M�xico' dentro de cad0: %s\n", posicion);
    else
        printf("\nPrueba de la funci�n strstr. No se encontr� 'M�xico' dentro de cad0.\n");

    posicion = strstr(cad0, "Guatemala");
    if (posicion)
        printf("\nPrueba de la funci�n strstr. Se localiza la cadena 'Guatemala' dentro de cad0: %s\n", posicion);
    else
        printf("\nPrueba de la funci�n strstr. No se encontr� 'Guatemala' dentro de cad0.\n");

    return 0;
}

