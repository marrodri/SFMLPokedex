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
    std::array<PokemonStruct, POKEMON_COUNT> pokemonList = {
            ///page 1.
            PokemonStruct({1, "Bulbasaur",
                           "A strange seed was planted on its back at birth. The plant sprouts and grows with this pokemon.\nIt can go for days without eating a single morsel. In the bulb on its back, it stores energy.\n",
                           std::array<int, 3>({1, 2, 3}), 41, 3, {FIRE, FLYING, PSYCHIC}, {GRASS, POISON},false}),
            PokemonStruct({2, "Ivysaur", "Need more research about Ivysaur",
                           std::array<int, 3>({1, 2, 3}), 49, 3, {FIRE, FLYING, ICE}, {GRASS, POISON},false}),
            PokemonStruct({3, "Venusaur", "Need more research about Ivysaur",
                           std::array<int, 3>({1, 2, 3}), 59, 3, {FIRE, FLYING, ICE}, {GRASS, POISON},false}),
            PokemonStruct({4, "Charmander", "Need more research about Ivysaur",
                           std::array<int, 3>({4, 5, 6}), 69, 3, {WATER, GROUND, ROCK}, {FIRE},false}),
            PokemonStruct({5, "Charmeleon", "Need more research about Charmeleon",
                           std::array<int, 3>({4, 5, 6}), 59, 3, {WATER, GROUND, ROCK}, {FIRE},false}),
            PokemonStruct({6, "Charizard", "Need more research about Charizard",
                           std::array<int, 3>({4, 5, 6}), 47, 3, {WATER, GROUND, ROCK}, {FIRE, FLYING},false}),
            ///checkpoint in weakness types.
            PokemonStruct({7, "Squirtle", "Need more research about Squirtle",
                           std::array<int, 3>({7, 8, 9}), 29, 3, {WATER, GROUND, ROCK}, {WATER},false}),
            PokemonStruct({8, "Wartotle", "Need more research about Wartotle",
                           std::array<int, 3>({7, 8, 9}), 31, 3, {WATER, GROUND, ROCK}, {WATER},false}),
            PokemonStruct({9, "Blastoise", "Need more research about Blastoise",
                           std::array<int, 3>({7, 8, 9}), 79, 3, {WATER, GROUND, ROCK}, {WATER},false}),
            ///TODO: checkpoint for Weakness and its about.
            PokemonStruct({10, "Caterpie", "Resources/Sprites/3DSprites/010.png",
                           std::array<int, 3>({10, 11, 12}), 49, 3, {}, {BUG},false}),
            PokemonStruct({11, "Metapod", "Resources/Sprites/3DSprites/011.png",
                           std::array<int, 3>({10, 11, 12}), 60, 3, {}, {BUG},false}),
            PokemonStruct({12, "Butterfree", "Resources/Sprites/3DSprites/012.png",
                           std::array<int, 3>({10, 11, 12}), 63, 3, {}, {BUG, FLYING},false}),
            PokemonStruct({13, "Weedle", "Resources/Sprites/3DSprites/013.png",
                           std::array<int, 3>({13, 14, 15}), 59, 3, {}, {BUG, POISON},false}),
            PokemonStruct({14, "Kakuna", "Resources/Sprites/3DSprites/014.png",
                           std::array<int, 3>({13, 14, 15}), 74, 3, {}, {BUG, POISON},false}),
            PokemonStruct({15, "Beedrill", "Resources/Sprites/3DSprites/015.png",
                           std::array<int, 3>({13, 14, 15}), 120, 3, {}, {BUG, POISON},false}),
            PokemonStruct({16, "Pidgey", "",
                           std::array<int, 3>({16, 17, 18}), 24, 3, {}, {NORMAL, FLYING},false}),
            PokemonStruct({17, "Pidgeotto", "",
                           std::array<int, 3>({16, 17, 18}), 20, 3, {}, {NORMAL, FLYING},false}),
            PokemonStruct({18, "Pidgeot", "",
                           std::array<int, 3>({16, 17, 18}), 53, 3, {}, {NORMAL, FLYING},false}),
            PokemonStruct({19, "Rattata", "",
                           std::array<int, 3>({19, 20, -1}), 25, 2, {}, {NORMAL},false}),
            PokemonStruct({20, "Raticate", "",
                           std::array<int, 3>({19, 20, -1}), 61, 2, {}, {NORMAL},false}),
            PokemonStruct({21, "Spearow", "",
                           std::array<int, 3>({21, 22, -1}), 24, 2, {}, {NORMAL, FLYING},false}),
            PokemonStruct({22, "Fearow", "",
                           std::array<int, 3>({21, 22, -1}), 50, 2, {}, {NORMAL, FLYING},false}),
            ///checkpoint to 28
            PokemonStruct({23, "Ekans", "",
                           std::array<int, 3>({23, 24, -1}), 48, 2, {}, {POISON},false}),
            PokemonStruct({24, "Arbok", "",
                           std::array<int, 3>({23, 24, -1}), 80, 1, {}, {POISON},false}),
            PokemonStruct({25, "Pikachu", "",
                           std::array<int, 3>({25, 26, -1}), 33, 2, {}, {ELECTRIC},true}),

            PokemonStruct({26, "Raichu", "",
                           std::array<int, 3>({25, 26, -1}), 29, 2, {}, {ELECTRIC},false}),
            PokemonStruct({27, "Sandshrew", "",
                           std::array<int, 3>({27, 28, -1}), 30, 2, {}, {GROUND},false}),
            PokemonStruct({28, "Sandslash", "",
                           std::array<int, 3>({27, 28, -1}), 48, 2, {}, {GROUND},false}),
            ///page 2.

            PokemonStruct({29, "Nidoran", "",
                           std::array<int, 3>({29, 30, 31}), 64, 3, {}, {POISON}}),
            PokemonStruct({30, "Nidorina", "",
                           std::array<int, 3>({29, 30, 31}), 40, 3, {}, {POISON}}),
            PokemonStruct({31, "Nidoquen", "",
                           std::array<int, 3>({29, 30, 31}), 50, 3, {}, {POISON, GROUND}}),
            PokemonStruct({32, "Nidoran", "",
                           std::array<int, 3>({32, 33, 34}), 50, 3, {}, {POISON}}),
            PokemonStruct({33, "Nidorino", "",
                           std::array<int, 3>({32, 33, 34}), 50, 3, {}, {POISON}}),
            PokemonStruct({34, "Nidoking", "",
                           std::array<int, 3>({32, 33, 34}), 42, 3, {}, {POISON, GROUND}}),
            PokemonStruct({35, "Clefairy", "",
                           std::array<int, 3>({35, 36, -1}), 40, 2, {}, {NORMAL}}),
            PokemonStruct({36, "Clefable", "",
                           std::array<int, 3>({35, 36, -1}), 40, 2, {}, {NORMAL}}),
            PokemonStruct({37, "Vulpix", "",
                           std::array<int, 3>({37, 38, -1}), 40, 2, {}, {FIRE}}),
            PokemonStruct({38, "Ninetails", "Please add more data about Ninetails",
                           std::array<int, 3>({37, 38, -1}), 59, 2, {WATER,ROCK, GROUND}, {FIRE, NORMAL}}),
           //new pokemons added.
            PokemonStruct({-1, "", "",
                           std::array<int, 3>({-1, -1, -1}), 0, 0, {}, {}}),


//69


            ///NEW POKEMON TOADD.

            //32
    };
public:
    PokemonList();

    PokemonStruct &getPokemonData(int index);
    void setDescription(int index, std::string &descr);

    //paging.
    void setCurrentPage(int i);
    int getStartingPokemon();
    int getLastPokemon();



};

#endif //SFMLTEMPLATE_POKEMONLIST_H
