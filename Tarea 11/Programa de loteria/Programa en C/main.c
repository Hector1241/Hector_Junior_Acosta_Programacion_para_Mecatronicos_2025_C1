//Características del programa
//Registro dinámico de jugadores.

//Sorteo de tres números (ORO, PLATA, BRONCE).

//Guarda los premios en archivo.

//Muestra en pantalla los números más frecuentes.

//Informa qué jugadores ganaron.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NAME 50
#define FILE_NAME "premios.txt"

// Estructura del cliente
typedef struct {
    char nombre[MAX_NAME];
    int numero_jugado;
} Cliente;

// Estructura para contar ocurrencias de premios
typedef struct {
    int numero;
    int frecuencia;
} Contador;

// Funciones
void jugar(Cliente **clientes, int *num_clientes);
void tirar_numeros(int *oro, int *plata, int *bronce);
void guardar_numeros(int oro, int plata, int bronce);
void listar_frecuencia();
void mostrar_resultados(Cliente *clientes, int num_clientes, int oro, int plata, int bronce);
int ya_contado(Contador *contadores, int size, int num);

int main() {
    Cliente *clientes = NULL;
    int num_clientes = 0;
    int oro = -1, plata = -1, bronce = -1;
    int opcion;

    srand(time(NULL));  // Inicializa la semilla para números aleatorios

    do {
        printf("\n---- MENU LOTERIA ----\n");
        printf("1. Jugar (Registrar Cliente)\n");
        printf("2. Tirar Números (Premios)\n");
        printf("3. Lista de Números Salidos (Frecuencia)\n");
        printf("4. Ver Ganadores\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar(); // Limpia buffer

        switch(opcion) {
            case 1:
                jugar(&clientes, &num_clientes);
                break;
            case 2:
                tirar_numeros(&oro, &plata, &bronce);
                guardar_numeros(oro, plata, bronce);
                break;
            case 3:
                listar_frecuencia();
                break;
            case 4:
                mostrar_resultados(clientes, num_clientes, oro, plata, bronce);
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida.\n");
        }

    } while(opcion != 5);

    free(clientes); // Liberar memoria al salir
    return 0;
}

// Registrar nuevo cliente
void jugar(Cliente **clientes, int *num_clientes) {
    Cliente nuevo;
    printf("Nombre del cliente: ");
    fgets(nuevo.nombre, MAX_NAME, stdin);
    nuevo.nombre[strcspn(nuevo.nombre, "\n")] = '\0'; // Quitar salto de línea

    printf("Ingrese un número del 0 al 99: ");
    scanf("%d", &nuevo.numero_jugado);
    getchar();

    if(nuevo.numero_jugado < 0 || nuevo.numero_jugado > 99) {
        printf("Número inválido. Debe estar entre 0 y 99.\n");
        return;
    }

    // Reasignar memoria para nuevo cliente
    *clientes = realloc(*clientes, (*num_clientes + 1) * sizeof(Cliente));
    (*clientes)[*num_clientes] = nuevo;
    (*num_clientes)++;

    printf("Cliente registrado con éxito.\n");
}

// Generar tres números aleatorios como premios
void tirar_numeros(int *oro, int *plata, int *bronce) {
    *oro = rand() % 100;
    do {
        *plata = rand() % 100;
    } while(*plata == *oro);
    do {
        *bronce = rand() % 100;
    } while(*bronce == *oro || *bronce == *plata);

    printf("Números premiados:\n");
    printf("ORO: %d\n", *oro);
    printf("PLATA: %d\n", *plata);
    printf("BRONCE: %d\n", *bronce);
}

// Guardar premios en archivo
void guardar_numeros(int oro, int plata, int bronce) {
    FILE *archivo = fopen(FILE_NAME, "a");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    fprintf(archivo, "%d %d %d\n", oro, plata, bronce);
    fclose(archivo);
}

// Mostrar frecuencia de números premiados
void listar_frecuencia() {
    FILE *archivo = fopen(FILE_NAME, "r");
    if (archivo == NULL) {
        printf("No hay premios registrados aún.\n");
        return;
    }

    Contador contadores[300] = {0};
    int total = 0, numero;

    while (fscanf(archivo, "%d", &numero) == 1) {
        int encontrado = 0;
        for (int i = 0; i < total; i++) {
            if (contadores[i].numero == numero) {
                contadores[i].frecuencia++;
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            contadores[total].numero = numero;
            contadores[total].frecuencia = 1;
            total++;
        }
    }
    fclose(archivo);

    // Ordenar por frecuencia (burbuja)
    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (contadores[i].frecuencia < contadores[j].frecuencia) {
                Contador temp = contadores[i];
                contadores[i] = contadores[j];
                contadores[j] = temp;
            }
        }
    }

    printf("\nNúmeros más frecuentes en los premios:\n");
    for (int i = 0; i < total; i++) {
        printf("Número: %d - Veces: %d\n", contadores[i].numero, contadores[i].frecuencia);
    }
}

// Mostrar ganadores según último sorteo
void mostrar_resultados(Cliente *clientes, int num_clientes, int oro, int plata, int bronce) {
    if (oro == -1 || plata == -1 || bronce == -1) {
        printf("Debe tirar los números primero.\n");
        return;
    }

    printf("\n---- RESULTADOS ----\n");
    for (int i = 0; i < num_clientes; i++) {
        if (clientes[i].numero_jugado == oro) {
            printf("%s ganó ORO con el número %d\n", clientes[i].nombre, oro);
        } else if (clientes[i].numero_jugado == plata) {
            printf("%s ganó PLATA con el número %d\n", clientes[i].nombre, plata);
        } else if (clientes[i].numero_jugado == bronce) {
            printf("%s ganó BRONCE con el número %d\n", clientes[i].nombre, bronce);
        }
    }
}
