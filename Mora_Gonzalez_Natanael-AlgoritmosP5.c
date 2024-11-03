#include <stdio.h>
#include <stdlib.h>

/*Estructura de nodo para una lista vinculada
Cada nodo que contiene un valor entero 'val' y un puntero 'next'
que apunta al siguiente nodo en la lista*/
struct ListNode {
    int val;
    struct ListNode* next;
};//ListNode

/*Función para crear un nuevo nodo de lista que recibe como parametro un valor
entero que contendrá el nuevo nodo y retornará un puntero al nodo recien
creado, cuyo valor es 'value' y 'next' es NULL*/ 
struct ListNode* newNode(int value) {
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val = value;
    temp->next = NULL;
    return temp;
}//newNode

/* Función para convertir un arreglo a una lista vinculada que recibe como
parametro un arreglo de enteros 'arr' y su tamaño 'size' y retorna un puntero
al primer nodo de la lista vinculada creada a partir del arreglo*/
struct ListNode* arrayToList(int* arr, int size) {
    if (size == 0) return NULL;
    struct ListNode* head = newNode(arr[0]);
    struct ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = newNode(arr[i]);
        current = current->next;
    }//for
    return head;
}//arrayToList

/* Función para fusionar dos listas vinculadas ordenadas que recibe como parametros
punteros a dos listas vinculadas 'l1' y 'l2' (ambas deben de estar ordenadas) y retornará
un puntero a la cabeza de la nuevva lista que contiene todos los elementos de
'l1' y l2' en orden*/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }//if 
    else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }//else
}//mergeTwoLists

/* Función para fusionar k listas vinculadas que recibe como parametros arreglo de punteros
a listas vinculadas 'lists' y el numero de listas 'k' y retornara un puntero a la cabeza de
una lista fusionada que contiene todos los elementos en orden ascendente*/
struct ListNode* mergeKLists(struct ListNode** lists, int k) {
    if (k == 0) return NULL;
    if (k == 1) return lists[0];

    int interval = 1;
    //Fusiona pares de listas en intervalos crecientes hasta reducir todas las listas a una sola
    while (interval < k) {
        for (int i = 0; i < k - interval; i += interval * 2) {
            lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
        }//for
        interval *= 2;
    }//while
    return lists[0];
}//mergeLists

// Función para imprimir la lista vinculada que recibe como parametros 
//puntero al primer nodo de la lista vinculada 'node'

void printList(struct ListNode* node) {
    while (node) {
        printf("%d", node->val);
        if (node->next != NULL) {
            printf(" -> ");
        }//if
        node = node->next;
    }//while
    printf("\n");
}//printList

int main() {
    int k = 3;

    //Areglos a que pasaran a listas vinculadas
    int arr1[] = {1, 4, 5};
    int arr2[] = {1, 1, 6};
    int arr3[] = {1, 6};

    // Convertir los arreglos a listas vinculadas
    struct ListNode* lists[k];
    lists[0] = arrayToList(arr1, sizeof(arr1) / sizeof(arr1[0]));
    lists[1] = arrayToList(arr2, sizeof(arr2) / sizeof(arr2[0]));
    lists[2] = arrayToList(arr3, sizeof(arr3) / sizeof(arr3[0]));

    // Fusionar las listas y mostrar el resultado
    struct ListNode* mergedList = mergeKLists(lists, k);
    printList(mergedList);

    return 0;
}//main
