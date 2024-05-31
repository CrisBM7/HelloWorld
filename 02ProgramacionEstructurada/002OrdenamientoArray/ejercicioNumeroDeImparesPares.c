#include <stdio.h>

int main()
{
    int numero[10] = {33, 25, 36, 46, 75, 61, 70, 8, 9, 10};
    int par;
    int imPar;

    for(int i = 0; i < 10; i++){
      if (numero[i] % 2 == 0) {
            par++;
        } else {
            imPar++;
        }
    } 
    printf("Numero de elementos pares: %d \nNumeros de elementos impares: %d", par, imPar);
    

    return 0;
}