#include <stdio.h>

/* Elección.
   El programa almacena los votos emitidos en una elección en la que hubo cinco
   candidatos e imprime el total de votos que obtuvo cada uno de ellos. */

int main(void) {
    int ELE[5] = {0};   // Declaración del arreglo de cinco elementos inicializados en 0.
    int I, VOT;

    printf("Ingresa el primer voto (0 - Para terminar): ");
    scanf("%d", &VOT);

    while (VOT) {
        if ((VOT > 0) && (VOT < 6)) {  // Verificación de voto válido (1 a 5)
            ELE[VOT - 1]++;  // Se almacena el voto en la posición correspondiente
        } else {
            printf("\nEl voto ingresado es incorrecto.\n");
        }

        printf("Ingresa el siguiente voto (0 - Para terminar): ");
        scanf("%d", &VOT);
    }

    printf("\n\nResultados de la Elección\n");
    for (I = 0; I < 5; I++) {  // Se recorre el arreglo para imprimir los resultados
        printf("\nCandidato %d: %d votos", I + 1, ELE[I]);
    }

    return 0;
}
