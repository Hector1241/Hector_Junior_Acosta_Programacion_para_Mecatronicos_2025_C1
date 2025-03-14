#include <stdio.h>

int main() {
    char marcaModelo[100];  // Para almacenar el nombre y modelo del carro
    double kilometraje;      // Para almacenar el kilometraje recorrido
    double consumoPorKm;     // Para almacenar el consumo de combustible (en galones por km)
    double precioPorGalon;   // Para almacenar el precio del combustible por gal�n

    // Solicitar el precio del gal�n
    printf("Ingrese el precio del combustible por galon: ");
    scanf("%lf", &precioPorGalon);

    // Solicitar la marca y modelo del veh�culo
    printf("Ingrese la marca y modelo del carro: ");
    getchar();  // Limpiar el buffer de entrada
    fgets(marcaModelo, sizeof(marcaModelo), stdin);  // Leer la l�nea completa para la marca y modelo

    // Solicitar el kilometraje recorrido
    printf("Ingrese el kilometraje recorrido (en km): ");
    scanf("%lf", &kilometraje);

    // Solicitar el consumo de combustible en galones por km
    printf("Ingrese el consumo de combustible (en galones por km): ");
    scanf("%lf", &consumoPorKm);

    // Calcular el costo total
    double costoTotal = consumoPorKm * kilometraje * precioPorGalon;

    // Imprimir el reporte
    printf("\nReporte de consumo de combustible:\n");
    printf("Marca y modelo: %s", marcaModelo);
    printf("Kilometraje: %.2f km\n", kilometraje);
    printf("Costo por galon: $%.2f\n", precioPorGalon);
    printf("Costo total: $%.2f\n", costoTotal);

    return 0;
}
