#ifndef MILIBSTRUCT_H
#define MILIBSTRUCT_H


// Definicion de la estructura
typedef struct {
    int x;
    int y;
} Punto;

// Declaraciones de funciones
Punto crearPunto(int x, int y);
void imprimirPunto(Punto p);
float distanciaAlOrigen(Punto p);

#endif
