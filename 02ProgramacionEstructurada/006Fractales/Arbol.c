#include <stdio.h>
#include <math.h>

/*** Copo de nieve de Koch ***/

// Ejecutar
// g++ Arbol.c -o Arbol; .\Arbol > Arbol.html; .\Arbol.html

void dibujaLinea(int x1, int y1, int x2, int y2);
void dibujaArbol(int x1, int y1, double angulo, int longitud, int nivel);

int main()
{
    int ancho = 1000, alto = 1000;
    int x1 = 500, y1 = 500;
    double anguloInicial = -M_PI / 2;
    int longitudInicial = 150;
    int nivel = 10;

    printf("<html><body><svg width=\"%d\" height=\"%d\">\n", ancho, alto);
    dibujaArbol(x1, y1, anguloInicial, longitudInicial, nivel);
    printf("</svg></body></html>");
    return 0;
}

void dibujaArbol(int x1, int y1, double angulo, int longitud, int nivel)
{
    if (nivel == 0)
        return;

    int x2 = x1 + longitud * cos(angulo);
    int y2 = y1 + longitud * sin(angulo);

    dibujaLinea(x1, y1, x2, y2);

    dibujaArbol(x2, y2, angulo - M_PI / 6, longitud * 0.7, nivel - 1);
    dibujaArbol(x2, y2, angulo + M_PI / 6, longitud * 0.7, nivel - 1);
}

void dibujaLinea(int x1, int y1, int x2, int y2)
{
    printf("<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"green\" stroke-width=\"2\" />\n", x1, y1, x2, y2);
}
