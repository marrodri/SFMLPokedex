//
// Created by Marthel Rodriguez on 12/6/23.
//

#include "AppHandler.h"
#include "Screen/ScreenHandler.h"

std::string AppHandler::searchInput;
//PokemonList AppHandler::pokemonList;
TypesEnum AppHandler::pokemonTypeFilter1 = ANOTHERTYPE;
TypesEnum AppHandler::pokemonTypeFilter2 = ANOTHERTYPE;
TypesEnum AppHandler::pokemonWeaknessFilter1 = ANOTHERTYPE;
TypesEnum AppHandler::pokemonWeaknessFilter2 = ANOTHERTYPE;
TypesEnum AppHandler::pokemonWeaknessFilter3 = ANOTHERTYPE;

int AppHandler::currPage=0;
int AppHandler::pageMaxCap=2;

/**
* app configuration
* */
int AppHandler::currentTheme=0;
int AppHandler::currentFontSize=0;
int AppHandler::currentFontFamily=0;
int AppHandler::currentFontColor=0;

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
    ScreenHandler::setCurrentScreen(FILE_TREE_SCREEN);
}

void AppHandler::changeBackground() {
    std::cout << "running changeBackground from AppHandler" << std::endl;
    std::array<int, 3> backgroundColor={};
    std::array<int, 3> fileTreeBackgroundColor={};
    std::array<int, 3> homeScreenBackgroundColor={};

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

void AppHandler::nextPage() {
    if(currPage < pageMaxCap-1){
        currPage++;
    }
}

void AppHandler::prevPage() {
    if(currPage > 0){
        currPage--;
    }
}

