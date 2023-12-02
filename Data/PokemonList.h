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
            PokemonStruct({1, "Bulbasaur", "Resources/Sprites/3DSprites/001.png",
                           std::array<int, 3>({1, 2, 3}), 41, 3}),
            PokemonStruct({2, "Ivysaur", "Resources/Sprites/3DSprites/002.png",
                           std::array<int, 3>({1, 2, 3}), 49, 3}),

            PokemonStruct({3, "Venusaur", "Resources/Sprites/3DSprites/003.png",
                           std::array<int, 3>({1, 2, 3}), 59, 3}),

            PokemonStruct({4, "Charmander", "Resources/Sprites/3DSprites/004.png",
                           std::array<int, 3>({1, 2, 3}), 69, 3}),

            PokemonStruct({5, "Charmeleon", "Resources/Sprites/3DSprites/005.png",
                           std::array<int, 3>({1, 2, 3}), 59, 3}),
            PokemonStruct({6, "Charizard", "Resources/Sprites/3DSprites/006.png",
                           std::array<int, 3>({1, 2, 3}), 47, 3}),

            PokemonStruct({7, "Squirtle", "Resources/Sprites/3DSprites/007.png",
                           std::array<int, 3>({1, 2, 3}), 29, 3}),
            PokemonStruct({8, "Wartotle", "Resources/Sprites/3DSprites/008.png",
                           std::array<int, 3>({1, 2, 3}), 31, 3}),
            PokemonStruct({9, "Blastoise", "Resources/Sprites/3DSprites/009.png",
                           std::array<int, 3>({1, 2, 3}), 79, 3}),
            //TODO cols CHECKPOINT
            PokemonStruct({10, "Caterpie", "Resources/Sprites/3DSprites/010.png",
                           std::array<int, 3>({1, 2, 3}), 49, 3}),
            PokemonStruct({11, "Metapod", "Resources/Sprites/3DSprites/011.png",
                           std::array<int, 3>({1, 2, 3}), 60, 3}),
            PokemonStruct({12, "Butterfree", "Resources/Sprites/3DSprites/012.png",
                           std::array<int, 3>({1, 2, 3}), 63, 3}),
            PokemonStruct({13, "Weedle", "Resources/Sprites/3DSprites/013.png",
                           std::array<int, 3>({1, 2, 3}), 59, 3}),
            //TODO: update the cols
    };
public:
    PokemonList();

    PokemonStruct &getPokemonData(int index);


};

#endif //SFMLTEMPLATE_POKEMONLIST_H
