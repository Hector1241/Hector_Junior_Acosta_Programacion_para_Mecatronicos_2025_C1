#include <stdio.h>

// Prototipo de funci�n: se pasa un archivo como par�metro.
void promedio(FILE *);

int main(void) {
    FILE *ar;

    // Abrir el archivo en modo lectura
    if ((ar = fopen("arc9.txt", "r")) != NULL) {
        promedio(ar);  // Llamar a la funci�n promedio pasando el archivo como par�metro
        fclose(ar);    // Cerrar el archivo despu�s de la lectura
    } else {
        printf("No se puede abrir el archivo\n");
    }

    return 0;
}

// Funci�n para calcular e imprimir los promedios de los alumnos
void promedio(FILE *ar1) {
    int i, j, n, mat;
    float pro, cal;

    // Leer la cantidad de alumnos
    fscanf(ar1, "%d", &n);

    for (i = 0; i < n; i++) {
        fscanf(ar1, "%d", &mat);  // Leer matr�cula del alumno
        printf("%d\t", mat);

        pro = 0;
        for (j = 0; j < 5; j++) {  // Leer 5 calificaciones
            fscanf(ar1, "%f", &cal);
            pro += cal;
        }

        // Imprimir matr�cula y promedio calculado
        printf("\t %.2f\n", pro / 5);
    }
}
