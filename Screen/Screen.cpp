//
// Created by Marthel Rodriguez on 10/12/23.
//

#include "Screen.h"
#include "ScreenHandler.h"


Screen::Screen() : leftButton({840, 551}, "L"),
                   rightButton({890, 551}, "R") {


}


Screen::Screen(sf::Vector2f windowSize) : leftButton({840, 551}, "L"),
                                          rightButton({890, 551}, "R") {
    ///TODO: DEBUGGER CODE, DELETE THIS WHEN IT WORKS.
//    ScreenHandler::setSelectedPokemonData(AppHandler::pokemonList.getPokemonData(0));
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
        searchInput.addEventHandler(window, event);
        sideMenu.addEventHandler(window, event);
        logo.addEventHandler(window, event);
        if (MouseEvents<MainScreenButton>::mouseClicked(leftButton, window)) {
            AppHandler::prevPage();
        }
        if (MouseEvents<MainScreenButton>::mouseClicked(rightButton, window)) {
            AppHandler::prevPage();
        }
    }
}

void Screen::update() {
    background.setFillColor(AppHandler::getBackgroundColor());
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


