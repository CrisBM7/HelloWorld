#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void miFflush() {
    while (getchar() != '\n')
        ;
}

struct Country {
    char name[50];
    char nameSelection[50];
    char **teams;
    int ranking;
    int numTeams;
};

void capturarPais(struct Country *country, int *i);
void capturarEquipo(char team[], int j);
void imprimirDatos(struct Country *countries, int numCountries);

int main() {
    int numCountries;

    printf("Ingrese el numero de paises: ");
    scanf("%d", &numCountries);
    miFflush();

    struct Country *countries = (struct Country *)malloc(numCountries * sizeof(struct Country));

    for (int i = 0; i < numCountries; i++) {
        capturarPais(&countries[i], &i);

        printf("Numero de equipos: ");
        scanf("%d", &countries[i].numTeams);
        miFflush();
        countries[i].teams = (char **)malloc(countries[i].numTeams * sizeof(char *));

        for (int j = 0; j < countries[i].numTeams; j++) {
            countries[i].teams[j] = (char *)malloc(20 * sizeof(char));
            capturarEquipo(countries[i].teams[j], j);
        }
    }

    printf("\n||||||||||||Informacion de los paises y equipos||||||||||||\n");
    imprimirDatos(countries, numCountries);

    for (int i = 0; i < numCountries; i++) {
        free(countries[i].teams);
    }
    free(countries);

    return 0;
}

void capturarPais(struct Country *country, int *i) {
    printf("\nPais #%d:\n", *i + 1);

    printf("Nombre del pais: ");
    fgets(country->name, sizeof(country->name), stdin);

    printf("Seleccion nacional de futbol: ");
    fgets(country->nameSelection, sizeof(country->nameSelection), stdin);

    printf("Ranking UEFA del pais: ");
    scanf("%d", &country->ranking);
    miFflush();
}

void capturarEquipo(char team[], int j) {
    printf("\nCapturando datos para el equipo #%d:\n", j + 1);

    printf("Nombre del equipo: ");
    fgets(team, 20, stdin);
}

void imprimirDatos(struct Country *countries, int numCountries) {
    for (int i = 0; i < numCountries; i++) {
        printf("\nDatos del pais #%d:\n", i + 1);
        printf("Nombre: %s", countries[i].name);
        printf("Seleccion Nacional: %s", countries[i].nameSelection);
        printf("Ranking UEFA: %d\n", countries[i].ranking);

        for (int j = 0; j < countries[i].numTeams; j++) {
            printf("\nEquipo %d:\n", j + 1);
            printf("Nombre: %s", countries[i].teams[j]);
        }
    }
}