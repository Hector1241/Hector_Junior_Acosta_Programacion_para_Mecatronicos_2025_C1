#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VEHICULOS 100

typedef struct {
    char marca[50];
    char modelo[50];
    float consumo;
} Vehiculo;

Vehiculo vehiculos[MAX_VEHICULOS];
int totalVehiculos = 0;

void registrarVehiculo() {
    if (totalVehiculos >= MAX_VEHICULOS) {
        printf("No se pueden registrar más vehículos.\n");
        return;
    }
    printf("Ingrese la marca del vehículo: ");
    scanf(" %49s", vehiculos[totalVehiculos].marca);
    printf("Ingrese el modelo del vehículo: ");
    scanf(" %49s", vehiculos[totalVehiculos].modelo);
    printf("Ingrese el consumo de combustible (galones por km): ");
    scanf("%f", &vehiculos[totalVehiculos].consumo);
    totalVehiculos++;
    printf("Vehículo registrado correctamente.\n");
}

void calcularCosto() {
    if (totalVehiculos == 0) {
        printf("No hay vehículos registrados.\n");
        return;
    }
    float precioGalon, kilometraje;
    printf("Ingrese el precio del combustible por galón: ");
    scanf("%f", &precioGalon);
    printf("Ingrese el kilometraje a recorrer: ");
    scanf("%f", &kilometraje);

    printf("\n--- Reporte de Consumo ---\n");
    for (int i = 0; i < totalVehiculos; i++) {
        float consumoTotal = vehiculos[i].consumo * kilometraje;
        float costoTotal = consumoTotal * precioGalon;
        printf("Marca: %s, Modelo: %s\n", vehiculos[i].marca, vehiculos[i].modelo);
        printf("Kilometraje: %.2f km\n", kilometraje);
        printf("Costo por galón: $%.2f\n", precioGalon);
        printf("Costo total: $%.2f\n\n", costoTotal);
    }
}

void menu() {
    int opcion;
    while (1) {
        printf("\n1. Registrar vehículo\n");
        printf("2. Calcular costo de combustible\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                registrarVehiculo();
                break;
            case 2:
                calcularCosto();
                break;
            case 3:
                printf("Saliendo...\n");
                exit(0);
            default:
                printf("Opción no válida, intente de nuevo.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
