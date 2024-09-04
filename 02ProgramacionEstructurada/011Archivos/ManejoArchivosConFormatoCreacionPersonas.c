#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    Persona persona;

    // Abrir el archivo en modo "a+" para añadir y leer
    file = fopen("personas.txt", "a+");
    if (file == NULL)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Escribir una nueva persona en el archivo

    

    // Leer y mostrar personas desde el archivo
    char nombre[50];
    int edad;
    float estatura;

    printf("Personas en el archivo:\n");
    printf("Ingrese el su nombre \n");
    fgets(nombre, sizeof(nombre), stdin);
    strtok(nombre, "\n");
    printf("Ingrese la edad \n");
    scanf("%d", &edad);
    printf("Ingrese la estatura \n");
    scanf("%f", &estatura);

    strcpy(persona.nombre, nombre); 
    persona.edad = edad;
    persona.altura = estatura;

    escribirPersona(file, persona);
    
// Rewind para leer desde el principio
    rewind(file);
    
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
