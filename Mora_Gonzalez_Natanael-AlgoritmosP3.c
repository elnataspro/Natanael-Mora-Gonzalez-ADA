#include <stdio.h>
#include <time.h>

// Función recursiva para calcular Fibonacci
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    clock_t start, end;
    double timeTaken;
    
    printf("Introduce el valor de n para Fibonacci: ");
    scanf("%d", &n);
    
    // Medir el tiempo de ejecución
    start = clock();
    int result = fibonacci(n);
    end = clock();
    
    // Calcular el tiempo en milisegundos
    timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    
    printf("Fibonacci(%d) = %d\n", n, result);
    printf("Tiempo de ejecución: %.6f ms\n", timeTaken);
    
    return 0;
}
