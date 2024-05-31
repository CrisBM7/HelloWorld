#include <stdio.h>

int main()
{
    int numero[10] = {33, 25, 36, 46, 75, 61, 70, 8, 9, 10};
    int numeroMayor = numero[0];
    int numeroMenor = numero[0];

    for(int i = 0; i < 10; i++){
      if(numeroMayor < numero[i]){
       numeroMayor = numero[i];  
      }
      if(numeroMenor > numero[i]){
        numeroMenor = numero[i];
      }
    } 
    printf("El numero mayor es: %d \n", numeroMayor);
    printf("El numero menor es: %d ", numeroMenor);
    

    return 0;
}