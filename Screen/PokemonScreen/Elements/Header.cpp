//
// Created by Marthel Rodriguez on 11/29/23.
//

#include "Header.h"
#include "../../../Font/Font.h"
#include "../../../Helper/HelperFunctions.h"
#include "../../../Images/Images.h"
#include "../../ScreenHandler.h"
#include "../../../MouseEvents/MouseEvents.h"
#include "../../../SoundFX/SoundFX.h"

Header::Header() : container({250, 100}, {90 * 8, 40}, sf::Color(0x4287f5ff)),
                   pokemonName("Pokemon Name", 25, Font::getFont(OPEN_SANS), {250, 100}),
                   pokemonNo("001:", 25, Font::getFont(OPEN_SANS), {300, 100}),
                   backIcon({180, 100}, {40, 40}, sf::Color::Red),
                   saveIcon({180, 100}, {40, 40}, sf::Color::Cyan) {
    backIcon.setTexture(Images::getImage(CROSS));
    HelperFunctions::centerItemHorizontally(container, pokemonName, 200);
    HelperFunctions::centerItemHorizontally(container, pokemonNo, 70);
    HelperFunctions::positionItemByBounds(container, backIcon, {0, 0});


    HelperFunctions::positionItemByBounds(container, editIcon, {580, 0});
    HelperFunctions::positionItemByBounds(container, printIcon, {630, 0});
    HelperFunctions::positionItemByBounds(container, saveIcon, {680, 0});
}

Header::Header(PokemonStruct &pokemonData, sf::Vector2f position) {

}

void Header::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    container.draw(target, states);
    pokemonName.draw(target, states);
    pokemonNo.draw(target, states);

    backIcon.draw(target, states);

    editIcon.draw(target, states);
    printIcon.draw(target, states);
}

void Header::addEventHandler(sf::RenderWindow &window, sf::Event event) {

    if (MouseEvents<Container>::hovered(backIcon, window)) {
        if (!checkState(HOVERED)) {
            SoundFX::playHoverSound();
            MouseEvents<sf::RectangleShape>::setHand(window);
        }
        enableState(HOVERED);
    } else {
        if (checkState(HOVERED)) {
            MouseEvents<sf::RectangleShape>::setArrow(window);
        }
        disabledState(HOVERED);
    }

    if (MouseEvents<Container>::mouseClicked(backIcon, window)) {
        std::cout << "clicking logo menuItem, going home\n";
        SoundFX::playClickSound();
        MouseEvents<sf::RectangleShape>::setArrow(window);
        ScreenHandler::setCurrentScreen(HOME);
        ScreenHandler::toggleOffPokemonScreenElements();

    }

}

void Header::update() {
    if (ScreenHandler::getCurrScreen() == POKEMON) {
        this->pokemonData = ScreenHandler::getSelectedPokemonData();
        pokemonNo.setString(std::to_string(pokemonData.number));
        pokemonName.setString(pokemonData.name);
    }
}






