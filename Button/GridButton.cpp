//
// Created by Marthel Rodriguez on 11/22/23.
//

#include "GridButton.h"
#include "../SoundFX/SoundFX.h"
#include "../Images/Images.h"
#include "../Screen//ScreenHandler.h"

GridButton::GridButton() {
}

GridButton::GridButton(sf::Font &font, sf::Vector2f pos, int i) {
    box.setSize({85, 110});
    box.setFillColor(sf::Color::Green);
    box.setOutlineColor(sf::Color::White);
    box.setOutlineThickness(2);

    box.setPosition(pos);

    ///img text, replaced with an animated sprite.
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

    //text or sprite is centered.
    HelperFunctions::centerText(box, text);
    //
    HelperFunctions::centerTextVertically(box, pokemonName, 80);
    HelperFunctions::positionTextByBounds(box, number, {30,30});
}

GridButton::GridButton(sf::Font &font, sf::Vector2f pos, PokemonStruct &pokemonData):sprite3D(Images::get3DImage(pokemonData.number),1, pokemonData.cols) {
    this->pokemonData = pokemonData;
    box.setSize({100, 110});
    box.setTexture(&Images::getImage(BOX));
    box.setFillColor(sf::Color::Blue);
//    box.setOutlineColor(sf::Color::White);
//    box.setOutlineThickness(2);
    box.setPosition(pos);

    ///img text, replaced with an animated sprite.
//    text.setFont(font);
//    text.setCharacterSize(15);
//    text.setString("Sprite");

    ///number in top left cornet
    number.setCharacterSize(15);
    number.setString(std::string(std::to_string(pokemonData.number)));
    number.setFont(font);

    pokemonName.setCharacterSize(14);
    pokemonName.setString(pokemonData.name);
    pokemonName.setFont(font);

    //text or sprite is centered.
//    HelperFunctions::centerItem(box, sprite3D);
    HelperFunctions::centerTextVertically(box, pokemonName, 80);
    HelperFunctions::positionTextByBounds(box, number, {numPos.x,numPos.y});


    sprite3D.setTime(40);
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
    box.setPosition(pos);
    HelperFunctions::centerTextVertically(box, pokemonName, 95);
//    HelperFunctions::positionTextByBounds(box, number, {12, 12});
    HelperFunctions::positionTextByBounds(box, number, {numPos.x,numPos.y});
//    HelperFunctions::centerText(box, text);
    HelperFunctions::centerItem(box, sprite3D);
}

/**
 * GUI Methods
 **/
void GridButton::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    ///
    target.draw(box);
//    target.draw(text);
    sprite3D.draw(target,states);
    target.draw(number);
    target.draw(pokemonName);

}

void GridButton::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    ///
    if (MouseEvents<sf::RectangleShape>::hovered(box, window)) {
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

void GridButton::update() {
    ///
    if (checkState(HOVERED)) {
        box.setFillColor(sf::Color::Cyan);
    } else {
//        box.setFillColor(sf::Color::Green);
        box.setFillColor(sf::Color::Blue);
    }
    sprite3D.update();
}

//TODO: add the logic that moves from grid view,
// to the main pokemon.
void GridButton::onClick() {
    std::cout << "clicking function\n";
    ScreenHandler::setSelectedPokemonData(pokemonData);
    ScreenHandler::setCurrentScreen(POKEMON);
}

void GridButton::setOnClickFunction() {

}

void GridButton::onHoverSound() {

}

void GridButton::onClickSound() {

}
