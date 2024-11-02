#include <stdio.h>
#include "miCasaHogwarts.h"

// gcc mainCasaHogwarts.c -L. -lmiCasaHogwarts -o mainCasaHogwarts
//./mainCasaHogwarts

int main()
{

    guardarPuntos(CasaHogwarts *CasaHogwarts);
    leerCasas(CasaHogwarts *casaHogwarts, FILE *file);
    cargarPuntos(CasaHogwarts casaHogwarts[], int *opcion, FILE *file);


    return 0;
}