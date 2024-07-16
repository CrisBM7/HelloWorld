#include <stdio.h>

int fibonacci(int n)
{    
    if(n < 2){
        return n;
    } else {
        return (fibonacci(n - 1) + fibonacci(n - 2));
    }
}

int main()  
{
    int num = 10;
    printf("El término %d de la serie de Fibonacci es %d\n", 
        num, fibonacci(num));
    return 0;
}
