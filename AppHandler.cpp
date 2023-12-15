//
// Created by Marthel Rodriguez on 12/6/23.
//

#include "AppHandler.h"
#include "Screen/ScreenHandler.h"

std::string AppHandler::searchInput;
//PokemonList AppHandler::pokemonList;


/**
 *
 * */
bool AppHandler::pokemonFilterHasChanged = false;
TypesEnum AppHandler::pokemonTypeFilter1 = ANOTHERTYPE;
TypesEnum AppHandler::pokemonTypeFilter2 = ANOTHERTYPE;
TypesEnum AppHandler::pokemonWeaknessFilter1 = ANOTHERTYPE;
TypesEnum AppHandler::pokemonWeaknessFilter2 = ANOTHERTYPE;
TypesEnum AppHandler::pokemonWeaknessFilter3 = ANOTHERTYPE;

int AppHandler::currPage = 0;
int AppHandler::pageMaxCap = 2;

/**
* app configuration
* */
int AppHandler::currentTheme = 0;
int AppHandler::currentFontSize = 0;
int AppHandler::currentFontFamily = 0;
int AppHandler::currentFontColor = 0;
std::array<sf::Color, 3> AppHandler::backgroundColor = {sf::Color::Blue, sf::Color::Yellow, sf::Color(0x236635ff)};
std::array<sf::Color, 3> AppHandler::fileTreeBackgroundColor = {sf::Color(0x4290e3af), sf::Color::Yellow,
                                                                sf::Color(0x72ad68af)};

std::array<sf::Color, 3> AppHandler::subcontainersBackgroundColor = {sf::Color(0x4290e3af), sf::Color::Yellow,
                                                                     sf::Color(0x74edadff)};
PokemonList AppHandler::pokemonList;

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


sf::Color &AppHandler::getBackgroundColor() {
    return backgroundColor[currentTheme];
}

sf::Color &AppHandler::getFileTreeBackgroundColor() {
    return fileTreeBackgroundColor[currentTheme];
}

void AppHandler::changeBackground() {
    std::cout << "running changeBackground from AppHandler" << std::endl;
    if (currentTheme >= 3) {
        currentTheme = 0;
    } else {
        currentTheme++;
    }
}

void AppHandler::changeFontFamily() {
    std::cout << "running changeFontFamily from AppHandler" << std::endl;

}

void AppHandler::changeFontColor() {
    std::cout << "running changeFontColor from AppHandler" << std::endl;
}

/**
 * filter methods
 **/

void AppHandler::setPokemonTypeFilter1(TypesEnum pokemonType) {
    pokemonFilterHasChanged=true;
    pokemonTypeFilter1 = pokemonType;
    std::cout << "setting pokemon type filter 1\n";
}

void AppHandler::setPokemonTypeFilter2(TypesEnum pokemonType) {
    pokemonFilterHasChanged=true;
    pokemonTypeFilter2 = pokemonType;
    std::cout << "setting pokemon type filter 2\n";
}

void AppHandler::setPokemonWeaknessFilter1(TypesEnum pokemonType) {
    pokemonFilterHasChanged=true;
    pokemonWeaknessFilter1 = pokemonType;
    std::cout << "setting pokemon weakness filter 1\n";
}

void AppHandler::setPokemonWeaknessFilter2(TypesEnum pokemonType) {
    pokemonFilterHasChanged=true;
    pokemonWeaknessFilter2 = pokemonType;
    std::cout << "setting pokemon weakness filter 2\n";
}

void AppHandler::setPokemonWeaknessFilter3(TypesEnum pokemonType) {
    pokemonFilterHasChanged=true;
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
    if (currPage < pageMaxCap - 1) {
        currPage++;
    }
}

void AppHandler::prevPage() {
    if (currPage > 0) {
        currPage--;
    }
}

void AppHandler::setPokemonFilterHasChanged(bool filterHasChanged) {
    pokemonFilterHasChanged = filterHasChanged;
}

bool AppHandler::getPokemonFilterHasChanged() {
    return pokemonFilterHasChanged;
}




