#include "miPokemon.h"
#include <stdio.h>
#include <string.h>

// gcc -c miPokemon.c -o miPokemon.o
// ar rcs libmiPokemon.a miPokemon.o

void miFflush()
{
    while (getchar() != '\n');
}

void addPokemon(Pokemon *pokemon) // Falto *
{
    char nombrePokemon[20];
    char tipoPokemon[20];
    int vidaPokemon;
    int ataquePuntos;

    printf("Ingrese el nuevo Pokemon\n");
    printf("Ingrese el nombre de su pokemon: ");
    fgets(nombrePokemon, sizeof(nombrePokemon), stdin);
    strtok(nombrePokemon, "\n"); 
    strcpy(pokemon->nombre, nombrePokemon); // solo puedes igualar a cadena cuando inicializas, si no, usas strcpy
    printf("Ingrese el tipo de Pokemon: ");
    fgets(tipoPokemon, sizeof(tipoPokemon), stdin);
    strtok(tipoPokemon, "\n"); 
    strcpy(pokemon->tipo, tipoPokemon);
    printf("Ingrese los puntos de vida del Pokemon: ");
    scanf("%d", &vidaPokemon);
    pokemon->healthPoints = vidaPokemon;
    printf("Ingrese los puntos de ataque del Pokemon: ");
    scanf("%d", &ataquePuntos);
    pokemon->atackPoints = ataquePuntos;
    miFflush();
}

void ordPokePA(Pokemon *pokemon){
    int i, j;
    Pokemon pokemonTemp;

    for (int i = 0; i < 5; i++){
        for(int j = 0; j < 5-i-1; j++){
            if(pokemon[j].atackPoints > pokemon[j+1].atackPoints){
                pokemonTemp = pokemon[j];
                pokemon[j] = pokemon[j+1];
                pokemon[j+1] = pokemonTemp;
            }
        }
    }
    
}

void sacarProm(Pokemon *pokemon, float *promHP, float *promAT){
    for(int i = 0; i < 5; i++){
        *promHP = *promHP + pokemon[i].healthPoints;
        *promAT = *promAT + pokemon[i].atackPoints;
    }

    *promHP = *promHP/6;
    *promAT = *promAT/6;
}

void imprimirPokemons(Pokemon *pokemon, float *promHP, float *promAT){

    printf("\n-----------------------Equipo Pokemon-----------------------\n\n");
    printf("Nombre          Tipo            Pts Vida        Pts Ataque\n\n");
    
    for(int i = 0; i < 6; i++){
        int nomLen = strlen(pokemon[i].nombre);
        int typeLen = strlen(pokemon[i].tipo);
        int longitud = 0;

        printf("%s", pokemon[i].nombre);
        for(int j = 0; j < 16-nomLen; j++){
            printf(" ");
        }
        printf("%s", pokemon[i].tipo);
        for(int j = 0; j < 16-typeLen; j++){
            printf(" ");
        }
        printf("%d", pokemon[i].healthPoints);
        while (pokemon[i].healthPoints != 0) {
            pokemon[i].healthPoints /= 10;
            longitud++;
        }
        for(int j = 0; j < 16-longitud; j++){
            printf(" ");
        }
        printf("%d\n", pokemon[i].atackPoints);
    }

    printf("\n+ Pts de Vida: %s [%d]\n", pokemon[5].nombre, pokemon[5].healthPoints);
    printf("- Pts de Vida: %s [%d]\n\n", pokemon[0].nombre, pokemon[0].healthPoints);

    printf("Promedio pts vida: %.2f\n", *promHP);
    printf("Promedio pts ataque: %.2f", *promAT);
}