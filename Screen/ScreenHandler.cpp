//
// Created by Marthel Rodriguez on 11/29/23.
//

#include "ScreenHandler.h"

screenEnum ScreenHandler::currScreen;
PokemonStruct ScreenHandler::selectedPokemonData;
void ScreenHandler::setCurrentScreen(screenEnum screen) {
    currScreen = screen;
}

void ScreenHandler::setSelectedPokemonData(PokemonStruct &pokemonData) {
    std::cout << "SETTING POKEMON DATA!!!!!!! WOOT" <<"\n";
    std::cout << pokemonData.name <<"\n";
    selectedPokemonData = pokemonData;

}

screenEnum ScreenHandler::getCurrScreen() {
    return currScreen;
}

PokemonStruct &ScreenHandler::getSelectedPokemonData(){
    return selectedPokemonData;
}