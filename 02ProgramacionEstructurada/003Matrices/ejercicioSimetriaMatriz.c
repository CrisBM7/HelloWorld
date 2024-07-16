#include <stdio.h>

int main()
{
    int y = 0;
    int x = 0;
    int numUsuario;
    int numero;
    int simetrico = 1;
    printf("Ingrese el tamaño de la matriz cuadrada:\n");
    scanf("%d", &numUsuario);
    y = numUsuario;
    x = numUsuario;

    int arregloNumeros[y][x];

    printf("Ingrese los elementos de la matriz:\n");

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &numero);
            arregloNumeros[i][j] = numero;
        }
    }

    for (int i = 0; i < numUsuario; i++)
    {
        if (i == 0)
        {
            if (arregloNumeros[i][0] == arregloNumeros[numUsuario][numUsuario])
            {
                simetrico = 0;
            }
        } else {
            for(int der = numUsuario; der < 0; der--)
            if(arregloNumeros[i][0] == arregloNumeros[numUsuario][der-1]){
                simetrico = 0;
            }
        }
    }
    return 0;
}