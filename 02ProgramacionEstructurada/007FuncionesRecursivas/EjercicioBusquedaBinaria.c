#include <stdio.h>

int busquedaBinaria(int arr[], int izquierda, int derecha, int x)
{
    int m = (izquierda + derecha) / 2;
    if (x > arr[m])
    {
        izquierda = m;
        izquierda++;
        if (izquierda != derecha)
        {
            return busquedaBinaria(arr, m, derecha, x);
        }
        else
        {
            return -1;
        }
    }
    else if (x < arr[m])
    {
        derecha = m;
        derecha--;
        if (izquierda != derecha)
        {
            return busquedaBinaria(arr, izquierda, m, x);
        }
        else
        {
            return -1;
        }
    }
    return m;
}

int main()
{
    int arr[] = {2, 3, 4, 6, 10, 16, 19, 23, 28, 35};
    int n = 10;
    int x;

    printf("Numero a buscar: ");
    scanf("%d", &x);

    int resultado = busquedaBinaria(arr, 0, n - 1, x);
    if (resultado != -1)
    {
        printf("El elemento está presente en el índice %d\n", resultado);
    }
    else
    {
        printf("El elemento no está presente en el arreglo\n");
    }
    return 0;
}
