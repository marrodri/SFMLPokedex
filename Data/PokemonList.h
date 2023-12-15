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
            PokemonStruct({10, "Caterpie", "Need more research about Caterpie",
                           std::array<int, 3>({10, 11, 12}), 49, 3, {}, {BUG},false}),
            PokemonStruct({11, "Metapod", "Need more research about Metapod",
                           std::array<int, 3>({10, 11, 12}), 60, 3, {}, {BUG},false}),
            PokemonStruct({12, "Butterfree", "Need more research about Butterfree",
                           std::array<int, 3>({10, 11, 12}), 63, 3, {}, {BUG, FLYING},false}),
            PokemonStruct({13, "Weedle", "Need more research about Weedle",
                           std::array<int, 3>({13, 14, 15}), 59, 3, {}, {BUG, POISON},false}),
            PokemonStruct({14, "Kakuna", "Need more research about Kakuna",
                           std::array<int, 3>({13, 14, 15}), 74, 3, {}, {BUG, POISON},false}),
            PokemonStruct({15, "Beedrill", "Need more research about Beedrill",
                           std::array<int, 3>({13, 14, 15}), 120, 3, {}, {BUG, POISON},false}),
            PokemonStruct({16, "Pidgey", "Need more research about Pidgey",
                           std::array<int, 3>({16, 17, 18}), 24, 3, {}, {NORMAL, FLYING},false}),
            PokemonStruct({17, "Pidgeotto", "Need more research about Pidgeotto",
                           std::array<int, 3>({16, 17, 18}), 20, 3, {}, {NORMAL, FLYING},false}),
            PokemonStruct({18, "Pidgeot", "Need more research about Pidgeot",
                           std::array<int, 3>({16, 17, 18}), 53, 3, {}, {NORMAL, FLYING},false}),
            PokemonStruct({19, "Rattata", "Need more research about Rattata",
                           std::array<int, 3>({19, 20, -1}), 25, 2, {}, {NORMAL},false}),
            PokemonStruct({20, "Raticate", "Need more research about Raticate",
                           std::array<int, 3>({19, 20, -1}), 61, 2, {}, {NORMAL},false}),
            PokemonStruct({21, "Spearow", "Need more research about Spearow",
                           std::array<int, 3>({21, 22, -1}), 24, 2, {}, {NORMAL, FLYING},false}),
            PokemonStruct({22, "Fearow", "Need more research about Fearow",
                           std::array<int, 3>({21, 22, -1}), 50, 2, {}, {NORMAL, FLYING},false}),
            ///checkpoint to 28
            PokemonStruct({23, "Ekans", "Need more research about Ekans",
                           std::array<int, 3>({23, 24, -1}), 48, 2, {}, {POISON},false}),
            PokemonStruct({24, "Arbok", "Need more research about Arbok",
                           std::array<int, 3>({23, 24, -1}), 80, 1, {}, {POISON},false}),
            PokemonStruct({25, "Pikachu", "Need more research about Pikachu",
                           std::array<int, 3>({25, 26, -1}), 33, 2, {}, {ELECTRIC},true, 12}),

            PokemonStruct({26, "Raichu", "Need more research about Raichu",
                           std::array<int, 3>({25, 26, -1}), 29, 2, {}, {ELECTRIC},false}),
            PokemonStruct({27, "Sandshrew", "Need more research about Sandshrew",
                           std::array<int, 3>({27, 28, -1}), 30, 2, {}, {GROUND},false}),
            PokemonStruct({28, "Sandslash", "Need more research about Sandslash",
                           std::array<int, 3>({27, 28, -1}), 48, 2, {}, {GROUND},false}),
            ///page 2.

            PokemonStruct({29, "Nidoran", "Need more research about Nidoran",
                           std::array<int, 3>({29, 30, 31}), 64, 3, {}, {POISON}}),
            PokemonStruct({30, "Nidorina", "Need more research about Nidorina",
                           std::array<int, 3>({29, 30, 31}), 40, 3, {}, {POISON}}),
            PokemonStruct({31, "Nidoquen", "Need more research about Nidoquen",
                           std::array<int, 3>({29, 30, 31}), 50, 3, {}, {POISON, GROUND}}),
            PokemonStruct({32, "Nidoran", "Need more research about Nidoran",
                           std::array<int, 3>({32, 33, 34}), 50, 3, {}, {POISON}}),
            PokemonStruct({33, "Nidorino", "Need more research about Nidorino",
                           std::array<int, 3>({32, 33, 34}), 50, 3, {}, {POISON}}),
            PokemonStruct({34, "Nidoking", "Need more research about Nidoking",
                           std::array<int, 3>({32, 33, 34}), 42, 3, {}, {POISON, GROUND}}),
            PokemonStruct({35, "Clefairy", "Need more research about Clefairy",
                           std::array<int, 3>({35, 36, -1}), 40, 2, {}, {NORMAL}}),
            PokemonStruct({36, "Clefable", "Need more research about Clefable",
                           std::array<int, 3>({35, 36, -1}), 40, 2, {}, {NORMAL}}),
            PokemonStruct({37, "Vulpix", "Need more research about Vulpix",
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
    void unlockPikachu();

    //paging.
    void setCurrentPage(int i);
    int getStartingPokemon();
    int getLastPokemon();



};

#endif //SFMLTEMPLATE_POKEMONLIST_H
