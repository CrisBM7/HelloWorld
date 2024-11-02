#ifndef MILIB_H
#define MILIB_H

// Declaración de una función
void saludar(char *nombre);

// Ejemplos
void bitacora(char mensaje[]);
void imprimirArregloInt(int numeros[], int i);
int mayorEntre(int a, int b);

// Convenciones de retorno
int abrirArchivo(char *nombreArchivo);
char *reservarMemoria(int tamano);
int esPar(int numero);

#endif
