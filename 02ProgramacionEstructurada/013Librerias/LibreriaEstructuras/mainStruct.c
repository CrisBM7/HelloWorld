
#include <stdio.h>
#include "milibStruct.h"

// gcc mainStruct.c -L. -lmilibStruct -o mainStruct
//./mainStruct

int main() {
    // Crear un punto
    Punto p = crearPunto(6, 4);
    
    // Imprimir el punto
    imprimirPunto(p);
    
    // Calcular la distancia al origen
    float distancia = distanciaAlOrigen(p);
    printf("Distancia al origen: %f\n", distancia);

    return 0;
}