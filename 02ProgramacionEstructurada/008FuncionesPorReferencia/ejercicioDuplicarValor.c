#include <stdio.h>

void duplicarValor(int *x)
{
    int z;
    *x = (*x)*2;
}

int main()
{
    int x = 10;

    printf("Antes de duplicar el valor: %d", x);

    duplicarValor(&x);

    printf("\nDespués de duplicar el valor: %d", x);

    return 0;
}