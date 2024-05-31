#include <stdio.h>

#define N 5

int main()
{
    int arreglo[N] = {5, 2, 8, 1, 9};
    int temp;

    for (int i = 1; i < N; i++)
    {
        temp = arreglo[i];
        int j = i - 1;
        while (j >= 0 && arreglo[j] > temp)
        {
            arreglo[j + 1] = arreglo[j];
            j = j - 1;
        }
        arreglo[j + 1] = temp;
    }

    printf("Arreglo ordenado en orden ascendente: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    return 0;
}
