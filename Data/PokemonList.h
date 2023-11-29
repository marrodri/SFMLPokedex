//
// Created by Marthel Rodriguez on 11/29/23.
//

#ifndef SFMLTEMPLATE_POKEMONLIST_H
#define SFMLTEMPLATE_POKEMONLIST_H

#include <array>
#include "PokemonStruct.h"

class PokemonList {
private:
    std::array<PokemonStruct, 25> pokemonList = {
            PokemonStruct({1, "Bulbasaur", "hi this is bul",
                           std::array<int, 3>({1, 2, 3}),41}),
            PokemonStruct({2, "Charmander", "hi this is char",
                           std::array<int, 3>({1, 2, 3}),49}),
            PokemonStruct({3, "Squirtle", "hi this is squir",
                           std::array<int, 3>({1, 2, 3}),59}),
            PokemonStruct({4, "Sqirtle", "hi this is squir",
                           std::array<int, 3>({1, 2, 3}),59}),
            PokemonStruct({5, "Sqirtle", "hi this is squir",
                           std::array<int, 3>({1, 2, 3}),59}),
            PokemonStruct({6, "Sqirtle", "hi this is squir",
                           std::array<int, 3>({1, 2, 3}),59}),
            PokemonStruct({7, "Sqirtle", "hi this is squir",
                           std::array<int, 3>({1, 2, 3}),59}),
            PokemonStruct({8, "Sqirtle", "hi this is squir",
                           std::array<int, 3>({1, 2, 3}),59}),
            PokemonStruct({9, "Sqirtle", "hi this is squir",
                           std::array<int, 3>({1, 2, 3}),59}),
            PokemonStruct({10, "Sqirtle", "hi this is squir",
                           std::array<int, 3>({1, 2, 3}),59}),
            PokemonStruct({11, "Sqirtle", "hi this is squir",
                           std::array<int, 3>({1, 2, 3}),59}),
            PokemonStruct({12, "Sqirtle", "hi this is squir",
                           std::array<int, 3>({1, 2, 3}),59}),




    };
public:
    PokemonList();

    PokemonStruct &getPokemonData(int index);


};

#endif //SFMLTEMPLATE_POKEMONLIST_H
