#include "milib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// gcc -c milib.c -o milib.o
// ar rcs libmilib.a milib.o

void saludar(char *nombre)
{
    printf("Hola, %s!\n", nombre);
}

void bitacora(char mensaje[])
{
    // Obtén el tiempo actual
    time_t t;
    time(&t);

    // Convierte el tiempo a una estructura tm
    struct tm *tm_info = localtime(&t);

    // Imprime la fecha y hora
    printf("\n%04d-%02d-%02d %02d:%02d:%02d - %s\n\n",
           tm_info->tm_year + 1900, // Año desde 1900
           tm_info->tm_mon + 1,     // Mes (0-11)
           tm_info->tm_mday,        // Día del mes
           tm_info->tm_hour,        // Hora (0-23)
           tm_info->tm_min,         // Minutos (0-59)
           tm_info->tm_sec,         // Segundos (0-59)
           mensaje);
}

void imprimirArregloInt(int numeros[], int i)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", numeros[i]);
    }
    printf("\n");
}

int mayorEntre(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int abrirArchivo(char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL)
    {
        return -1; // Error al abrir el archivo
    }
    // Operaciones exitosas con el archivo
    fclose(archivo);
    return 0; // Éxito
}

char *reservarMemoria(int tamano)
{
    char *mem = (char *)malloc(tamano);
    if (mem == NULL)
    {
        // Error al asignar memoria
        return NULL;
    }
    return mem; // Éxito
}

int esPar(int numero)
{
    if (numero % 2 == 0){
        return 1;
    }
    else
    {
        return 0;
    }
}