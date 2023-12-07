//
// Created by Marthel Rodriguez on 11/29/23.
//

#include "ScreenHandler.h"
#include "../States/States.h"

screenEnum ScreenHandler::currScreen;
PokemonStruct ScreenHandler::selectedPokemonData;
bool ScreenHandler::searchInputFocused;

std::map<pokemonScreenElementsEnum, bool> ScreenHandler::pokemonScreenElementsLoaded;
std::map<homeScreenElementsEnum, bool> ScreenHandler::homeScreenElementsLoaded;

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

bool ScreenHandler::isSearchInputFocused(){
    return searchInputFocused;
}

void ScreenHandler::setSearchInputIsFocused(bool option) {
    searchInputFocused = option;
}


///home screen

