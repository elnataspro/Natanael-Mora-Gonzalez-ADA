#include <stdio.h>
#include <stdlib.h> // Necesario para usar system("pause");

// Denominaciones disponibles de monedas y billetes
int denominaciones[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
int tam = sizeof(denominaciones) / sizeof(denominaciones[0]);

// Función recursiva para encontrar el número mínimo de monedas/billetes
int encontrarCambioRecursivo(int valor, int indice) {
    if (valor == 0) {
        return 0; // Caso base: si el valor es 0, no necesitamos más monedas/billetes
    }

    // Buscar la mayor denominación que sea menor o igual al valor actual
    while (valor < denominaciones[indice]) {
        indice++;
    }

    // Restamos esa denominación del valor y hacemos una llamada recursiva
    printf("%d ", denominaciones[indice]);
    return 1 + encontrarCambioRecursivo(valor - denominaciones[indice], indice);
}

int main() {
    int valor;

    // Solicitar al usuario ingresar el valor
    printf("Ingrese el valor en pesos: ");
    scanf("%d", &valor);

    // Mostrar el desglose de monedas/billetes
    printf("El valor dado: %d\n", valor);
    printf("Se necesitan las siguientes monedas/billetes:\n");

    // Llamada a la función recursiva
    int totalMonedas = encontrarCambioRecursivo(valor, 0);

    // Mostrar el número mínimo de monedas/billetes
    printf("\nNúmero mínimo de monedas/billetes necesarios: %d\n", totalMonedas);

    // Pausar la consola
    system("pause");

    return 0;
}