#include <stdio.h>

int main() {
    int numeroDeFilas = 0; // Número de filas en el triángulo de Pascal
    int filaActual, columnaActual, valor, espaciosAntes;
    
    if(numeroDeFilas >= 1 && numeroDeFilas <= 30){
    // Iterar sobre cada fila
        for (filaActual = 0; filaActual < numeroDeFilas; filaActual++) {
            // Inicializar el primer valor en la fila como 1
            valor = 1;
    
            // Calcular y agregar los espacios antes de los números (centrar el triángulo)
            espaciosAntes = (numeroDeFilas - filaActual - 1) * 2;  // Ajustar el número de espacios para centrar la fila
            for (columnaActual = 0; columnaActual < espaciosAntes; columnaActual++) {
                printf(" ");  // Imprimir los espacios
            }//for
    
            // Imprimir los valores en la fila del triángulo de Pascal
            for (columnaActual = 0; columnaActual <= filaActual; columnaActual++) {
                printf("%4d", valor);  // Imprimir el valor de la celda del triángulo
                // Calcular el siguiente valor en la fila usando la fórmula del Triángulo de Pascal
                valor = valor * (filaActual - columnaActual) / (columnaActual + 1);
            }//for
    
            // Imprimir un salto de línea para la siguiente fila
            printf("\n");
        }//for
    }//if
        else{
            printf("El numero de columnas esta fuera del rango permitido");
        }//else
    return 0;
}//main