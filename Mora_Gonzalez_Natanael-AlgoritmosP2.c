#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

// Función para fusionar dos mitades de un arreglo (utilizada en Merge Sort)
void merge(int array[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Crear arreglos temporales
    int L[n1], R[n2];

    // Copiar los datos a los arreglos temporales L[] y R[]
    for (i = 0; i < n1; i++){
        L[i] = array[left + i];
    }//for
    for (j = 0; j < n2; j++){
        R[j] = array[mid + 1 + j];
    }//for

    // Fusionar los arreglos temporales de nuevo en array[left..right]
    i = 0;  // Índice inicial del primer subarreglo
    j = 0;  // Índice inicial del segundo subarreglo
    k = left;  // Índice inicial del subarreglo fusionado
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }//if
        else {
            array[k] = R[j];
            j++;
        }//else
        k++;
    }//while

    // Copiar los elementos restantes de L[], si hay alguno
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }//while

    // Copiar los elementos restantes de R[], si hay alguno
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }//while
}//merge

// Función principal que implementa Merge Sort
void mergeSort(int array[], int left, int right) {
    // Caso base. Si el subarreglo tiene uno o menos elementos
    if (left >= right) {
        return;
    }//if

    // Dividir el arreglo en dos mitades
    int mid = left + (right - left) / 2;

    // Llamada recursiva para obtener la primera mitad
    mergeSort(array, left, mid);

    // Llamada recursiva para obtener la segunda mitad
    mergeSort(array, mid + 1, right);

    // Fusionar las dos mitades ordenadas
    merge(array, left, mid, right);
}//mergeSort

// Función para fusionar dos arreglos ordenados
void fusionarArreglos(int* nums1, int m, int* nums2, int n, int* resultado) {
    int i = 0, j = 0, k = 0;

    // Fusionar los arreglos hasta que se procesen todos los elementos de ambos
    while (i < m && j < n) {
        if (nums1[i] <= nums2[j]) {
            resultado[k++] = nums1[i++];
        } else {
            resultado[k++] = nums2[j++];
        }
    }//while

    // Si quedan elementos en nums1, copiarlos
    while (i < m) {
        resultado[k++] = nums1[i++];
    }//while

    // Si quedan elementos en nums2, copiarlos
    while (j < n) {
        resultado[k++] = nums2[j++];
    }//while
}//fusionarArreglos

// Función para calcular la mediana de dos arreglos
double calcularMediana(int* nums1, int m, int* nums2, int n) {
    int totalSize = m + n;
    int* mergedArray = (int*)malloc(totalSize * sizeof(int));

    // Ordenar ambos arreglos con la función mergeSort
    mergeSort(nums1, 0, m - 1);
    mergeSort(nums2, 0, n - 1);

    // Fusionar los arreglos ordenados
    fusionarArreglos(nums1, m, nums2, n, mergedArray);

    // Imprimir el arreglo fusionado
    printf("Arreglo fusionado: [");
    for (int i = 0; i < totalSize; i++) {
        printf("%d", mergedArray[i]);
        if (i != totalSize - 1) {
            printf(", ");
        }//if
    }//for
    printf("]\n");
    printf("Numero total de elementos en el arreglo: %d\n", totalSize);

    // Calcular la mediana
    double mediana;
    if (totalSize % 2 == 0) {
        mediana = (mergedArray[totalSize / 2 - 1] + mergedArray[totalSize / 2]) / 2.0;
    }//if 
    else {
        mediana = mergedArray[totalSize / 2];
    }//else

    free(mergedArray);
    return mediana;
}//calcularMediana

int main() {
    // Variables para medir el tiempo
    clock_t start, end;
    double cpu_time_used;

    int nums1[] = {147, 234, 158, 76, 135, 82, 42, 199, 55, 3, 87, 187, 106, 75, 36, 11, 121, 90, 148, 25, 201, 97, 41, 112, 58, 143, 
               197, 26, 84, 28, 54, 139, 7, 45, 110, 38, 105, 60, 27, 98, 173, 20, 6, 190, 131, 109, 53, 194, 83, 17, 170, 4, 
               152, 19, 129, 48, 192, 5, 116, 151, 57, 10, 69, 35, 44, 181, 99, 123, 165, 89, 74, 186, 138, 161, 71, 130, 12, 
               13, 46, 172, 2, 64, 56, 155, 136, 141, 102, 120, 31, 185, 156, 113, 111, 108, 169, 77, 157, 160, 119, 72, 100, 
               15, 59, 154, 204, 205, 142, 162, 182, 153, 65, 86, 33, 185, 52, 150, 39, 104, 88, 175, 178, 1, 140, 8, 27, 200, 
               16, 43, 206, 85, 189, 178, 68, 22, 50, 214, 161, 207, 147, 83, 115, 35, 51, 195, 204, 26, 110};
    int nums2[] = {15, 62, 206, 128, 37, 56, 102, 144, 3, 54, 190, 94, 199, 101, 75, 22, 119, 41, 5, 205, 10, 143, 81, 173, 100, 
               17, 160, 89, 25, 18, 58, 211, 109, 26, 142, 65, 170, 147, 66, 23, 110, 131, 60, 99, 21, 141, 178, 71, 95, 114, 
               45, 9, 139, 181, 121, 69, 36, 107, 168, 156, 113, 155, 193, 146, 35, 52, 93, 80, 116, 112, 27, 177, 7, 123, 203, 
               170, 72, 19, 176, 68, 34, 50, 214, 208, 150, 40, 67, 12, 198, 129, 209, 108, 184, 1, 84, 191, 63, 13, 167, 165, 
               48, 59, 130, 105, 153, 63, 70, 164, 78, 91, 132, 73, 9, 87, 120};

    int m = sizeof(nums1) / sizeof(nums1[0]);
    int n = sizeof(nums2) / sizeof(nums2[0]);

    // Iniciar la medición del tiempo
    start = clock();

    // Calcular la mediana de los dos arreglos
    double mediana = calcularMediana(nums1, m, nums2, n);

    // Finalizar la medición del tiempo
    end = clock();
    // Convertir de segundos a milisegundos multiplicando por 1000
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

    // Mostrar la mediana y el tiempo de ejecución en milisegundos
    printf("La mediana es: %.2f\n", mediana);
    printf("Tiempo de ejecución: %f milisegundos\n", cpu_time_used);

    return 0;
}