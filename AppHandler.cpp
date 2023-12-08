//
// Created by Marthel Rodriguez on 12/6/23.
//

#include "AppHandler.h"

std::string AppHandler::searchInput;
TypesEnum AppHandler::pokemonTypeFilter1;
TypesEnum AppHandler::pokemonTypeFilter2;
TypesEnum AppHandler::pokemonWeaknessFilter1;
TypesEnum AppHandler::pokemonWeaknessFilter2;
TypesEnum AppHandler::pokemonWeaknessFilter3;

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

void AppHandler::setPokemonTypeFilter1(){
    std::cout << "setting pokemon type filter 1\n";
}
void AppHandler::setPokemonTypeFilter2(){
    std::cout << "setting pokemon type filter 2\n";
}
void AppHandler::setPokemonWeaknessFilter1(){
    std::cout << "setting pokemon weakness filter 1\n";
}
void AppHandler::setPokemonWeaknessFilter2(){
    std::cout << "setting pokemon weakness filter 2\n";
}
void AppHandler::setPokemonWeaknessFilter3(){
    std::cout << "setting pokemon weakness filter 3\n";
}


