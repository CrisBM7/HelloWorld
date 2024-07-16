#include <stdio.h>

/*** Triangulo de Sierpinski ***/

// Ejecutar
// g++ Triangulo.c -o Triangulo; .\Triangulo > Triangulo.html; .\Triangulo.html

void dibujarTriangulo(int x1, int y1, int x2, int y2, int x3, int y3);
void trianguloSierpinski(int x1, int y1, int x2, int y2, int x3, int y3, int nivel);

int main()
{
    int ancho = 1000, alto = 1000;
    int x1 = 350, y1 = 100, x2 = 100, y2 = 600, x3 = 600, y3 = 600;
    int nivel = 4;

    printf("<html><body><svg width=\"%d\" height=\"%d\">\n", ancho, alto);
    trianguloSierpinski(x1, y1, x2, y2, x3, y3, nivel);
    printf("</svg></body></html>");

    return 0;
}

void trianguloSierpinski(int x1, int y1, int x2, int y2, int x3, int y3, int nivel)
{
    if (nivel == 1)
    {
        dibujarTriangulo(x1, y1, x2, y2, x3, y3);
    }
    else
    {
        nivel--;
        // calcular los vertices de los nuevos triángulos
        trianguloSierpinski(x1, y1, (x1 + x2) / 2.0, (y1 + y2) / 2.0, (x1 + x3) / 2.0, (y1 + y3) / 2.0, nivel);
        trianguloSierpinski((x1 + x2) / 2.0, (y1 + y2) / 2.0, x2, y2, (x2 + x3) / 2.0, (y2 + y3) / 2.0, nivel);
        trianguloSierpinski((x1 + x3) / 2.0, (y1 + y3) / 2.0, (x2 + x3) / 2.0, (y2 + y3) / 2.0, x3, y3, nivel);
    }
}

void dibujarTriangulo(int x1, int y1, int x2, int y2, int x3, int y3)
{
    printf("<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"red\" stroke-width=\"3\" />\n", x1, y1, x2, y2);
    printf("<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"blue\" stroke-width=\"3\" />\n", x2, y2, x3, y3);
    printf("<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"orange\" stroke-width=\"3\" />\n", x1, y1, x3, y3);
}