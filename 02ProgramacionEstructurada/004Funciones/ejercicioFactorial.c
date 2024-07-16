#include <stdio.h>

// Función recursiva para calcular la suma de los primeros n números naturales
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        int resultado = n * factorial(n - 1);
        return resultado;
    }
}

int main()
{
    int numUsuario;

    printf("Introduce un numero: ");
    scanf("%d", &numUsuario);
    factorial(numUsuario);
    printf("El factorial %d números es %d\n", numUsuario, factorial(numUsuario));
    return 0;
}