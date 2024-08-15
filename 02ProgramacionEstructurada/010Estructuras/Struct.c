#include <stdio.h>
#include <string.h>

/**una struct (abreviatura de "estructura") es una colección de variables agrupadas bajo
 * un mismo nombre, que pueden ser de diferentes tipos de datos. Las structs se utilizan
 * para representar registros o entidades con múltiples atributos. */

// Declaracion
// Clasico struct Persona{};
typedef struct
{
    /* data */
    char nombre[50];
    char sexo;
    int edad;
    float altura;
} Persona;

// Prototipo Funciones
void imprimirPersona(Persona persona);
void imprimirPersonas(Persona personas[], int lenght);
void miFflush();

int main()
{
    // Inicializacion
    Persona persona = {"Juan Perez", 'M', 30, 1.75};

    imprimirPersona(persona);

    // Leer un miembro
    printf("\nIntroduce el nuevo nombre: ");
    fgets(persona.nombre, sizeof(persona.nombre), stdin);
    strtok(persona.nombre, "\n");

    printf("\nIntroduce el nuevo sexo: ");
    scanf("%c", &persona.sexo);
    miFflush();

    // Modificar un miembro
    persona.edad = 90;
    persona.altura = 1.65;

    printf("\n");
    imprimirPersona(persona);

    printf("\n------\n");

    /***Estructuras en arreglos***/

    // Declaracion e inicializacion del arreglo de structs
    Persona personas[4] = {
        {"Juan Perez", 'M', 30, 1.75},
        {"Maria Lopez", 'F', 25, 1.65},
        {"Carlos Garcia", 'M', 35, 1.80}};
    int size = 4;

    imprimirPersonas(personas, size);

    // ************************* Agregamos a Pedro Sola *************************
    personas[3] = (Persona){"Pedro Sola", 'M', 105, 1.60};

    printf("\n-----Agregamos a Pedro Sola-----");
    imprimirPersonas(personas, size);

    // ************************* Alguien Cambio de Sexo *************************
    strcpy(personas[0].nombre, "Juana Perez");
    personas[0].edad++;
    personas[0].sexo = 'F';

    printf("\n-----Alguien Cambio de Sexo-----");
    imprimirPersonas(personas, size);

    // ************************* Intercambio de personas *************************
    Persona personaTemporal;

    personaTemporal = personas[0];
    personas[0] = personas[1];
    personas[1] = personaTemporal;

    printf("\n-----Intercambio de personas-----");
    imprimirPersonas(personas, size);

    // ************************* Se murio Pedrito u.u *************************
    memset(&personas[3], 0, sizeof(Persona));
    printf("\n-----Se murio Pedrito u.u-----");
    imprimirPersonas(personas, size);

    // ************************* Tamanio controlado *************************
    size--;
    printf("\n-----Tamanio controlado-----");
    imprimirPersonas(personas, size);

    return 0;
}

void imprimirPersona(Persona persona)
{
    // Acceso a los miembros
    printf("Nombre: %s\n", persona.nombre);
    printf("Sexo: %c\n", persona.sexo);
    printf("Edad: %d\n", persona.edad);
    printf("Altura: %.2f\n", persona.altura);
}

void imprimirPersonas(Persona personas[], int lenght)
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