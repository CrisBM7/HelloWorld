#include <stdio.h>
#include "miFutbol.h"

// gcc mainFutbol.c -L. -lmiFutbol -o mainFutbol
//./mainFutbol

int main()
{

    guardarPuntos(CasaHogwarts *CasaHogwarts);
    leerCasas(CasaHogwarts *casaHogwarts, FILE *file);
    cargarPuntos(CasaHogwarts casaHogwarts[], int *opcion, FILE *file);


    return 0;
}