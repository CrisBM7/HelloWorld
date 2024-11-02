#ifndef MIPOKEMON_H
#define MIPOKEMON_H

typedef struct
{
    char nombre[50];
    char tipo[50];
    int healthPoints;
    int atackPoints;
} Pokemon;

void addPokemon(Pokemon *pokemon);
void ordPokePA(Pokemon *pokemon);
void sacarProm(Pokemon *pokemon, float *promHP, float *promAT);
void imprimirPokemons(Pokemon *pokemon, float *promHP, float *promAT);

#endif