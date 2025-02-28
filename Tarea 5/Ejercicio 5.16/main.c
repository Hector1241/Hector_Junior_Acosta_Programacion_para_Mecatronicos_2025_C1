#include <stdio.h>

/* Apuntadores y arreglos */
void main(void) {
    int V1[4] = {2, 3, 4, 7};
    int V2[4] = {6, 0, 0, 0};  // Se inicializan todos los elementos

    int *AX, *AY;
    AX = &V1[3];
    AY = &V2[2];  // Apunta a V2[2], ahora seguro ya que está inicializado

    V1[V2[0] - V1[2]] = *AY;  // V2[0] - V1[2] = 6 - 4 = 2 (V1[2] se modifica)
    *AY = *AX - V1[0];        // *AY (V2[2]) = V1[3] - V1[0] = 7 - 2 = 5

    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d V1[3]=%d\tV2[0]=%d V2[1]=%d V2[2]=%d V2[3]=%d",
           V1[0], V1[1], V1[2], V1[3], V2[0], V2[1], V2[2], V2[3]);

    V2[1] = ++*AX;  // Incrementa V1[3] antes de asignarlo a V2[1]
    V2[3] = (*AY)++; // Usa V2[2] (5) y luego lo incrementa a 6
    *AX += 2;        // Suma 2 a V1[3] (ahora 10)

    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d V1[3]=%d\tV2[0]=%d V2[1]=%d V2[2]=%d V2[3]=%d\n",
           V1[0], V1[1], V1[2], V1[3], V2[0], V2[1], V2[2], V2[3]);
}
