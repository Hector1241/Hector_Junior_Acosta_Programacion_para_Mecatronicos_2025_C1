#include <stdio.h>
#include <stdlib.h>
#include <math.h>  // Necesaria para sqrt()

// Definiciones de constantes para las operaciones
#define SUMA 1
#define RESTA 2
#define MULTIPLICACION 3
#define DIVISION 4
#define RAIZ_CUADRADA 5
#define POTENCIA_CUADRADO 6
#define SALIR 0
#define ERR_OK 0
#define ERR_DbyZ 1
#define ERR_NEG_ROOT 2

// Declaración de funciones
void EntradaNumeros(float *n1, float *n2);
void EntradaNumero(float *n);
int suma(float n1, float n2, float *pResult);
int resta(float n1, float n2, float *pResult);
int multiplicar(float n1, float n2, float *pResult);
int dividir(float n1, float n2, float *pResult);
int raizCuadrada(float n, float *pResult);
int potenciaCuadrado(float n, float *pResult);

int main() {
    float numero1 = 0.0, numero2 = 0.0, result = 0.0;
    int menu = 0, err = 0;

    do {
        printf("\n0 - Salir\n1 - Suma\n2 - Resta\n3 - Multiplicacion\n4 - Division\n");
        printf("5 - Raiz Cuadrada\n6 - Potencia al Cuadrado\n");
        printf("Seleccione una opcion: ");
        scanf("%i", &menu);

        if (menu == SUMA) {
            EntradaNumeros(&numero1, &numero2);
            err = suma(numero1, numero2, &result);
            printf("\nLa suma de %.2f + %.2f es: %.2f\n", numero1, numero2, result);
        }
        else if (menu == RESTA) {
            EntradaNumeros(&numero1, &numero2);
            err = resta(numero1, numero2, &result);
            printf("\nLa resta de %.2f - %.2f es: %.2f\n", numero1, numero2, result);
        }
        else if (menu == DIVISION) {
            EntradaNumeros(&numero1, &numero2);
            err = dividir(numero1, numero2, &result);
            if (err == ERR_DbyZ) {
                printf("\nError: Division por 0 no permitida.\n");
            } else {
                printf("\nLa division de %.2f / %.2f es: %.2f\n", numero1, numero2, result);
            }
        }
        else if (menu == MULTIPLICACION) {
            EntradaNumeros(&numero1, &numero2);
            err = multiplicar(numero1, numero2, &result);
            printf("\nLa multiplicacion de %.2f * %.2f es: %.2f\n", numero1, numero2, result);
        }
        else if (menu == RAIZ_CUADRADA) {
            EntradaNumero(&numero1);
            err = raizCuadrada(numero1, &result);
            if (err == ERR_NEG_ROOT) {
                printf("\nError: No se puede calcular la raiz cuadrada de un numero negativo.\n");
            } else {
                printf("\nLa raiz cuadrada de %.2f es: %.2f\n", numero1, result);
            }
        }
        else if (menu == POTENCIA_CUADRADO) {
            EntradaNumero(&numero1);
            err = potenciaCuadrado(numero1, &result);
            printf("\nLa potencia al cuadrado de %.2f es: %.2f\n", numero1, result);
        }
    } while (menu != SALIR);

    printf("\nFin del programa\n");
    return 0;
}

// Función para pedir dos números
void EntradaNumeros(float *n1, float *n2) {
    printf("\nIngrese numero 1: ");
    scanf("%f", n1);
    printf("Ingrese numero 2: ");
    scanf("%f", n2);
}

// Función para pedir un número
void EntradaNumero(float *n) {
    printf("\nIngrese un numero: ");
    scanf("%f", n);
}

// Función para sumar
int suma(float n1, float n2, float *pResult) {
    *pResult = n1 + n2;
    return ERR_OK;
}

// Función para restar
int resta(float n1, float n2, float *pResult) {
    *pResult = n1 - n2;
    return ERR_OK;
}

// Función para dividir
int dividir(float n1, float n2, float *pResult) {
    if (n2 == 0.0) {
        return ERR_DbyZ;
    } else {
        *pResult = n1 / n2;
        return ERR_OK;
    }
}

// Función para multiplicar
int multiplicar(float n1, float n2, float *pResult) {
    *pResult = n1 * n2;
    return ERR_OK;
}

// Función para calcular la raíz cuadrada
int raizCuadrada(float n, float *pResult) {
    if (n < 0) {
        return ERR_NEG_ROOT;
    } else {
        *pResult = sqrt(n);
        return ERR_OK;
    }
}

// Función para calcular la potencia al cuadrado
int potenciaCuadrado(float n, float *pResult) {
    *pResult = n * n;
    return ERR_OK;
}
