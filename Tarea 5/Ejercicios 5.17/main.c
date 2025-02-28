#include <stdio.h>

/* Apuntadores y arreglos */
void main(void) {
    int V1[4] = {1, 3, 5, 7};
    int V2[4] = {2, 4, 0, 0};  // Se inicializa completamente V2 para evitar valores basura

    int *AX, *AY;
    AX = &V1[2];  // Apunta a V1[2] (5)
    AY = &V2[2];  // Apunta a V2[2] (0)

    V2[2] = *(AX + 1);  // V2[2] = V1[3] (7)
    V2[3] = *AX;        // V2[3] = V1[2] (5)

    AX = AX + 1;        // AX ahora apunta a V1[3] (7)
    V1[0] = *AX;        // V1[0] = 7

    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d V1[3]=%d\tV2[0]=%d V2[1]=%d V2[2]=%d V2[3]=%d",
           V1[0], V1[1], V1[2], V1[3], V2[0], V2[1], V2[2], V2[3]);

    V1[2] = *AY;  // V1[2] = V2[2] (7)
    V1[1] = --*AY;  // Decrementa *AY (V2[2]), ahora 6, y asigna a V1[1]

    AX = AX + 1;  // AX ahora apunta fuera de los límites de V1 (puede ser peligroso)

    if (AX < &V1[4]) {  // Verifica si AX sigue dentro de los límites de V1
        V1[3] = *AX;  // Esto solo se ejecuta si AX es seguro
    }

    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d V1[3]=%d\tV2[0]=%d V2[1]=%d V2[2]=%d V2[3]=%d\n",
           V1[0], V1[1], V1[2], V1[3], V2[0], V2[1], V2[2], V2[3]);
}
