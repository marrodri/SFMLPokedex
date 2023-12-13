//
// Created by Marthel Rodriguez on 11/22/23.
//

#include "GridButton.h"
#include "../SoundFX/SoundFX.h"
#include "../Images/Images.h"
#include "../Screen//ScreenHandler.h"
#include "../Font/Font.h"

GridButton::GridButton() {
}

GridButton::GridButton(sf::Font &font, sf::Vector2f pos, int i) {
    box.setSize({85, 110});
    box.setFillColor(sf::Color::Green);
    box.setOutlineColor(sf::Color::White);
    box.setOutlineThickness(2);

    box.setPosition(pos);

    ///img dropdownItemText, replaced with an animated sprite.
    text.setFont(font);
    text.setCharacterSize(15);
    text.setString("Sprite");


    ///number in top left cornet
    number.setCharacterSize(15);
    number.setString("#1");
    number.setFont(font);

    pokemonName.setCharacterSize(14);
    pokemonName.setString("Charizard");
    pokemonName.setFont(font);

    //dropdownItemText or sprite is centered.
    HelperFunctions::centerText(box, text);
    //
    HelperFunctions::centerTextVertically(box, pokemonName, 80);
    HelperFunctions::positionTextByBounds(box, number, {30, 30});
}

GridButton::GridButton(sf::Font &font, sf::Vector2f pos, PokemonStruct &pokemonData) : sprite3D(
        Images::get3DImage(pokemonData.number), 1, pokemonData.cols) {
    this->pokemonData = pokemonData;
    box.setSize({100, 110});
    box.setTexture(&Images::getImage(BOX));
    box.setFillColor(sf::Color::Blue);
    box.setPosition(pos);

    /**
     * locked components.
     * */
    mask.setPosition(pos);
    mask.setSize({100, 110});
    mask.setTexture(Images::getImage(BOX));
    mask.setFillColor(sf::Color(0x000000af));
    lockedText = Text("Locked", 12, Font::getFont(OPEN_SANS), {100, 100});
    HelperFunctions::centerItem(mask, lockedText);


    ///img dropdownItemText, replaced with an animated sprite.
//    dropdownItemText.setFont(font);
//    dropdownItemText.setCharacterSize(15);
//    dropdownItemText.setString("Sprite");

    ///number in top left cornet
    number.setCharacterSize(15);
    number.setString(std::string(std::to_string(pokemonData.number)));
    number.setFont(font);

    pokemonName.setCharacterSize(14);
    pokemonName.setString(pokemonData.name);
    pokemonName.setFont(font);

    //dropdownItemText or sprite is centered.
//    HelperFunctions::centerItem(box, sprite3D);
    HelperFunctions::centerTextVertically(box, pokemonName, 80);
    HelperFunctions::positionTextByBounds(box, number, {numPos.x, numPos.y});

    sprite3D.setTime(30);
}

/**
 * Getters
 **/
sf::Vector2f GridButton::getPosition() {
    return box.getPosition();
}

sf::Vector2f GridButton::getSize() {
    return box.getSize();
}

void GridButton::setPosition(sf::Vector2f pos) {
    mask.setPosition({pos.x, pos.y});
    box.setPosition(pos);
    HelperFunctions::centerTextVertically(box, pokemonName, 95);
    HelperFunctions::positionTextByBounds(box, number, {numPos.x, numPos.y});
    HelperFunctions::centerItem(mask, lockedText);
    HelperFunctions::centerItem(box, sprite3D);

}

/**
 * GUI Methods
 **/
void GridButton::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    target.draw(box);
    sprite3D.draw(target, states);
    target.draw(number);
    target.draw(pokemonName);
    if (pokemonData.isLocked) {
        target.draw(mask);
        target.draw(lockedText);
    }

}

void GridButton::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    ///
    if (!pokemonData.isLocked) {
        if (MouseEvents<sf::RectangleShape>::hovered(box, window) && !pokemonData.isLocked) {
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
        if (MouseEvents<sf::RectangleShape>::mouseClicked(box, window)) {
            SoundFX::playClickSound();
            MouseEvents<sf::RectangleShape>::setArrow(window);
            onClick();
        }
    }
}

void GridButton::update() {
    ///
    if (!pokemonData.isLocked) {
        if (checkState(HOVERED)) {
            box.setFillColor(sf::Color::Cyan);
        } else {
//        box.setFillColor(sf::Color::Green);
            box.setFillColor(sf::Color::Blue);
        }

    }
    sprite3D.update();
}

//TODO: add the logic that moves from grid view,
// to the main pokemon.
void GridButton::onClick() {
    std::cout << "clicking function\n";
    ScreenHandler::setSelectedPokemonData(pokemonData);
    ScreenHandler::setCurrentScreen(POKEMON_SCREEN);
}

void GridButton::setOnClickFunction() {

}

void GridButton::onHoverSound() {

}

void GridButton::onClickSound() {

}
