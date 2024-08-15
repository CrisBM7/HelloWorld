#include <stdio.h>
#include <string.h>

void miFflush()
{
    while (getchar() != '\n')
        ;
}

int main()
{
    char nombre[20];
    int x;

    //nombre = "Beatriz";

    strcpy(nombre, "Beatriz");

    printf("Nombre: %s\n", nombre);

    printf("Tamanio de arreglo: %d\n", sizeof(nombre));

    printf("Ingresar Numero: ");
    scanf("%d", &x);
    miFflush();
    
    printf("Ingresar Nombre: ");
    fgets(nombre, sizeof(nombre), stdin);
    strtok(nombre, "\n");

    return 0;
}