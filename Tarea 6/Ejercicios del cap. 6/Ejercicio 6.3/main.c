#include <stdio.h>

/* Universidad.
   El programa, al recibir información sobre el número de alumnos que han ingresado
   a sus ocho diferentes carreras en los dos semestres lectivos de los últimos
   cinco años, obtiene información útil para el departamento de escolar. */

#define F 8  // Número de carreras
#define C 2  // Número de semestres
#define P 5  // Número de años

// Prototipos de funciones
void Lectura(int [][C][P], int, int, int);
void Funcion1(int[][C][P], int, int, int);
void Funcion2(int [][C][P], int, int, int);
void Funcion3(int[][C][P], int, int, int);

int main(void) {
    int UNI[F][C][P];

    Lectura(UNI, F, C, P);
    Funcion1(UNI, F, C, P);
    Funcion2(UNI, F, C, P);
    Funcion3(UNI, 6, C, P);
    /* Se coloca el 6 como parámetro ya que es la clave de la Ingeniería en Computación. */

    return 0;
}

void Lectura(int A[][C][P], int FI, int CO, int PR) {
    /* La función Lectura se utiliza para leer un arreglo tridimensional de tipo
       entero de FI filas, CO columnas y PR profundidad.
       Al ser tridimensional, se necesitan tres ciclos para recorrer el arreglo. */

    int K, I, J;
    for (K = 0; K < PR; K++)
        for (I = 0; I < FI; I++)
            for (J = 0; J < CO; J++) {
                printf("Año: %d\tCarrera: %d\tSemestre: %d: ", K + 1, I + 1, J + 1);
                scanf("%d", &A[I][J][K]);
            }
}

void Funcion1(int A[][C][P], int FI, int CO, int PR) {
    /* Esta función determina el año en el que ingresó el mayor número de alumnos a la universidad.
       El primer ciclo externo corresponde a los años. */

    int K, I, J, MAY = 0, AO = -1, SUM;

    for (K = 0; K < PR; K++) {
        // Por cada año, se suma el ingreso de los dos semestres de las ocho carreras.
        SUM = 0;
        for (I = 0; I < FI; I++)
            for (J = 0; J < CO; J++)
                SUM += A[I][J][K];

        if (SUM > MAY) {
            MAY = SUM;
            AO = K;
        }
    }

    printf("\nEl año con mayor ingreso de alumnos fue el año %d con %d alumnos.\n", AO + 1, MAY);
}
