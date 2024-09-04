#include <stdio.h>
#include <string.h>

typedef struct
{
    char nombre[50];
    int puntos;
} CasaHogwarts;

void miFflush();
void guardarPuntos(CasaHogwarts *CasaHogwarts, FILE *file);
int leerCasas(CasaHogwarts *casaHogwarts, FILE *file);
void cargarPuntos(CasaHogwarts *casaHogwarts, int *opcion);

int main()
{

    FILE *file;
    int opcion;

    CasaHogwarts casasHogwarts[4] = {
        {"Gryffindor", 0},
        {"Hufflepuff", 0},
        {"Ravenclaw", 0},
        {"Slytherin", 0}
    };

    
    file = fopen("hogwarts_puntos.txt", "a+");
    rewind(file);
    file = fopen("hogwarts_puntos.txt", "r+");

    if (file == NULL)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    while (leerCasas(casasHogwarts, file) == 4 && !feof(file))
    {
        printf("%s: %d puntos %.2f\n", p.nombre, p.edad, p.altura);
    }
    
    printf("\nMenu:\n");
    printf("1. Cargar Puntos\n");
    printf("2. Salir\n");
    printf("Selecciona una opcion: ");
    scanf("%d", &opcion);
    cargarPuntos(casasHogwarts, &opcion);
    guardarPuntos(casasHogwarts, file);

    if (fclose(file) != 0)
    {
        perror("Error al cerrar el archivo");
        return 1;
    }
    
   
    return 0;
}

void miFflush()
{
    while (getchar() != '\n');
}

void guardarPuntos(CasaHogwarts *CasaHogwarts, FILE *file)
{
    rewind(file);
    for(int i = 0; i < 4; i++){
        fprintf(file, "%s %d\n", CasaHogwarts[i].nombre, CasaHogwarts[i].puntos);
    }
    
}

int leerCasas(CasaHogwarts *casaHogwarts, FILE *file){
    return fscanf(file, "%s %d", casaHogwarts->nombre, casaHogwarts->puntos); 
}

void cargarPuntos(CasaHogwarts *casaHogwarts, int *opcion){

    int puntaje;

    for(int i = 0; i < 4; i++){
        if(i == 0){
            printf("\n\nCasa:\n");
        }
        printf("%d. %s\n", i+1, casaHogwarts[i].nombre);
    }

    printf("5. Regresar\n");
    printf("Selecciona una opcion: ");
    scanf("%d", opcion);

    if(*opcion != 5){
        printf("Puntos a Sumar: ");
        scanf("%d", &puntaje);
    }

    switch (*opcion)
    {
    case 1:
        casaHogwarts[0].puntos = puntaje + casaHogwarts[0].puntos;
        break;
    case 2:
        casaHogwarts[1].puntos = puntaje + casaHogwarts[1].puntos;
        break;
    case 3:
        casaHogwarts[2].puntos = puntaje + casaHogwarts[2].puntos;
        break;
    case 4:
        casaHogwarts[3].puntos = puntaje + casaHogwarts[3].puntos;
        break;
    case 5:
        
        break;
    default:
        printf("Esa opcion no es valida");
        break;
    }
}