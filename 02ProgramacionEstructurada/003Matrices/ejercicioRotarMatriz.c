#include <stdio.h>

int main()
{

    int numeros[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int rotacion[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    int extra;
    int x = 0;
    int ejeY = 0;
    int ejeYStop = 1;

    do
    {
        for (int j = 2; j >= 0; j--)
        {
            for (int i = ejeY; i < ejeYStop; i++)
            {
                extra = numeros[j][i];
                for (int rep = 0; rep < 1; rep++)
                {
                    rotacion[0][x] = extra;
                    x++;
                }
            }
        }
        ejeY++;
        ejeYStop++;
    } while (ejeY <= 2);

    printf("La matriz rotada en 90 grados es:\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", rotacion[i][j]);
            if (j == 2)
            {
                printf("\n");
            }
        }
    }
}