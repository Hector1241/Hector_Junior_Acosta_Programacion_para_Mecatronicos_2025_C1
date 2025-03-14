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

/* Declaraci�n de la estructura alumno. */
void escribe(FILE *); /* Prototipo de funci�n. */

int main(void) /* Se cambia void main por int main para cumplir con el est�ndar C */
{
    FILE *ar;
    if ((ar = fopen("ad1.dat", "w")) != NULL) /* Se corrigieron las comillas incorrectas */
        escribe(ar);
    else
        printf("\nEl archivo no se puede abrir");
    fclose(ar);
    return 0; /* Se agrega return 0 para indicar terminaci�n correcta */
}

void escribe(FILE *ap)
/* Esta funci�n sirve para leer los datos de los alumnos utilizando una
estructura tipo alumno, que se almacenar� posteriormente en un archivo. */
{
    alumno alu;
    int i = 0, r;
    printf("\n�Desea ingresar informaci�n sobre alumnos? (S�-1  No-0):  ");
    scanf("%d", &r);
    while (r)
    {
        i++;
        printf("Matr�cula del alumno %d: ", i);
        scanf("%d", &alu.matricula);
        printf("Nombre del alumno %d: ", i);
        fflush(stdin);
        fgets(alu.nombre, 20, stdin); /* Se reemplaza gets por fgets para evitar desbordamientos */
        printf("Carrera del alumno %d: ", i);
        scanf("%d", &alu.carrera);
        printf("Promedio del alumno %d: ", i);
        scanf("%f", &alu.promedio);
        fwrite(&alu, sizeof(alumno), 1, ap); /* Se corrigi� ssiizzeeooff por sizeof */
        printf("\n�Desea ingresar informaci�n sobre m�s alumnos? (S�-1 No-0):  ");
        scanf("%d", &r);
    }
}
