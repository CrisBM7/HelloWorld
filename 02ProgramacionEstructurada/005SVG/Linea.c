#include <stdio.h>

// Ejecutar
// g++ Linea.c -o Linea; .\Linea > Linea.html; .\Linea.html

int main()
{
    int ancho = 500, alto = 500;

    printf("<html><body><svg width=\"%d\" height=\"%d\">\n", ancho, alto);
    printf("<line x1=\"0\" y1=\"0\" x2=\"500\" y2=\"500\" stroke=\"red\" stroke-width=\"3\" />");
    printf("</svg></body></html>");

    return 0;
}
