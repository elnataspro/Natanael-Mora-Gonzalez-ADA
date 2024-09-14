#include <stdio.h>
/*La funcion removerDuplicados que toma como parametros un puntero nums al arreglo
 y numsSize que es el tamaño del arreglo*/
int removerDuplicados(int* nums, int numsSize){
    if(numsSize == 0) //Caso Base. Si numsSize == 0, entonces no hay elementos en el arreglo y no se retorna nada
        return 0;
    int k = 1; //numero de elementos unicos
    int i = 0;
    for(i=1; i< numsSize; i++){
        if(nums[i] != nums[i - 1]){//Se compara el elemento actual con el anterior
            nums[k] = nums[i]; //Se mueve el elemento unico al siguiente indice k
            k++;
        }//if
    }//for 
            return k;
}//removerDuplicados

int main(){
    int nums[] = {0,1,1,3,3,5,5,10,10,50,50,110,110};
    int numsSize = sizeof(nums)/ sizeof(nums[0]);
    
    int k = removerDuplicados(nums, numsSize);
    int i = 0;
    
    printf("Numero de elementos unicos: %d\n", k);
    printf("Arreglo modificado: \n");
    for(i; i < k; i++){
            printf("%d \n", nums[i]);
            }//for
    printf("\n");
}//main
