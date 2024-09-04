#include <stdio.h>
#include <string.h>

typedef struct
{
    char nombre[50];
    int puntos;
} CasaHogwarts;

void miFflush();
void guardarPuntos(CasaHogwarts *CasaHogwarts);
int leerCasas(CasaHogwarts *casaHogwarts, FILE *file);
void cargarPuntos(CasaHogwarts casaHogwarts[], int *opcion, FILE *file);

int main()
{

    FILE *file;
    int opcion;

    while (opcion != 0){

    CasaHogwarts casasHogwarts[4];

    // file = fopen("hogwarts_puntos.txt", "a+");
    //  rewind(file); No tenia mucho sentido abrirlo 2 veces

    /* Aprovecahamos r para ver si el archivo existe, si file es nulo  lo creamos y guardamos los puntos inicializados*/
    file = fopen("hogwarts_puntos.txt", "r");

    if (file == NULL)
    {
        strcpy(casasHogwarts[0].nombre, "Gryffindor");
        casasHogwarts[0].puntos = 0;
        strcpy(casasHogwarts[1].nombre, "Hufflepuff");
        casasHogwarts[1].puntos = 0;
        strcpy(casasHogwarts[2].nombre, "Ravenclaw");
        casasHogwarts[2].puntos = 0;
        strcpy(casasHogwarts[3].nombre, "Slytherin");
        casasHogwarts[3].puntos = 0;

        file = fopen("hogwarts_puntos.txt", "a+"); // creamos y escribimos
        guardarPuntos(casasHogwarts);
        fclose(file);
        file = fopen("hogwarts_puntos.txt", "r"); // Volvemos a abrir en r para que quede consistente con nuestra primer apertura
    }


    
    printf(",-*'^'~*-.,_,.-*~ Puntaje Hogwarts ~*-.,_,.-*~'^'*-,\n");

    int z = 0;
    rewind(file);
    while (leerCasas(&casasHogwarts[z], file) == 2 && !feof(file)){
        z++;
    }; // 2 por que es el numero de datos que lee por casa
    for(int i = 0; i < 4; i++){
        printf("\n%s: %d puntos", casasHogwarts[i].nombre, casasHogwarts[i].puntos);
    }
    fclose(file);

    // hasta aca te ayudo por ahora,
    // tip: recuerda que existe una forma de sobreescribir el archivo
    // un archivo lo puedes abrir y cerrar cuantas veces necesites

    printf("\n\nMenu:\n");
    printf("1. Cargar Puntos\n");
    printf("2. Salir\n");
    printf("Selecciona una opcion: ");
    scanf("%d", &opcion);
    if (opcion != 2){
        cargarPuntos(casasHogwarts, &opcion, file);
        guardarPuntos(casasHogwarts);
    } else {
        opcion = 0;
    }

    }

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

void guardarPuntos(CasaHogwarts *CasaHogwarts)
{
    FILE *file = fopen("hogwarts_puntos.txt", "w+");
    for (int i = 0; i < 4; i++)
    {
        fprintf(file, "%s %d\n", CasaHogwarts[i].nombre, CasaHogwarts[i].puntos);
    }
    fclose(file);
}

int leerCasas(CasaHogwarts *casaHogwarts, FILE *file)
{
    int respuesta = fscanf(file, "%s %d", casaHogwarts->nombre, &(casaHogwarts->puntos)); // fscanf espera apuntadores, casaHogwarts->nombre ya es un
                                                                                          // apuntador por que es un arreglo de caracteres
                                                                                          // pero casaHogwarts->puntos NO
                                                                                          // Y si, ya se que casaHogwarts en un apuntador y esta bien
                                                                                          // pasarlo asi pues si no se pasaria una copia
                                                                                          // Pero los atributos al pasarlos a otra funcion
                                                                                          // tambien hay que pasar sus direcciones de memoria
    return respuesta;
}

void cargarPuntos(CasaHogwarts casaHogwarts[], int *opcion, FILE *file)
{

    int puntaje;
    int i = 1;
    printf("\n\nCasa:");

    for(int i = 0; i < 4; i++){
        printf("\n%d. %s", i+1,  casaHogwarts[i].nombre);
    }
    printf("\n5. Regresar\n");
    printf("Selecciona una opcion: ");
    scanf("%d", opcion);

    if (*opcion != 5)
    {
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
        *opcion = 1;
        break;
    default:
        printf("Esa opcion no es valida\n");
        *opcion = 1;
        break;
    }
}