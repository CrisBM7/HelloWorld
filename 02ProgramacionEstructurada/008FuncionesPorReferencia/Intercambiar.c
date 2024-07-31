#include <stdio.h>

// Función que intercambia los valores de dos enteros
void intercambiar(int *x, int *y)
{
    int z;
    z=*x;
    *x=*y;
    *y=z;
}

int main()
{
    int x = 10;
    int y = 20;

    printf("Antes de intercambiar: x = %d, y = %d\n", x, y);

    // Llamada a la función intercambiar pasando las direcciones de x y y
    intercambiar(&x, &y);

    printf("Después de intercambiar: x = %d, y = %d\n", x, y);

    return 0;
}
