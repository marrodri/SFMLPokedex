//
// Created by Marthel Rodriguez on 12/7/23.
//

#include "Menu.h"

void Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    target.draw(button);
    //if visible.
//    for(auto option = options.begin(); option!= options.end(); option++){
//        target.draw(option);
//    }

}

void Menu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    ///onClick for the buttons.
}

void Menu::update() {
    ///update for visibility.
}

sf::Vector2f Menu::getPosition() {
    return button.getPosition();

}

sf::Vector2f Menu::getSize() {
    return button.getSize();

}

sf::FloatRect Menu::getLocalBounds() const {
    return button.getLocalBounds();

}

sf::FloatRect Menu::getGlobalBounds() const {
    return button.getGlobalBounds();

}

void Menu::setOrigin(sf::Vector2f &origin) {
button.setOrigin(origin);
}

void Menu::setPosition(const sf::Vector2f &pos) {
button.setPosition(pos);
}

void Menu::setFillColor(const sf::Color &color) {
button.setFillColor(color);
}

void Menu::setTexture(const sf::Texture &texture) {
button.setTexture(texture);
}

void Menu::setSize(sf::Vector2f size) {
button.setSize(size);
}

void Menu::setOutlineThickness(float outlineThickness) {
button.setOutlineThickness(outlineThickness);
}

void Menu::setOutlineColor(const sf::Color &color) {
button.setOutlineColor(color);
}
