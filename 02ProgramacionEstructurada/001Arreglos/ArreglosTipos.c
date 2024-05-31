#include <stdio.h>

int main()
{
    // Arreglo de caracteres
    char caracteres[5] = {'a', 'b', 'c', 'd', 'e'};

    // Arreglo de enteros
    int enteros[5] = {10, 20, 30, 40, 50};

    // Arreglo de números de punto flotante
    float flotantes[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

    // Impresión de los elementos de los arreglos
    printf("Arreglo de caracteres:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%c ", caracteres[i]);
    }
    printf("\n");

    printf("Arreglo de enteros:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", enteros[i]);
    }
    printf("\n");

    printf("Arreglo de números de punto flotante:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%.1f ", flotantes[i]);
    }
    printf("\n");

    return 0;
}
