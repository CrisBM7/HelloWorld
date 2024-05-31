#include <stdio.h>

#define N 5

int main()
{
    int arreglo[N] = {5, 2, 8, 1, 9};
    int temp;
    int min_idx;

    for (int i = 0; i < N - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < N; j++)
        {
            if (arreglo[j] < arreglo[min_idx])
            {
                min_idx = j;
            }
        }
        temp = arreglo[i];
        arreglo[i] = arreglo[min_idx];
        arreglo[min_idx] = temp;
    }

    printf("Arreglo ordenado en orden ascendente: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    return 0;
}
