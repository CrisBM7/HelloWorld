#include <stdio.h>

int main()
{
    int array[5] = {4, 2, 1, 7, 5};
    int arrayResultado[5] = {0, 0, 0, 0, 0};
    int arrayIndice[5] = {0, 0, 0, 0, 0};
    int numeroABuscar;
    int salida = 6;
    int entrar;
    int indiceMin;
    int valorMin;

    for (int j = 0; j < 5; j++)
    {
        valorMin = 100000000;
        entrar = 1;
        for (int i = 0; i < 5; i++)
        {
            for (int k = 0; k < j; k++)
            {
                if (arrayIndice[k] == i)
                {
                    entrar = 0;
                }
            }
            if (valorMin > array[i] && entrar == 1)
            {
                indiceMin = i;
                valorMin = array[i];
            }
        }
        arrayResultado[j] = valorMin;
        arrayIndice[j] = indiceMin;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arrayResultado[i]);
    }
    return 0;
}