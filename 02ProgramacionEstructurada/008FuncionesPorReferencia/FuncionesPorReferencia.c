#include <stdio.h>

// Funcion que incrementa el valor de un entero en 1

void incrementarPorValor(int numero)
{
    numero++;

    printf("Incrementando por valor: %d\n", numero);
}

void incrementarPorReferencia(int *numero)
{
    // Los parentesis son importantes
    (*numero)++;
    printf("Incrementando por Referancia: %d\n", *numero);
}

int main()
{
    int valor = 10;

    printf("Antes de incrementar: %d\n", valor);

    incrementarPorValor(valor);

    printf("Despues de incrementar por Valor: %d\n", valor);

    // Llamada a la funcion pasando la direccion de 'valor'
    incrementarPorReferencia(&valor);

    printf("Despues de incrementar por Referencia: %d\n", valor);

    return 0;
}