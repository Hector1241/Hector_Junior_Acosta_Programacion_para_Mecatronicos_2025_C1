#include <stdio.h>

int main(void) {
    char *cad0 = "Buenos d\u00edas";
    char cad1[20] = "Hola";
    char cad2[] = "M\u00e9xico";
    char cad3[] = {'B', 'i', 'e', 'n', 'v', 'e', 'n', 'i', 'd', 'o', '\0'};
    char cad4[20], cad5[20], cad6[20];
    char p;
    int i = 0;

    printf("\nLa cadena cad0 es: ");
    puts(cad0);
    printf("\nLa cadena cad1 es: %s\n", cad1);
    printf("\nLa cadena cad2 es: ");
    puts(cad2);
    printf("\nLa cadena cad3 es: ");
    puts(cad3);

    printf("\nIngrese una l\u00ednea de texto �se lee con gets�: \n");
    fgets(cad4, sizeof(cad4), stdin);
    printf("\nLa cadena cad4 es: ");
    puts(cad4);

    printf("\nIngrese una l\u00ednea de texto �se lee con scanf�: \n");
    scanf("%19s", cad5);
    printf("\nLa cadena cad5 es: %s\n", cad5);
    getchar();

    printf("\nIngrese una l\u00ednea de texto �se lee cada caracter con getchar�: \n");
    while ((p = getchar()) != '\n' && i < (sizeof(cad6) - 1)) {
        cad6[i++] = p;
    }
    cad6[i] = '\0';

    printf("\nLa cadena cad6 es: ");
    puts(cad6);

    return 0;
}
