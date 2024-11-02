#ifndef MICASAHOGWARTS_H
#define MICASAHOGWARTS_H

typedef struct
{
    char nombre[50];
    int puntos;
} CasaHogwarts;


void miFflush();
void guardarPuntos(CasaHogwarts *CasaHogwarts);
int leerCasas(CasaHogwarts *casaHogwarts, FILE *file);
void cargarPuntos(CasaHogwarts casaHogwarts[], int *opcion, FILE *file);

#endif