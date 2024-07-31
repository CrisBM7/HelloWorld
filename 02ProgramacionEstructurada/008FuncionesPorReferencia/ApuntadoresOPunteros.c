#include <stdio.h>

int main()
{
    int x = 10;    // Declaracion de una variable entera
    int *p = NULL; // Declaracion de un puntero a entero
    p = &x;        // Asignacion de la direccion de x

    printf("\n---Ejemplo Enteros---\n");
    printf("Valor de x: %d\n", x);            // Imprime el valor de x
    printf("Direccion de x: %p\n", &x);       // Imprime la direccion de x
    printf("Valor de p: %p\n", p);            // Imprime el valor de p (direccion de x)
    printf("Valor apuntado por p: %d\n", *p); // Imprime el valor apuntado por p (valor de x)

    // Modificacion del valor de x a traves del puntero p
    *p = 20;
    printf("Nuevo valor de x: %d\n", x); // Imprime el nuevo valor de x

    /**** Flotantes ****/

    float f = 3.14;
    float *pF = &f;

    printf("\n---Ejemplo Flotantes---\n");
    printf("Valor de f: %.2f\n", f);
    printf("Direccion de f: %p\n", &f);
    printf("Valor de pF: %p\n", pF);
    printf("Valor apuntado por pF: %.2f\n", *pF);

    /**** Caracteres ****/

    char c = 'A';
    char *pC = &c;

    printf("\n---Ejemplo Caracteres---\n");
    printf("Valor de c: %c\n", c);
    printf("Direccion de c: %p\n", &c);
    printf("Valor de pC: %p\n", pC);
    printf("Valor apuntado por pC: %c\n", *pC);

    /**** Arrays ****/

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int *pArr = arr;

    printf("\n---Ejemplo Arrays---\n");
    printf("Valor de arr: ");
    for (int i = 0; i < 10; ++i)
    {
        printf("[%d] ", arr[i]);
    }
    printf("\nDireccion de arr: %p\n", arr);
    printf("Valor de pArr: %p\n", pArr);
    printf("Valor apuntado por pArr:");
    for (int i = 0; i < 10; ++i)
    {
        printf("[%d] ", pArr[i]); // Asegurarse de no acceder fuera del rango
    }

    return 0;
}
