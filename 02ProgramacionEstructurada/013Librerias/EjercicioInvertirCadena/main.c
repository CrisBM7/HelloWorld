
#include <stdio.h>
#include "milib.h"

// gcc main.c -L. -lmilib -o main
//./main

int main()
{
    bitacora("Entra al programa...");
    bitacora("Saludo");
    saludar("Mundo");

    bitacora("Impresion de arreglo");
    int lenght = 5;
    int arr[] = {1, 2, 3, 4, 5};

    imprimirArregloInt(arr, lenght);

    bitacora("Numero mayor");
    int a = 5, b = 7;

    printf("Mayor entre %d y %d = %d\n", a, b, mayorEntre(a, b));

    if (abrirArchivo("Archivo.txt") == 0)
    {
        bitacora("Se pudo abrir el archivo");
    }
    else
    {
        bitacora("No se pudo abrir el archivo");
    }

    char *cadenaReservada = reservarMemoria(5);
    if (cadenaReservada != NULL)
    {
        bitacora("Se pudo reservar la memoria");
    }
    else
    {
        bitacora("No se pudo reservar la memoria");
    }

    if (esPar(2))
    {
        bitacora("Es par");
    }
    else
    {
        bitacora("No es Par");
    }

    bitacora("Invertir Palabra");

    char s[] = "Hola\0";
    invertirCadena(s);

    
    printf("%s", s);

    bitacora("Saliendo del programa...");

    return 0;
}