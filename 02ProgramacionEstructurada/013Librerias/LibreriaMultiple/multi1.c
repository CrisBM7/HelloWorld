#include "multi1.h"
#include <stdio.h>

// gcc -c multi1.c -o multi1.o
// ar rcs libmulti1.a multi1.o

void saludar(char *nombre)
{
    printf("Hola, %s!\n", nombre);
}