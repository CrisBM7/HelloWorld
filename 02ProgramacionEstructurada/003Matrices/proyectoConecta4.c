#include <stdio.h>
// Este sirve para limpiar pantalla
#include <stdlib.h>
// Este sirve para los colorcitos
#include <windows.h>
// Colores definidos
#define RED 4
#define WHITE 15
#define CYAN 3

// Limpia la pantalla
void limpiarPantalla()
{
    system("cls");
};

// Se come los saltos de linea
void miFflush()
{
    while (getchar() != '\n')
        ;
}

// Cambiar colores
void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
// Variables jugadores
char p1[10];
char p2[10];
int play;
// Menu principal
void menuPrincipal()
{
    limpiarPantalla();
    setColor(WHITE);
    printf("----------------\n");
    printf("|              |\n");
    printf("|              |\n");
    printf("|   Conecta 4  |\n");
    printf("|              |\n");
    printf("|              |\n");
    printf("|(Presiona una |\n");
    printf("|  tecla para  |\n");
    printf("|    empezar)  |\n");
    printf("----------------\n\n\n\n");

    scanf("%d", &play);
    limpiarPantalla();

    setColor(RED);
    printf("----------------\n");
    printf("|              |\n");
    printf("|              |\n");
    printf("| Introduce tu |\n");
    printf("|   nombre P1  |\n");
    printf("|              |\n");
    printf("| Eres las-> O |\n");
    printf("|              |\n");
    printf("|              |\n");
    printf("----------------\n\n\n\n");
    printf("Escribe tu nombre letra por letra para guardarlo (max 3 letras)\n");

    for (int i = 1; i < 4; i++)
    {
        miFflush();
        printf("Escribe la %d letra: ", i);
        scanf("%c", &p1[i]);
    }
    limpiarPantalla();

    setColor(CYAN);
    printf("----------------\n");
    printf("|              |\n");
    printf("|              |\n");
    printf("| Introduce tu |\n");
    printf("|   nombre P2  |\n");
    printf("|              |\n");
    printf("| Eres las-> X |\n");
    printf("|              |\n");
    printf("|              |\n");
    printf("----------------\n\n\n\n");
    printf("Escribe tu nombre letra por letra para guardarlo (max 3 letras)\n");

    for (int i = 1; i < 4; i++)
    {
        miFflush();
        printf("Escribe la %d letra: ", i);
        scanf("%c", &p2[i]);
    }
    limpiarPantalla();
}

// Turno de los jugadores
int turno = 0;
char ficha = 'o';

void turnoP1()
{
    setColor(RED);
    ficha = 'o';
    turno = 1;
}
void turnoP2()
{
    setColor(CYAN);
    ficha = 'x';
    turno = 0;
}

// Definir tablero largo  y ancho
#define x 16
#define y 9

