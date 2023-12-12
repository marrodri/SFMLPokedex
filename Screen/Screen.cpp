//
// Created by Marthel Rodriguez on 10/12/23.
//

#include "Screen.h"
#include "ScreenHandler.h"
#include "../SFMLPokedex.h"


Screen::Screen() : leftButton({840, 551}, "L"),
                   rightButton({890, 551}, "R") {


}


Screen::Screen(sf::Vector2f windowSize) : leftButton({840, 551}, "L"),
                                          rightButton({890, 551}, "R") {
    ///TODO: DEBUGGER CODE, DELETE THIS WHEN IT WORKS.
//    ScreenHandler::setSelectedPokemonData(SFMLPokedex::pokemonList.getPokemonData(0));
//    ScreenHandler::setCurrentScreen(POKEMON);

    background.setFillColor(sf::Color::Blue);
    background.setSize(windowSize);
    background.setPosition(0, 0);
//    ScreenHandler::toggleOnPokemonScreenElements();
}


Screen::Screen(sf::Vector2f dimensions, sf::Font font) : leftButton({840, 551}, "L"),
                                                         rightButton({890, 551}, "R") {

}

/**
 * setters
 **/

void Screen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(background);

    ///TODO: Draw the other elements of the front-end.
    if (ScreenHandler::getCurrScreen() == HOME_SCREEN) {
        target.draw(mainScreen);
    } else if (ScreenHandler::getCurrScreen() == POKEMON_SCREEN) {
        target.draw(pokemonScreen);
    } else if (ScreenHandler::getCurrScreen() == FILE_TREE_SCREEN) {
        target.draw(fileTreeScreen);
    }
//    target.draw(leftButton);
//    target.draw(rightButton);
    target.draw(searchInput);
    target.draw(sideMenu);
    target.draw(logo);
}

void Screen::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (ScreenHandler::getCurrScreen() == HOME_SCREEN && !ScreenHandler::isSearchInputFocused() &&
        !ScreenHandler::isMenuBarFocused()) {
        mainScreen.addEventHandler(window, event);
    } else if (ScreenHandler::getCurrScreen() == POKEMON_SCREEN && !ScreenHandler::isMenuBarFocused()) {
        pokemonScreen.addEventHandler(window, event);
    } else if (ScreenHandler::getCurrScreen() == FILE_TREE_SCREEN) {
        fileTreeScreen.addEventHandler(window, event);
    }
    if (!ScreenHandler::isMenuBarFocused()) {
        leftButton.addEventHandler(window, event);
        rightButton.addEventHandler(window, event);

        searchInput.addEventHandler(window, event);
        sideMenu.addEventHandler(window, event);
        logo.addEventHandler(window, event);
    }

}

void Screen::update() {
    if (ScreenHandler::getCurrScreen() == HOME_SCREEN) {
        mainScreen.update();
    } else if (ScreenHandler::getCurrScreen() == POKEMON_SCREEN) {
        pokemonScreen.update();
    } else if (ScreenHandler::getCurrScreen() == FILE_TREE_SCREEN) {
        fileTreeScreen.update();
    }
    searchInput.update();
    sideMenu.update();
    logo.update();
}


