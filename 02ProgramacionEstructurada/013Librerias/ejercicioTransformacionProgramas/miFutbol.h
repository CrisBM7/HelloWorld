#ifndef MIFUTBOL_H
#define MIFUTBOL_H

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

#endif