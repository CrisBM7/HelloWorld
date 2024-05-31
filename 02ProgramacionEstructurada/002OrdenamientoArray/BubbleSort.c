#include <stdio.h>

#define N 5

int main()
{
    int arreglo[N] = {9,5, 2, 8, 1};
    int temp;
    int i, j;

    for (i = 0; i < N - 1; i++) {
        // Ultimos i elementos ya estan en su lugar
        for (j = 0; j < N-i-1; j++) {
            if (arreglo[j] > arreglo[j+1]) {
                // Intercambiar arr[j] y arr[j+1]
                temp = arreglo[j];
                arreglo[j] = arreglo[j+1];
                arreglo[j+1] = temp;
            }
        }
    }

    printf("Arreglo ordenado en orden ascendente: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    return 0;
}
