//
// Created by Marthel Rodriguez on 11/29/23.
//

#include "ScreenHandler.h"
#include "../States/States.h"

/**
 * screen handler static variables
 * */
screenEnum ScreenHandler::currScreen;
PokemonStruct ScreenHandler::selectedPokemonData;
bool ScreenHandler::searchInputFocused;
bool ScreenHandler::menuBarFocused=false;

std::map<menuOptionsEnum, bool> ScreenHandler::openedMenuBarOptions = {{FILE_MENU,   false},
                                                                      {WINDOW_MENU, false},
                                                                      {THEME_MENU,  false}};
std::map<pokemonScreenElementsEnum, bool> ScreenHandler::pokemonScreenElementsLoaded;
std::map<homeScreenElementsEnum, bool> ScreenHandler::homeScreenElementsLoaded;

/**
 * screenHandler static methods
 **/

void ScreenHandler::setCurrentScreen(screenEnum screen) {
    currScreen = screen;
}

void ScreenHandler::setSelectedPokemonData(PokemonStruct &pokemonData) {
    std::cout << "SETTING POKEMON DATA!!!!!!! WOOT" << "\n";
    std::cout << pokemonData.name << "\n";
    selectedPokemonData = pokemonData;
}


screenEnum ScreenHandler::getCurrScreen() {
    return currScreen;
}


PokemonStruct &ScreenHandler::getSelectedPokemonData() {
    return selectedPokemonData;
}


///pokemon screen
void ScreenHandler::setPokemonScreenElementLoaded(pokemonScreenElementsEnum pokemonScreenElement, bool isLoaded) {
    pokemonScreenElementsLoaded[pokemonScreenElement] = isLoaded;
}


bool ScreenHandler::getPokemonScreenElementLoaded(pokemonScreenElementsEnum pokemonScreenElement) {
    return pokemonScreenElementsLoaded[pokemonScreenElement];
}


void ScreenHandler::toggleOffPokemonScreenElements() {
    for (int i = 0; i < LAST_POKEMON_SCREEN_ELEMENT; i++) {
        //go through the states map, enable to false.
        pokemonScreenElementsLoaded[static_cast<pokemonScreenElementsEnum>(i)] = false;
    }
}


void ScreenHandler::toggleOnPokemonScreenElements() {
    for (int i = 0; i < LAST_POKEMON_SCREEN_ELEMENT; i++) {
        //go through the states map, enable to false.
        pokemonScreenElementsLoaded[static_cast<pokemonScreenElementsEnum>(i)] = true;
    }
}

bool ScreenHandler::isSearchInputFocused() {
    return searchInputFocused;
}

void ScreenHandler::setSearchInputIsFocused(bool option) {
    searchInputFocused = option;
}


///home screen
void ScreenHandler::setHomeScreenLoaded(bool isLoaded){}

bool ScreenHandler::isHomeScreenLoaded(){
    return false;
}

///

///menubar handler
bool ScreenHandler::isMenuBarFocused() {
    return menuBarFocused;
}

void ScreenHandler::setMenuBarIsFocused(bool option) {
    menuBarFocused = option;
}


void ScreenHandler::enableOpenedMenuBarOption(menuOptionsEnum menuOption) {
    openedMenuBarOptions[menuOption] = true;
}

void ScreenHandler::disableOpenedMenuBarOption(menuOptionsEnum menuOption) {
    openedMenuBarOptions[menuOption] = false;
}

bool ScreenHandler::checkOpenedMenuBarOption(menuOptionsEnum menuOption) {
    return openedMenuBarOptions[menuOption];
}
