//
// Created by Marthel Rodriguez on 11/29/23.
//

#ifndef SFMLTEMPLATE_SCREENHANDLER_H
#define SFMLTEMPLATE_SCREENHANDLER_H

#include "ScreenEnum.h"
#include "../Data/PokemonStruct.h"
#include <iostream>
#include <map>

//the main screen left and right buttons
//will have to check the current screen as it will .

//main screen: update the mainScreen GridView pokemons
//PokemonScreen: go to the next or previous page.

class ScreenHandler {
private:
    static screenEnum currScreen;
    static PokemonStruct selectedPokemonData;
    static bool pokemonScreenLoaded;
    static std::map<pokemonScreenElementsEnum, bool> pokemonScreenElementsLoaded;
    static std::map<homeScreenElementsEnum, bool> homeScreenElementsLoaded;
public:
    static void setCurrentScreen(screenEnum screen);
    static screenEnum getCurrScreen();

    /// selectedPokemon
    static void setSelectedPokemonData(PokemonStruct &pokemonData);
    static PokemonStruct &getSelectedPokemonData();

    /// pokemonScreen Status;
    static void setPokemonScreenElementLoaded(pokemonScreenElementsEnum pokemonScreenElement, bool isLoaded);
    static bool getPokemonScreenElementLoaded(pokemonScreenElementsEnum pokemonScreenElement);
    static void toggleOffPokemonScreenElements();

    static void toggleOnPokemonScreenElements();


    ///home screen
    static void setHomeScreenLoaded(bool isLoaded);
    static bool isHomeScreenLoaded();
};


#endif //SFMLTEMPLATE_SCREENHANDLER_H
