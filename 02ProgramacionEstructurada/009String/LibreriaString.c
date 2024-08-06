#include <stdio.h>
#include <string.h>

int copiarCadena()
{
    char src[] = "Hola, mundo";
    char dest[50];

    strcpy(dest, src);

    printf("Cadena copiada: %s\n", dest);

    return 0;
}

int concatenar()
{
    char str1[50] = "Hola, ";
    char str2[] = "mundo";

    strcat(str1, str2);

    printf("Cadena concatenada: %s\n", str1);

    return 0;
}

int comparar()
{
    char str1[] = "Hola";
    char str2[] = "Mundo";

    if (strcmp(str1, str2) == 0)
    {
        printf("Las cadenas son iguales.\n");
    }
    else
    {
        printf("Las cadenas son diferentes.\n");
    }

    return 0;
}

int longitud()
{
    char str[] = "Hola, mundo";

    printf("La longitud de la cadena es: %u\n", strlen(str));

    printf("La longitud del array es: %u\n", sizeof(str));

    return 0;
}

int buscarCaracter()
{
    char str[] = "Hola, mundo";
    char ch = 'm';
    char *p;

    p = strchr(str, ch);

    if (p != NULL)
    {
        printf("El caracter '%c' se encontro en la posicion: %d\n", ch, p - str + 1);
    }
    else
    {
        printf("El caracter '%c' no se encontro.\n", ch);
    }

    return 0;
}

int busquedaSubcadena()
{
    char str[] = "Hola, mundo";
    char substr[] = "mundo";
    char *p;

    p = strstr(str, substr);

    if (p != NULL)
    {
        printf("La subcadena '%s' se encontro en la posicion: %ld\n", substr, p - str + 1);
    }
    else
    {
        printf("La subcadena '%s' no se encontro.\n", substr);
    }

    return 0;
}

int main()
{
    copiarCadena();
    concatenar();
    comparar();
    longitud();
    buscarCaracter();
    busquedaSubcadena();

    return 0;
}