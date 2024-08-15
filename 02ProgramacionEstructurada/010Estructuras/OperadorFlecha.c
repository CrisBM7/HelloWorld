#include <stdio.h>
#include <string.h>

// Definicion de la estructura
struct Persona
{
    char nombre[50];
    char sexo;
    int edad;
    float altura;
};

// Prototipos
void modificarPersona(struct Persona *persona);
void modificarPersonas(struct Persona personas[], int size);
void imprimirPersona(struct Persona persona);
void imprimirPersonas(struct Persona personas[], int lenght);
void miFflush();

int main()
{
    struct Persona persona = {"Juan Perez", 'M', 30, 1.75};

    // Imprimir valores originales
    printf("---------Valores originales---------\n");
    imprimirPersona(persona);

    // Modificar los valores de la estructura
    modificarPersona(&persona);

    // Imprimir valores modificados
    printf("\n---------Valores modificados---------\n");
    imprimirPersona(persona);

    // Modificacion de arreglo de structs
    struct Persona personas[3] = {
        {"Juan Perez", 'M', 30, 1.75},
        {"Maria Lopez", 'F', 25, 1.65},
        {"Carlos Garcia", 'M', 35, 1.80}};
    int size = 3;

    printf("\n---------Valores originales [Arreglos]---------\n");
    imprimirPersonas(personas, size);

    modificarPersonas(personas, size);

    printf("\n---------Valores modificados [Arreglos]---------\n");
    imprimirPersonas(personas, size);

    return 0;
}

// Funcion para modificar la estructura
void modificarPersona(struct Persona *persona)
{
    printf("\n:::Captura de datos:::");
    printf("\nIntroduce el nuevo nombre: ");
    fgets(persona->nombre, sizeof(persona->nombre), stdin);
    strtok(persona->nombre, "\n");

    printf("Introduce el nuevo sexo: ");
    scanf("%c", &persona->sexo);
    miFflush();
    persona->edad = 90;
    persona->altura = 1.65;
}

// Funcion para modificar el arreglo de estructuras
void modificarPersonas(struct Persona personas[], int size)
{
    strcpy(personas[0].nombre, "Juana Perez");
    personas[0].edad++;
    personas[0].sexo = 'F';
}

void imprimirPersona(struct Persona persona)
{
    printf("Nombre: %s\n", persona.nombre);
    printf("Sexo: %c\n", persona.sexo);
    printf("Edad: %d\n", persona.edad);
    printf("Altura: %.2f\n", persona.altura);
}

void imprimirPersonas(struct Persona personas[], int lenght)
{
    for (int i = 0; i < lenght; i++)
    {
        printf("\n");
        printf("Persona %d\n", i + 1);
        imprimirPersona(personas[i]);
    }
}

void miFflush()
{
    while (getchar() != '\n')
        ;
}
