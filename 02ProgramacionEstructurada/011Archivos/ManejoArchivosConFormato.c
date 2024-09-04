#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[50];
    int edad;
    float altura;
} Persona;

void escribirPersona(FILE *file, Persona p)
{
    fprintf(file, "%s %d %f\n", p.nombre, p.edad, p.altura);
}

int leerPersona(FILE *file, Persona *p)
{
    return fscanf(file, "%s %d %f", p->nombre, &p->edad, &p->altura);
}

int main()
{
    FILE *file;
    Persona persona = {"Pepe", 35, 1.76};

    // Abrir el archivo en modo "a+" para añadir y leer
    file = fopen("personas.txt", "a+");
    if (file == NULL)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Escribir una nueva persona en el archivo
    escribirPersona(file, persona);

    // Rewind para leer desde el principio
    rewind(file);

    // Leer y mostrar personas desde el archivo
    printf("Personas en el archivo:\n");
    Persona p;
    while (leerPersona(file, &p) == 3 && !feof(file))
    {
        printf("Nombre: %s, Edad: %d, Altura: %.2f\n", p.nombre, p.edad, p.altura);
    }

    // Cerrar el archivo
    if (fclose(file) != 0)
    {
        perror("Error al cerrar el archivo");
        return 1;
    }

    return 0;
}
