#include <stdio.h>

// Prototipo de la funcion
int suma(int a, int b);
int resta(int a, int b);

int main() {
    int resultado = suma(3, 4);
    printf("La suma es: %d\n", resultado);
    return 0;
}

// Definición de la funcion
int suma(int a, int b) {
    return a + b;
}

// Definición de la funcion resta
int resta(int a, int b) {
    return a - b;
}