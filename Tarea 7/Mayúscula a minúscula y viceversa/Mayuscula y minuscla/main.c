#include <stdio.h>

int main() {
    char letra, convertida;

    // 1 - Pedir ingresar una letra
    printf("Ingrese una letra: ");
    scanf("%c", &letra);

    // 2 - Verificar que sea una letra
    if ((letra >= 'A' && letra <= 'Z') || (letra >= 'a' && letra <= 'z')) {

        // 3 - Comprobar si es mayúscula o minúscula y 4 - Convertir
        if (letra >= 'a' && letra <= 'z') {
            convertida = letra - 32; // Convierte a mayúscula (ASCII)
        } else {
            convertida = letra + 32; // Convierte a minúscula (ASCII)
        }

        // 5 - Imprimir la letra convertida
        printf("Letra convertida: %c\n", convertida);
    } else {
        printf("Error: No ingresó una letra válida.\n");
    }

    return 0;
}
