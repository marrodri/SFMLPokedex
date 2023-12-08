//
// Created by Marthel Rodriguez on 12/6/23.
//

#include "AppHandler.h"

std::string AppHandler::searchInput;
TypesEnum AppHandler::pokemonTypeFilter1=ANOTHERTYPE;
TypesEnum AppHandler::pokemonTypeFilter2=ANOTHERTYPE;
TypesEnum AppHandler::pokemonWeaknessFilter1=ANOTHERTYPE;
TypesEnum AppHandler::pokemonWeaknessFilter2=ANOTHERTYPE;
TypesEnum AppHandler::pokemonWeaknessFilter3=ANOTHERTYPE;

/**
 * searchInput methods
 **/
std::string AppHandler::getSearchInput() {
    return searchInput;
}

void AppHandler::updateSearchInput(const std::string &input) {
    searchInput = input;
}

/**
 * menu Methods
 **/
void AppHandler::closeProgram() {
    std::cout << "running closeProgram from AppHandler" << std::endl;
}

void AppHandler::openFileTree() {
    std::cout << "running openFileTree from AppHandler" << std::endl;
    std::cout << "OPENING FILE TREE SCREEN" << std::endl;
}

void AppHandler::changeBackground() {
    std::cout << "running changeBackground from AppHandler" << std::endl;
}

void AppHandler::changeFontFamily() {
    std::cout << "running changeFontFamily from AppHandler" << std::endl;
}

void AppHandler::changeFontColor() {
    std::cout << "running changeFontColor from AppHandler" << std::endl;
}

/**
 * filter methods
 * */

void AppHandler::setPokemonTypeFilter1(TypesEnum pokemonType) {
    pokemonTypeFilter1 = pokemonType;
    std::cout << "setting pokemon type filter 1\n";

}

void AppHandler::setPokemonTypeFilter2(TypesEnum pokemonType) {
    pokemonTypeFilter2 = pokemonType;
    std::cout << "setting pokemon type filter 2\n";
}

void AppHandler::setPokemonWeaknessFilter1(TypesEnum pokemonType) {
    pokemonWeaknessFilter1 = pokemonType;
    std::cout << "setting pokemon weakness filter 1\n";
}

void AppHandler::setPokemonWeaknessFilter2(TypesEnum pokemonType) {
    pokemonWeaknessFilter2 = pokemonType;
    std::cout << "setting pokemon weakness filter 2\n";
}

void AppHandler::setPokemonWeaknessFilter3(TypesEnum pokemonType) {
    pokemonWeaknessFilter3 = pokemonType;
    std::cout << "setting pokemon weakness filter 3\n";
}


TypesEnum AppHandler::getPokemonTypeFilter1() {
    return pokemonTypeFilter1;
}

TypesEnum AppHandler::getPokemonTypeFilter2() {
    return pokemonTypeFilter2;
}

TypesEnum AppHandler::getPokemonWeaknessFilter1() {
    return pokemonWeaknessFilter1;
}

TypesEnum AppHandler::getPokemonWeaknessFilter2() {
    return pokemonWeaknessFilter2;
}

TypesEnum AppHandler::getPokemonWeaknessFilter3() {
    return pokemonWeaknessFilter3;
}


