#include <stdio.h>

// Función para contar el número de subarreglos cuya media sea mayor o igual a 'threshold'
int numOfSubarrays(int nums[], int numsSize, int k, int threshold) {
    int l = 0;
    int r = 0;
    int cnt = 0;
    int sum = 0;

    // Inicializamos el primer subarreglo de tamaño 'k'
    while (r < k && r < numsSize) {
        sum += nums[r];
        r++;
    }//while

    // Calculamos la media del primer subarreglo y verificamos si cumple con el umbral
    int avg = sum / k;
    if (avg >= threshold) {
        cnt++;
    }//while

    // Continuamos con los siguientes subarreglos
    while (r < numsSize) {
        sum -= nums[l];  // Restamos el valor que sale del subarreglo
        sum += nums[r];  // Añadimos el nuevo valor al subarreglo
        avg = sum / k;   // Calculamos la nueva media
        if (avg >= threshold) {
            cnt++;
        }
        l++;
        r++;
    }//while

    return cnt;
}//numofSubarrays   

int main() {
    // Ejemplo de uso de la función numOfSubarrays
    int nums[] = {2,2,2,2,5,5,5,8};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 3;
    int threshold = 4;
    

    int result = numOfSubarrays(nums, numsSize, k, threshold);
    printf("Número de subarreglos: %d\n", result);

    return 0;
}//main
