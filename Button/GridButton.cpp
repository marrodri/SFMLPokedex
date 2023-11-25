//
// Created by Marthel Rodriguez on 11/22/23.
//

#include "GridButton.h"
#include "../SoundFX/SoundFX.h"

GridButton::GridButton() {
}

GridButton::GridButton(sf::Font &font, sf::Vector2f pos, int i) {
    box.setSize({85,110});
    box.setFillColor(sf::Color::Green);
    box.setOutlineColor(sf::Color::White);
    box.setOutlineThickness(2);

    box.setPosition(pos);
    text.setFont(font);
    text.setCharacterSize(15);
    text.setString("Pichu");
    HelperFunctions<sf::RectangleShape>::centerText(box, text);
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
    HelperFunctions<sf::RectangleShape>::centerText(box, text);
}

/**
 * GUI Methods
 **/
void GridButton::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    ///
    target.draw(box);
    target.draw(text);
}

void GridButton::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    ///

    if (MouseEvents<sf::RectangleShape>::hovered(box,window)) {
        if (!checkState(HOVERED)) {
            SoundFX::playHoverSound();
            MouseEvents<sf::RectangleShape>::setHand(window);
        }
        enableState(HOVERED);
    }
    else {
        if(checkState(HOVERED)){
            MouseEvents<sf::RectangleShape>::setArrow(window);
        }
        disabledState(HOVERED);
    }
    if (MouseEvents<sf::RectangleShape>::mouseClicked(box, window)) {
        std::cout << "clicking grid button\n";
        SoundFX::playClickSound();
        MouseEvents<sf::RectangleShape>::setArrow(window);
        onClick();
    }
}

void GridButton::update() {
    ///
    if (checkState(HOVERED)) {
        box.setFillColor(sf::Color::Cyan);
    }
    else {
        box.setFillColor(sf::Color::Green);

    }
}

//TODO: add the logic that moves from grid view,
// to the main pokemon.
void GridButton::onClick() {
    std::cout << "clicking function\n";
}

void GridButton::setOnClickFunction() {

}

void GridButton::onHoverSound() {

}

void GridButton::onClickSound() {

}