int main()
{
    menuPrincipal();
    do
    {
        limpiarPantalla();
        char tablero[y][x] = {
            {'|', '1', '|', '2', '|', '3', '|', '4', '|', '5', '|', '6', '|', '7', '|', '\n'},
            {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', '\n'},
            {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', '\n'},
            {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', '\n'},
            {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', '\n'},
            {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', '\n'},
            {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', '\n'},
            {'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', '\n'},
            {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', ' '}};

        int opcionPlayer;
        int parar1 = 7;
        int parar2 = 7;
        int parar3 = 7;
        int parar4 = 7;
        int parar5 = 7;
        int parar6 = 7;
        int parar7 = 7;

        int yCase1 = 7;
        int yCase2 = 7;
        int yCase3 = 7;
        int yCase4 = 7;
        int yCase5 = 7;
        int yCase6 = 7;
        int yCase7 = 7;

        int opcionValida = 1;
        int fichaIndiceX;
        int fichaIndiceY;
        int ganador = 0;
        int empate = 49;

        do
        {
            // Turno de los jugadores
            if (turno == 0 && opcionValida == 1)
            {
                turnoP1();
                empate--;
            }
            else if (turno == 1 && opcionValida == 1)
            {
                turnoP2();
                empate--;
            }

            // Muestra el tablero
            for (int i = 0; i < y; i++)
            {
                for (int j = 0; j < x; j++)
                {
                    printf("%c", tablero[i][j]);
                }
            }

            if (opcionValida == 0)
            {
                printf("\n(Tecla no reconocida ingresa otra vez donde poner tu ficha,\n O no es tu turno)");
            }
            printf("\n\nElige donde poner tu ficha ");
            if (turno == 0)
            {
                for (int i = 0; i < 4; i++)
                {
                    printf("%c", p2[i]);
                }
            }
            else
            {
                for (int i = 0; i < 4; i++)
                {
                    printf("%c", p1[i]);
                }
            }
            printf(": ");

            opcionValida = 1;
            scanf("%d", &opcionPlayer);
            limpiarPantalla();

            switch (opcionPlayer)
            {
            case 1:
                if (parar1 > 0)
                {
                    for (yCase1; yCase1 >= parar1; yCase1--)
                    {
                        tablero[yCase1][1] = ficha;
                        fichaIndiceY = yCase1;
                        fichaIndiceX = 1;
                    }
                    parar1--;
                }
                else
                {
                    opcionValida = 0;
                }
                break;
            case 2:
                if (parar2 > 0)
                {
                    for (yCase2; yCase2 >= parar2; yCase2--)
                    {
                        tablero[yCase2][3] = ficha;
                        fichaIndiceY = yCase2;
                        fichaIndiceX = 3;
                    }
                    parar2--;
                }
                else
                {
                    opcionValida = 0;
                }

                break;
            case 3:
                if (parar3 > 0)
                {
                    for (yCase3; yCase3 >= parar3; yCase3--)
                    {
                        tablero[yCase3][5] = ficha;
                        fichaIndiceY = yCase3;
                        fichaIndiceX = 5;
                    }
                    parar3--;
                }
                else
                {
                    opcionValida = 0;
                }

                break;
            case 4:
                if (parar4 > 0)
                {
                    for (yCase4; yCase4 >= parar4; yCase4--)
                    {
                        tablero[yCase4][7] = ficha;
                        fichaIndiceY = yCase4;
                        fichaIndiceX = 7;
                    }
                    parar4--;
                }
                else
                {
                    opcionValida = 0;
                }
                break;
            case 5:
                if (parar5 > 0)
                {
                    for (yCase5; yCase5 >= parar5; yCase5--)
                    {
                        tablero[yCase5][9] = ficha;
                        fichaIndiceY = yCase5;
                        fichaIndiceX = 9;
                    }
                    parar5--;
                }
                else
                {
                    opcionValida = 0;
                }
                break;
            case 6:
                if (parar6 > 0)
                {
                    for (yCase6; yCase6 >= parar6; yCase6--)
                    {
                        tablero[yCase6][11] = ficha;
                        fichaIndiceY = yCase6;
                        fichaIndiceX = 11;
                    }
                    parar6--;
                }
                else
                {
                    opcionValida = 0;
                }
                break;
            case 7:
                if (parar7 > 0)
                {
                    for (yCase7; yCase7 >= parar7; yCase7--)
                    {
                        tablero[yCase7][13] = ficha;
                        fichaIndiceY = yCase7;
                        fichaIndiceX = 13;
                    }
                    parar7--;
                }
                else
                {
                    opcionValida = 0;
                }
                break;
            default:
                opcionValida = 0;
                break;
            }

            // Comprobacion del ganador

            int x2 = 0;
            ganador = 0;

            // Comprobacion de abajo hacia arriba
            for (int i = 1; i < 4; i++)
            {
                if (tablero[fichaIndiceY][fichaIndiceX] == tablero[fichaIndiceY + i][fichaIndiceX])
                {
                    ganador++;
                }
            }

            // Comprobacion hacia los lados

            if (ganador < 3)
            {
                int contador = 4;
                ganador = 0;
                for (int i = 1; i < contador; i++)
                {
                    x2 = x2 + 2;
                    if (tablero[fichaIndiceY][fichaIndiceX] == tablero[fichaIndiceY][fichaIndiceX + x2])
                    {
                        ganador++;
                    }
                    else
                    {
                        contador = 1;
                    }
                }
            }

            if (ganador < 3)
            {
                int contador = 4;
                x2 = 0;
                for (int i = 1; i < contador; i++)
                {
                    x2 = x2 + 2;
                    if (tablero[fichaIndiceY][fichaIndiceX] == tablero[fichaIndiceY][fichaIndiceX - x2])
                    {
                        ganador++;
                    }
                    else
                    {
                        contador = 1;
                    }
                }
            }

            // Comprobacion en linea inclinada

            // Abajo derecha
            int mas1 = 0;
            if (ganador < 3)
            {
                ganador = 0;
                x2 = 0;
                int contador = 4;
                for (int i = 1; i < contador; i++)
                {
                    x2 = x2 + 2;
                    mas1++;
                    if (tablero[fichaIndiceY][fichaIndiceX] == tablero[fichaIndiceY + mas1][fichaIndiceX + x2])
                    {
                        ganador++;
                    }
                    else
                    {
                        contador = 1;
                    }
                }
            }

            // Arriba izquierda
            if (ganador < 3)
            {
                mas1 = 0;
                x2 = 0;
                int contador = 4;

                for (int i = 1; i < contador; i++)
                {
                    x2 = x2 + 2;
                    mas1++;
                    if (tablero[fichaIndiceY][fichaIndiceX] == tablero[fichaIndiceY - mas1][fichaIndiceX - x2])
                    {
                        ganador++;
                    }
                    else
                    {
                        contador = 1;
                    }
                }
            }

            // Abajo izquierda
            if (ganador < 3)
            {
                int contador = 4;
                ganador = 0;
                mas1 = 0;
                x2 = 0;
                for (int i = 1; i < contador; i++)
                {
                    x2 = x2 + 2;
                    mas1++;
                    if (tablero[fichaIndiceY][fichaIndiceX] == tablero[fichaIndiceY + mas1][fichaIndiceX - x2])
                    {
                        ganador++;
                    }
                    else
                    {
                        contador = 1;
                    }
                }
            }

            // Arriba derecha
            mas1 = 0;
            if (ganador < 3)
            {
                x2 = 0;
                int contador = 4;
                for (int i = 1; i < contador; i++)
                {
                    x2 = x2 + 2;
                    mas1++;
                    if (tablero[fichaIndiceY][fichaIndiceX] == tablero[fichaIndiceY - mas1][fichaIndiceX + x2])
                    {
                        ganador++;
                    }
                    else
                    {
                        contador = 1;
                    }
                }
            }

            if (ganador >= 3)
            {
                printf("Ganaste");
            }

        } while (ganador < 3 && empate > 0);

        limpiarPantalla();
        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j < x; j++)
            {
                printf("%c", tablero[i][j]);
            }
        }
        if (ganador == 3)
        {
            printf("\nGanaste ");
            if (turno == 0)
            {
                for (int i = 0; i < 4; i++)
                {
                    printf("%c", p2[i]);
                }
            }
            else
            {
                for (int i = 0; i < 4; i++)
                {
                    printf("%c", p1[i]);
                }
            }
        }
        else
        {
            printf("\nEmpate (Son muy buenos jugando lol)");
        }

        printf("\nPresiona (1) para volver a jugar o (0) para salir: ");
        scanf("%d", &play);

    } while (play == 1);

    return 0;
}
