#include <stdio.h>

int potencia(int base, int exp)
{   
    if(exp == 0){
        return 1;
    } else {
       int resultado = base * potencia(base, exp - 1); 
       return resultado;
    }
}


int main()
{
    int base = 2;
    int exp = 3;
    printf("%d elevado a la potencia de %d es %d\n", base, 
        exp, potencia(base, exp));
    return 0;
}
