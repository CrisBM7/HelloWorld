#include <stdio.h>
#define TAM 10

int main()
{
    int arreglo[TAM] = {33, 25, 36, 46, 75, 61, 70, 8, 9, 10};
    int mitad = TAM / 2;
    int min_idx;
    int temp;

    //Selection sort
    for (int i = 0; i < mitad; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < TAM; j++)
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

    //Bubble Sort
    for (int i = mitad; i < TAM - 1; ++i)
    {
        for (int j = mitad; j < TAM - i - 1 + mitad; ++j)
        {
            if (arreglo[j] < arreglo[j + 1])
            {
                int temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }

    // Imprimir el arreglo ordenado
    for (int i = 0; i < TAM; ++i)
    {
        printf("%d ", arreglo[i]);
    }

    return 0;
}
