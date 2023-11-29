//
// Created by Marthel Rodriguez on 11/28/23.
//

#ifndef SFMLTEMPLATE_POKEMONSTRUCT_H
#define SFMLTEMPLATE_POKEMONSTRUCT_H

#include <string>
#include <array>

enum TypesEnum { BUG, DRAGON, ELECTRIC, FIGHTING, FIRE, FLYING, GHOST, GRASS, GROUND, ICE, NORMAL, POISON, PSYCHIC, ROCK, WATER, ANOTHERTYPE };

struct PokemonStruct {
    int number;
    std::string name;
    std::string about;
//    this could be just an array of numbers, and the frontend just fetches the pointers from the array.
    std::array<int,3> evolutions;
    int cols;
//    TypesEnum type;
//    std::vector<TypesEnum> weaknesses;
//    std::string pathCry;

};

#endif //SFMLTEMPLATE_POKEMONSTRUCT_H
