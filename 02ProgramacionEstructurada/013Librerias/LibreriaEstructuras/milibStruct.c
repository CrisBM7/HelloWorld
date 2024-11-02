#include "milibStruct.h"
#include <stdio.h>
#include <math.h>

// gcc -c milibStruct.c -o milibStruct.o
// ar rcs libmilibStruct.a milibStruct.o

// Implementacion de la funcion para crear un punto
Punto crearPunto(int x, int y) {
    Punto p;
    p.x = x;
    p.y = y;
    return p;
}

// Funcion para imprimir las coordenadas del punto
void imprimirPunto(Punto p) {
    printf("Punto(%d, %d)\n", p.x, p.y);
}

// Funcion para calcular la distancia al origen
float distanciaAlOrigen(Punto p) {
    return sqrt(p.x * p.x + p.y * p.y);
}