#include <stdio.h>
/* Alumnos.
El programa almacena variables de tipo estructura alumno en un archivo. */
typedef struct
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

/* Declaración de la estructura alumno. */
void escribe(FILE *); /* Prototipo de función. */

int main(void) /* Se cambia void main por int main para cumplir con el estándar C */
{
    FILE *ar;
    if ((ar = fopen("ad1.dat", "w")) != NULL) /* Se corrigieron las comillas incorrectas */
        escribe(ar);
    else
        printf("\nEl archivo no se puede abrir");
    fclose(ar);
    return 0; /* Se agrega return 0 para indicar terminación correcta */
}

void escribe(FILE *ap)
/* Esta función sirve para leer los datos de los alumnos utilizando una
estructura tipo alumno, que se almacenará posteriormente en un archivo. */
{
    alumno alu;
    int i = 0, r;
    printf("\n¿Desea ingresar información sobre alumnos? (Sí-1  No-0):  ");
    scanf("%d", &r);
    while (r)
    {
        i++;
        printf("Matrícula del alumno %d: ", i);
        scanf("%d", &alu.matricula);
        printf("Nombre del alumno %d: ", i);
        fflush(stdin);
        fgets(alu.nombre, 20, stdin); /* Se reemplaza gets por fgets para evitar desbordamientos */
        printf("Carrera del alumno %d: ", i);
        scanf("%d", &alu.carrera);
        printf("Promedio del alumno %d: ", i);
        scanf("%f", &alu.promedio);
        fwrite(&alu, sizeof(alumno), 1, ap); /* Se corrigió ssiizzeeooff por sizeof */
        printf("\n¿Desea ingresar información sobre más alumnos? (Sí-1 No-0):  ");
        scanf("%d", &r);
    }
}
