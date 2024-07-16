#include <stdio.h>

void miFflush()
{
    while (getchar() != '\n');
}

int main()
{
    char elementoBuscar;
    int y = 0;
    int x = 0;
    int posicionX[10] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int posicionY[10] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    char letras[5][5] = {
        {'a', 'd', 'c', 'a', 'b'},
        {'d', 'c', 'a', 'c', 'e'},
        {'e', 'b', 'c', 'f', 'b'},
        {'f', 'c', 'd', 'b', 'e'},
        {'c', 'd', 'a', 'e', 'c'}};

    printf("Ingrese un elemento a buscar: ");
    scanf("%c", &elementoBuscar);
    miFflush();

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (elementoBuscar == letras[i][j])
            {
                posicionX[x] = j;
                posicionY[y] = i;
                x++;
                y++;
            }
        }
    }

    if(x != 0){
       for (int i = 0; i < x; i++){
            printf("Elemento encontrado en la posición [%d] [%d]\n", posicionY[i], posicionX[i]);
        } 
    } else {
        printf("Elemento no encontrado");
    }

    return 0;
    
    
}