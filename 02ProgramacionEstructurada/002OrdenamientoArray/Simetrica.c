#include <stdio.h>

int main()
{
    int n;
    printf("Ingrese el tamaño de la matriz cuadrada: ");
    scanf("%d", &n);

    int matrix[n][n];
    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    int isSymmetric = 0;
    //Aqui tu codigo

    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
        {
            if(matrix[i][j] == matrix[j][i]){
                isSymmetric = 1;
            }
        }
        
    }

    if (isSymmetric == 1)
    {
        printf("La matriz es simétrica.\n");
    }
    else
    {
        printf("La matriz no es simétrica.\n");
    }

    return 0;
}
