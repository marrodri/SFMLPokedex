//
// Created by Marthel Rodriguez on 11/25/23.
//

#include "MainScreenButton.h"
#include "../../Font/Font.h"
#include "../../Helper/HelperFunctions.h"
#include "../../SoundFX/SoundFX.h"
#include "../../MouseEvents/MouseEvents.h"
#include "../../Images/Images.h"
#include "../ScreenHandler.h"

MainScreenButton::MainScreenButton(sf::Vector2f position, std::string text) {

    buttonContainer.setPosition(position);
    buttonContainer.setTexture(&Images::getImage(BUTTON));
    this->text.setString(text);
    this->text.setFont(Font::getFont(OPEN_SANS));
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
    if (MouseEvents<sf::RectangleShape>::hovered(buttonContainer, window)) {
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
    if (MouseEvents<sf::RectangleShape>::mouseClicked(buttonContainer, window)) {
        std::cout << "clicking grid menuItem\n";
        SoundFX::playClickSound();
        MouseEvents<sf::RectangleShape>::setArrow(window);
        onClick();
        ScreenHandler::setCurrentScreen(HOME_SCREEN);
    }
}

void MainScreenButton::update() {
//    GUIComponent::update();
}

sf::Vector2f MainScreenButton::getPosition() {
    return buttonContainer.getPosition();
}

sf::Vector2f MainScreenButton::getSize() {
    return buttonContainer.getSize();
}

sf::FloatRect MainScreenButton::getLocalBounds() const {
    return buttonContainer.getLocalBounds();
}

sf::FloatRect MainScreenButton::getGlobalBounds() const {
    return buttonContainer.getGlobalBounds();
}

void MainScreenButton::setOrigin(sf::Vector2f &origin) {
    buttonContainer.setOrigin(origin);
}

void MainScreenButton::setPosition(const sf::Vector2f &pos) {
    buttonContainer.setPosition(pos);
}

void MainScreenButton::setFillColor(const sf::Color &color) {
    buttonContainer.setFillColor(color);
}

void MainScreenButton::setTexture(const sf::Texture &texture) {
    buttonContainer.setTexture(&texture);
}

void MainScreenButton::setSize(sf::Vector2f size) {
    buttonContainer.setSize(size);
}

void MainScreenButton::setOutlineThickness(float outlineThickness) {
    buttonContainer.setOutlineThickness(outlineThickness);
}

void MainScreenButton::setOutlineColor(const sf::Color &color) {
    buttonContainer.setOutlineColor(color);
}
