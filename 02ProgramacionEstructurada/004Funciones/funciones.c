#include <stdio.h>

void imprimirMensaje() {
    printf("\nHola, Mundo!\n");
}
int obtenerValor() {
    return 42;
}
void imprimirSuma(int a, int b) {
    printf("\nLa suma es %d\n", a + b);
}

int duplicar(int x) {
    x = x * 2;
}

void imprimirArreglo(int a[]) {
    printf("\n arreglo en la posicion 3 es  %d\n", a[2]);
}

int main() {
    int numero = 5;
    int resultado = 0;
    int valor=0;
    int arreglo [5] = {2,1,4,3,7};

    imprimirArreglo(arreglo);

    imprimirMensaje();

    valor = obtenerValor();
    printf("\n42 es %d\n", valor); 

    resultado = duplicar(numero);
    printf("\nEl número es %d\n", resultado); // Imprimirá 5

    imprimirSuma(2, 4);
    
    return 0;
}