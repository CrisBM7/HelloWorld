#include <stdio.h>
#include <math.h>

/*** Copo de nieve de Koch ***/

// Ejecutar
// g++ Copo.c -o Copo; .\Copo > Copo.html; .\Copo.html

void dibujaLinea(int x1, int y1, int x2, int y2);
void koch(int x1, int y1, int x2, int y2, int nivel);
void kochSnowflake(int x1, int y1, int x2, int y2, int x3, int y3, int nivel);

int main()
{
    int ancho = 1000, alto = 1000;
    int x1 = 350, y1 = 0;
    int x2 = 100, y2 = 500;
    int x3 = 600, y3 = 500;
    int nivel = 4; // Puedes ajustar el nivel de detalle aquí

    printf("<html><body><svg width=\"%d\" height=\"%d\">\n", ancho, alto);
    kochSnowflake(x1, y1, x2, y2, x3, y3, nivel);
    printf("</svg></body></html>");
    return 0;
}

void kochSnowflake(int x1, int y1, int x2, int y2, int x3, int y3, int nivel)
{
    koch(x1, y1, x2, y2, nivel);
    koch(x2, y2, x3, y3, nivel);
    koch(x3, y3, x1, y1, nivel);
}

void koch(int x1, int y1, int x2, int y2, int nivel)
{
    if (nivel == 0)
    {
        dibujaLinea(x1, y1, x2, y2);
    }
    else
    {
        int dx = x2 - x1;
        int dy = y2 - y1;

        int x3 = x1 + dx / 3;
        int y3 = y1 + dy / 3;

        int x4 = x1 + 2 * dx / 3;
        int y4 = y1 + 2 * dy / 3;

        int x = x3 + (int)(cos(M_PI / 3) * (x4 - x3) - sin(M_PI / 3) * (y4 - y3));
        int y = y3 + (int)(sin(M_PI / 3) * (x4 - x3) + cos(M_PI / 3) * (y4 - y3));

        koch(x1, y1, x3, y3, nivel - 1);
        koch(x3, y3, x, y, nivel - 1);
        koch(x, y, x4, y4, nivel - 1);
        koch(x4, y4, x2, y2, nivel - 1);
    }
}

void dibujaLinea(int x1, int y1, int x2, int y2)
{
    printf("<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"black\" stroke-width=\"2\" />\n", x1, y1, x2, y2);
}
