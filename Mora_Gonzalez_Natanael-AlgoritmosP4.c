#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <time.h>

// Estructura para representar un punto en 2D
typedef struct {
    float x, y;
} Punto;

// Función para calcular la distancia euclidiana entre dos puntos
float distancia(Punto p1, Punto p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}//distancia

// Función para generar puntos aleatorios
void generarPuntos(Punto puntos[], int n) {
    for (int i = 0; i < n; i++) {
        puntos[i].x = (float)rand() / (float)(RAND_MAX / 100.0);
        puntos[i].y = (float)rand() / (float)(RAND_MAX / 100.0);
    }//for
}//generarPuntos

// Función para comparar puntos en base a la coordenada X
int compararX(const void *a, const void *b) {
    Punto *p1 = (Punto *)a;
    Punto *p2 = (Punto *)b;
    return (p1->x > p2->x) - (p1->x < p2->x);
}//compararX

// Función para comparar puntos en base a la coordenada Y
int compararY(const void *a, const void *b) {
    Punto *p1 = (Punto *)a;
    Punto *p2 = (Punto *)b;
    return (p1->y > p2->y) - (p1->y < p2->y);
}//compararY

// Función de fuerza bruta para encontrar la mínima distancia entre puntos
float fuerzaBruta(Punto puntos[], int n, Punto *p1, Punto *p2) {
    float minDist = FLT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            float dist = distancia(puntos[i], puntos[j]);
            if (dist < minDist) {
                minDist = dist;
                *p1 = puntos[i];
                *p2 = puntos[j];
            }//if
        }//for
    }//for
    return minDist;
}//fuerzaBruta

// Función para encontrar la distancia mínima en la franja central
float minDistFranja(Punto franja[], int n, float d, Punto *p1, Punto *p2) {
    float minDist = d;
    qsort(franja, n, sizeof(Punto), compararY); // Ordena por coordenada Y

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n && (franja[j].y - franja[i].y) < minDist; j++) {
            float dist = distancia(franja[i], franja[j]);
            if (dist < minDist) {
                minDist = dist;
                *p1 = franja[i];
                *p2 = franja[j];
            }//if
        }//for
    }//for
    return minDist;
}//minDistFranja

// Función principal de divide y vencerás
float puntosMasCercanosRec(Punto puntosX[], Punto puntosY[], int n, Punto *p1, Punto *p2) {
    // Si hay menos de 4 puntos, usa fuerza bruta
    if (n <= 3) {
        return fuerzaBruta(puntosX, n, p1, p2);
    }//puntosMasCercanosRec

    // Encuentra el punto medio
    int mitad = n / 2;
    Punto puntoMedio = puntosX[mitad];

    // Divide los puntos en dos mitades
    Punto puntosYIzq[mitad];
    Punto puntosYDer[n - mitad];
    int izqIdx = 0, derIdx = 0;
    for (int i = 0; i < n; i++) {
        if (puntosY[i].x <= puntoMedio.x) {
            puntosYIzq[izqIdx++] = puntosY[i];
        } else {
            puntosYDer[derIdx++] = puntosY[i];
        }
    }

    // Encuentra la distancia mínima en las dos mitades
    Punto pIzq1, pIzq2, pDer1, pDer2;
    float distIzq = puntosMasCercanosRec(puntosX, puntosYIzq, mitad, &pIzq1, &pIzq2);
    float distDer = puntosMasCercanosRec(puntosX + mitad, puntosYDer, n - mitad, &pDer1, &pDer2);

    // Determina la menor distancia entre las dos mitades
    float d = distIzq < distDer ? distIzq : distDer;
    *p1 = distIzq < distDer ? pIzq1 : pDer1;
    *p2 = distIzq < distDer ? pIzq2 : pDer2;

    // Construye la franja de puntos cercanos a la línea media
    Punto franja[n];
    int franjaSize = 0;
    for (int i = 0; i < n; i++) {
        if (fabs(puntosY[i].x - puntoMedio.x) < d) {
            franja[franjaSize++] = puntosY[i];
        }//if
    }//for

    // Encuentra la menor distancia en la franja
    return minDistFranja(franja, franjaSize, d, p1, p2);
}//puntosMasCercanosRec

// Función inicial que prepara los datos y llama al recursivo
float puntosMasCercanos(Punto puntos[], int n, Punto *p1, Punto *p2) {
    Punto puntosX[n];
    Punto puntosY[n];

    // Copia los puntos en dos arrays
    for (int i = 0; i < n; i++) {
        puntosX[i] = puntos[i];
        puntosY[i] = puntos[i];
    }//for

    // Ordena los puntos por coordenada X y Y
    qsort(puntosX, n, sizeof(Punto), compararX);
    qsort(puntosY, n, sizeof(Punto), compararY);

    // Llama a la función recursiva
    return puntosMasCercanosRec(puntosX, puntosY, n, p1, p2);
}//puntosMasCercanos

int main() {
    int n;
    Punto p1, p2;
    srand(time(0));  // Inicializa la semilla para los números aleatorios

    // Prueba con diferentes valores de n
    printf("Introduce el número de puntos n: ");
    scanf("%d", &n);

    Punto *puntos = (Punto *)malloc(n * sizeof(Punto));
    generarPuntos(puntos, n);

    clock_t start = clock();
    float minDist = puntosMasCercanos(puntos, n, &p1, &p2);
    clock_t end = clock();

    printf("El par de puntos más cercanos es: (%.2f, %.2f) y (%.2f, %.2f)\n", p1.x, p1.y, p2.x, p2.y);
    printf("Distancia mínima: %f\n", minDist);
    printf("Tiempo de ejecución: %f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(puntos);
    return 0;
}//main1
