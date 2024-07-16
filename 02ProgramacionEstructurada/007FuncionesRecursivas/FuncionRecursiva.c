#include <stdio.h>

// Función recursiva para calcular la suma de los primeros n números naturales
int suma(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        int resultado = n + suma(n - 1);
        return resultado;
    }
}

int main()
{
    int num = 5;
    printf("La suma de los primeros %d números es %d\n", num, suma(num));
    return 0;
}