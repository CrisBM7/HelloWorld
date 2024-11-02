#include <stdio.h>
#include "miPokemon.h"

// gcc mainPokemon.c -L. -lmiPokemon -o mainPokemon
//./mainPokemon

int main()
{
    Pokemon pokemons[6] = {
        {"Pikachu", "Electrico", 35, 55},
        {"Charmander", "Fuego", 39, 52},
        {"Bulbasuar", "Planta", 45, 49},
        {"Squirtle", "Agua", 44, 48}
    };

    float promHP = 0;
    float promAT = 0;

    addPokemon(&pokemons[5]);
    imprimirPokemons(pokemons, &promHP, &promAT);

    return 0;
}