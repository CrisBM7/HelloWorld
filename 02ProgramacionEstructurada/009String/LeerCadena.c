#include <stdio.h>
#include <string.h>
/*scanf*/

void miFflush()
{
    while (getchar() != '\n')
        ;
}

int main()
{
    // Clasico scanf (No lee espacios)
    char strScanf[20];
    printf("Introduce una cadena [scanf]: ");
    scanf("%s", strScanf); // lee hasta el primer espacio o nueva linea
    miFflush(); // limpiar buffer
    printf("Cadena introducida [scanf]: %s\n", strScanf);
    

    // Obsoleto gets
    char strGets[20];
    printf("Introduce una cadena [gets]: ");
    gets(strGets); // Peligroso, no controla el tamanio de la entrada
    printf("Cadena introducida [gets]: %s\n", strGets);

    // El mejorcito fgets (Hay que limpiar saltos de linea)
    char strFgets[20];
    printf("Introduce una cadena [strFgets]: ");
    fgets(strFgets, sizeof(strFgets), stdin); // lee incluyendo espacios, hasta el tamanio especificado o una nueva linea
    strtok(strFgets, "\n");                   // limpiar saltos de linea
    printf("Cadena introducida [strFgets]: %s\n", strFgets);

    return 0;
}