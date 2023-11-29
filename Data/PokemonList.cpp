//
// Created by Marthel Rodriguez on 11/28/23.
//



#include "PokemonList.h"

PokemonList::PokemonList() {

}

PokemonStruct &PokemonList::getPokemonData(int index) {
    return pokemonList[index];
}



