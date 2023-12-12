//
// Created by Marthel Rodriguez on 11/28/23.
//



#include "PokemonList.h"

PokemonList::PokemonList() {

}

PokemonStruct &PokemonList::getPokemonData(int index) {
    return pokemonList[index];
}

void PokemonList::setDescription(int index, std::string &descr) {
    std::cout <<"new setted description: " << descr<<"\n";
    pokemonList[index-1].about = descr;

}



