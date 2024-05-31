#include <stdio.h>

int main()
{
    // Declaración e inicialización de un arreglo de enteros
    int miArreglo[5] = {10, 20, 30, 40, 50};

    int miArreglo2[5];

    miArreglo2[0] = 10;
    miArreglo2[1] = 20;
    miArreglo2[2] = 30;
    miArreglo2[3] = 40;
    miArreglo2[4] = 50;

    // Acceso e impresión de los elementos del arreglo
    printf("Elementos del arreglo miArreglo:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Elemento %d: %d\n", i, miArreglo[i]);
    }

    // Modificación de un elemento del arreglo
    miArreglo[2] = 35;

    printf("Ingrese el valor que ahora tendra \"miArreglo\" en la posicion 3 que es de hecho la 4 jaja: ");
    scanf("%d", &miArreglo[3]);

    // Acceso e impresión del arreglo modificado
    printf("\nElementos del arreglo miArreglo (después de la modificación):\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Elemento %d: %d\n", i, miArreglo[i]);
    }

    return 0;
}
