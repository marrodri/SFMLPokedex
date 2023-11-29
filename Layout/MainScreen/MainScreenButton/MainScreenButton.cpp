//
// Created by Marthel Rodriguez on 11/25/23.
//

#include "MainScreenButton.h"
#include "../../../Font/Font.h"
#include "../../../Helper/HelperFunctions.h"
#include "../../../SoundFX/SoundFX.h"
#include "../../../MouseEvents/MouseEvents.h"

MainScreenButton::MainScreenButton(sf::Vector2f position, std::string text) {

    buttonContainer.setPosition(position);
    this->text.setString(text);
    this->text.setFont(Font::getFont());
    this->text.setCharacterSize(24);
    buttonContainer.setSize({35, 35});
    HelperFunctions::centerText(buttonContainer, this->text);
    buttonContainer.setFillColor(sf::Color::Yellow);

}

void MainScreenButton::onClick() {

}

void MainScreenButton::setOnClickFunction() {

}

void MainScreenButton::onHoverSound() {

}

void MainScreenButton::onClickSound() {

}



void MainScreenButton::draw(sf::RenderTarget &target, sf::RenderStates states) const {
//    GUIComponent::draw(target, states);
    target.draw(buttonContainer);
    target.draw(text);
}

void MainScreenButton::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents<sf::RectangleShape>::hovered(buttonContainer,window)) {
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
    if (MouseEvents<sf::RectangleShape>::mouseClicked(buttonContainer, window)) {
        std::cout << "clicking grid button\n";
        SoundFX::playClickSound();
        MouseEvents<sf::RectangleShape>::setArrow(window);
        onClick();
    }
}

void MainScreenButton::update() {
//    GUIComponent::update();
}
