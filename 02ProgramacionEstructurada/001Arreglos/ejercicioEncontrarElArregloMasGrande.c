#include <stdio.h>

int main()
{
    int numero[5] = {1, 2, 3, 7, 5};
    int numeroMayor = 0;

    for(int i = 0; i < 5; i++){
      if(numero[i] > numeroMayor){
       numeroMayor = numero[i];  
      }
    }
    printf("%d ", numeroMayor);

    return 0;
}