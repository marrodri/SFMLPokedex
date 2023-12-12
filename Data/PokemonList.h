//
// Created by Marthel Rodriguez on 11/29/23.
//

#ifndef SFMLTEMPLATE_POKEMONLIST_H
#define SFMLTEMPLATE_POKEMONLIST_H

#include <array>
#include "PokemonStruct.h"
#include <iostream>

const int POKEMON_COUNT = 56;

class PokemonList {
private:
    static std::array<PokemonStruct, POKEMON_COUNT> pokemonList;
public:
//    PokemonList();

    static PokemonStruct &getPokemonData(int index);
    static void setDescription(int index, std::string &descr);

    //paging.
    static void setCurrentPage(int i);
    static int getStartingPokemon();
    static int getLastPokemon();



};

#endif //SFMLTEMPLATE_POKEMONLIST_H
