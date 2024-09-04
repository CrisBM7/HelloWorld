#include <stdio.h>
#include <stdlib.h>

/*Modificar codigo primero para que reciba la persona ingresada 
por teclado en vaz de ser inicializada

Y luego de alguna forma meter un numero de personas indefinido
hasta que el usuario ya no necesite ingresar nuevas personas

ingresar nuevo nombre : S
juan perez 37 1.60
ingresar nuevo nombre : S
ana sanchez 43 1.50
ingresar nuevo nombre : N*/

void miFflush()
{
    while (getchar() != '\n');
}

typedef struct
{
    char nombre[50];
    char apellido[50];
    int edad;
    float altura;
} Persona;

void escribirPersona(FILE *file, Persona p)
{
    fprintf(file, "%s %s %d %f\n", p.nombre, p.apellido, p.edad, p.altura);
}

int leerPersona(FILE *file, Persona *p)
{
    return fscanf(file, "%s %s %d %f", p->nombre, p->apellido, &p->edad, &p->altura);
}

int main()
{
    FILE *file;
    Persona persona;
    char opcion;

    // Abrir el archivo en modo "a+" para añadir y leer
    file = fopen("personas.txt", "a+");
    if (file == NULL)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Escribir una nueva persona en el archivo
    do{

        printf("Ingrese nombre apellido edad y altura de la persona nueva separado por espacios:\n");
        scanf("%s %s %d %f", persona.nombre, persona.apellido, &persona.edad, &persona.altura);
        miFflush();

        escribirPersona(file, persona);

        printf("\nDesea ingresar una nueva persona? (S/N): ");
        scanf("%c", &opcion);
        miFflush();
    }while (opcion=='s' || opcion=='S');
    
    // Rewind para leer desde el principio
    rewind(file);

    // Leer y mostrar personas desde el archivo
    printf("Personas en el archivo:\n");
    Persona p;
    while (leerPersona(file, &p) == 4 && !feof(file))
    {
        printf("Nombre: %s, Apellido: %s Edad: %d, Altura: %.2f\n", p.nombre, p.apellido, p.edad, p.altura);
    }

    // Cerrar el archivo
    if (fclose(file) != 0)
    {
        perror("Error al cerrar el archivo");
        return 1;
    }

    return 0;
}



