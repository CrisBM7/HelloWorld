#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows = 3, cols = 4;

    // Asignar memoria para un array de punteros a int (filas)
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL)
    {
        printf("Error al asignar memoria\n");
        return 1;
    }

    // Asignar memoria para cada fila (columnas)
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL)
        {
            printf("Error al asignar memoria para la fila %d\n", i);
            return 1;
        }
    }

    // Rellenar la matriz con valores y mostrarla
    printf("Matriz:\n");
    int c = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            matrix[i][j] = c++; // Asignacion de valores
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Liberar la memoria asignada
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]); // Liberar cada fila
    }
    free(matrix); // Liberar el array de punteros

    return 0;
}
