#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void miFflush() {
    while (getchar() != '\n')
        ;
}

struct Team {
    char name[50];
    char city[50];
    char stadium[50];
    int year;
};

struct Country {
    char name[50];
    char nameSelection[50];
    int ranking;
    struct Team *teams;  // Apuntador a los equipos
    int numTeams;        // Número de equipos asociados al país
};

void capturarPais(struct Country *country, int *i);
void capturarEquipo(struct Team *team, int *j);
void imprimirDatos(struct Country *countries, int numCountries);

int main() {
    int numCountries;

    printf("Ingrese el numero de paises: ");
    scanf("%d", &numCountries);
    miFflush();  // Limpiar el buffer

    // Reserva dinámica para los países
    struct Country *countries = (struct Country *)malloc(numCountries * sizeof(struct Country));

    for (int i = 0; i < numCountries; i++) {
        capturarPais(&countries[i], &i);

        printf("Numero de equipos: ");
        scanf("%d", &countries[i].numTeams);

        // Reserva dinámica para los equipos asociados a este país
        countries[i].teams = (struct Team *)malloc(countries[i].numTeams * sizeof(struct Team));

        for (int j = 0; j < countries[i].numTeams; j++) {
            capturarEquipo(&countries[i].teams[j], &j);
        }
    }

    printf("\n||||||||||||Informacion de los paises y equipos||||||||||||\n");
    imprimirDatos(countries, numCountries);

    // Liberar memoria dinámica
    for (int i = 0; i < numCountries; i++) {
        free(countries[i].teams);
    }
    free(countries);

    return 0;
}

void capturarPais(struct Country *country, int *i) {
    
    printf("\nPais #%d:\n", *i+1);

    printf("Nombre del pais: ");
    fgets(country->name, sizeof(country->name), stdin);
    printf("Seleccion nacional de futbol: ");
    fgets(country->nameSelection, sizeof(country->nameSelection), stdin);
    printf("Ranking UEFA del pais: ");
    scanf("%d", &country->ranking);
    miFflush();  // Limpiar el buffer después de scanf
}

void capturarEquipo(struct Team *team, int *j) {

    printf("\nCapturando datos para el equipo #%d:\n", *j+1);

    printf("Nombre del equipo: ");
    fgets(team->name, sizeof(team->name), stdin);
    miFflush();
    printf("Ciudad de origen: ");
    fgets(team->city, sizeof(team->city), stdin);
    printf("Estadio principal: ");
    fgets(team->stadium, sizeof(team->stadium), stdin);
    printf("Anio de fundacion: ");
    scanf("%d", &team->year);
    miFflush();  // Limpiar el buffer después de scanf
}

void imprimirDatos(struct Country *countries, int numCountries) {
    for (int i = 0; i < numCountries; i++) {
        printf("\nDatos del pais #%d:\n", i + 1);
        printf("Nombre: %s", countries[i].name);
        printf("Seleccion Nacional: %s", countries[i].nameSelection);
        printf("Ranking UEFA: %d\n", countries[i].ranking);

        for (int j = 0; j < countries[i].numTeams; j++) {
            printf("\nEquipo %d:\n", j + 1);
            printf("Nombre: %s", countries[i].teams[j].name);
            printf("Ciudad: %s", countries[i].teams[j].city);
            printf("Estadio: %s", countries[i].teams[j].stadium);
            printf("Anio de Fundacion: %d\n", countries[i].teams[j].year);
        }
    }
}