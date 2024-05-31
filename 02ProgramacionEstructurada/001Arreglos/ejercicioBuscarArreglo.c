#include <stdio.h>

int main()
{
    int numero[5] = {4, 2, 1, 7, 5};
    int numeroABuscar;
    int salida = 6;

    printf("Ingresa el elemento que desea buscar: ");
    scanf("%d", &numeroABuscar);

    for(int i = 0; i < 5; i++){
      if(numeroABuscar == numero[i]){ 
        salida = 1;
      }
    }
    if (salida == 1){
     printf("El elemento %d fue encontrado", numeroABuscar); 
    }

    if (salida != 1){
     printf("El elemento %d no fue encontrado", numeroABuscar);   
    }
    return 0;
}