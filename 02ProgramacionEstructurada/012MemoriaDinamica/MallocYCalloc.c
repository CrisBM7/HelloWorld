#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n; // Numero de elementos en el array

    printf("N:");
    scanf("%d",&n);

    // Usando malloc para asignar memoria para 5 enteros
    int *arr_malloc;
    
    arr_malloc = (int *)malloc(n * sizeof(int));

    printf("Tamaño individual: %d\n" , sizeof(int));
    printf("Tamaño del arreglo: %d\n" , sizeof(*arr_malloc));

    if (arr_malloc == NULL)
    {
        printf("Error al asignar memoria con malloc\n");
        return 1;
    }

    // Usando calloc para asignar memoria para 5 enteros
    int *arr_calloc = (int *)calloc(n, sizeof(int));
    if (arr_calloc == NULL)
    {
        printf("Error al asignar memoria con calloc\n");
        free(arr_malloc);
        return 1;
    }

    // Imprimir valores iniciales del array asignado por malloc
    printf("Valores del array asignado por malloc:\n");
    for (int i = 0; i < n; i++)
    {
        arr_malloc[i] = i+1;
        printf("%d ", arr_malloc[i]); // Puede contener basura (valores aleatorios)
    }
    printf("\n");

    // Imprimir valores iniciales del array asignado por calloc
    printf("Valores del array asignado por calloc:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr_calloc[i]); // Todos los valores deben ser 0
    }
    printf("\n");

    // Liberar la memoria asignada
    free(arr_malloc);
    free(arr_calloc);

    return 0;
}
