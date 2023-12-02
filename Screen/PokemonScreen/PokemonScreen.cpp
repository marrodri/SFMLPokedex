//
// Created by Marthel Rodriguez on 11/21/23.
//

#include "PokemonScreen.h"
#include "../../Helper/HelperFunctions.h"
#include "../../Font/Font.h"
#include "../ScreenHandler.h"


//container(sf::Vector2f pos, sf::Vector2f size, sf::Color &color)
//title(const std::string &str, int fontSize, sf::Vector2f pos, sf::Font &font);
//ScreenHandler::getSelectedPokemonData().number
//ScreenHandler::getSelectedPokemonData().cols
PokemonScreen::PokemonScreen() : spriteDisplay(1, 41), evolutions(std::array<int, 3>{1, 1, 1}, 41) {
    std::cout << "Displaying pokemon screen:" << ScreenHandler::getSelectedPokemonData().name << "\n";
    container.setSize({90 * 8, 4 * 110});
    container.setPosition({250, 100});
    container.setFillColor(sf::Color::Green);
    title.setFont(Font::getFont());
    title.setString("Pokemon Screen");
    title.setCharacterSize(24);
    HelperFunctions::centerItem(container, title);
}

void PokemonScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (ScreenHandler::getCurrScreen() == POKEMON) {
        target.draw(container);
        target.draw(title);
        header.draw(target, states);
        spriteDisplay.draw(target, states);
        description.draw(target, states);
        evolutions.draw(target, states);
        pokemonWeakness.draw(target, states);
        pokemonType.draw(target, states);
    }
}

void PokemonScreen::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (ScreenHandler::getCurrScreen() == POKEMON) {
        header.addEventHandler(window, event);
        description.addEventHandler(window, event);
        evolutions.addEventHandler(window, event);
        pokemonWeakness.addEventHandler(window, event);
        pokemonType.addEventHandler(window, event);
    }
}

void PokemonScreen::update() {
//    if (ScreenHandler::getCurrScreen() == POKEMON) {
        header.update();
        spriteDisplay.update();
        description.update();
        evolutions.update();
        pokemonWeakness.update();
        pokemonType.update();
//    }
}
