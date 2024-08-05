#include <stdio.h>

void duplicarValor(float *x, float *y, float *z)
{
    *z = (*x)+(*y);
    *z = (*z)/2;
}

int main()
{
    float x = 4.00;
    float y = 6.00;
    float z = 0;

    printf("Valor 1: %.2f", x);
    printf("\nValor 2: %.2f", y);

    duplicarValor(&x, &y, &z);

    printf("\nPromedio: %.2f", z);

    return 0;
}