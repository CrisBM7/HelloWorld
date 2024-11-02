
#include <stdio.h>
#include "multi1.h"
#include "multi2.h"

// gcc mainMulti.c -L. -lmulti1 -lmulti2 -o mainMulti
//./mainMulti

int main()
{
    saludar("Mundo");
    despedirse("Mundo");
    return 0;
}