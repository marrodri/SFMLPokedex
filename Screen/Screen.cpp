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
    if (ScreenHandler::getCurrScreen() == HOME) {
        mainScreen.draw(target, states);
    } else if (ScreenHandler::getCurrScreen() == POKEMON) {
        pokemonScreen.draw(target, states);
    }
    target.draw(leftButton);
    target.draw(rightButton);
    target.draw(searchInput);
    target.draw(sideMenu);
    target.draw(logo);
}

void Screen::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (ScreenHandler::getCurrScreen() == HOME && !ScreenHandler::isSearchInputFocused()) {
        mainScreen.addEventHandler(window, event);
    } else if (ScreenHandler::getCurrScreen() == POKEMON) {
        pokemonScreen.addEventHandler(window, event);
    }
    leftButton.addEventHandler(window, event);
    rightButton.addEventHandler(window, event);

    searchInput.addEventHandler(window, event);
    sideMenu.addEventHandler(window, event);
    logo.addEventHandler(window, event);
}

void Screen::update() {
    if (ScreenHandler::getCurrScreen() == HOME) {
        mainScreen.update();
    } else if (ScreenHandler::getCurrScreen() == POKEMON) {
        pokemonScreen.update();
    }
    searchInput.update();
    sideMenu.update();
    logo.update();
}


