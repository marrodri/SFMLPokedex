//
// Created by Marthel Rodriguez on 11/29/23.
//

#include "Text.h"

Text::Text() {

}

Text::Text(const std::string &str, int fontSize, sf::Font &font, sf::Vector2f pos) {

    text.setString(str);
    text.setCharacterSize(fontSize);
    text.setPosition(pos);
    text.setFont(font);
    text.setFillColor(sf::Color::White);
}

Text::Text(const std::string &str, int fontSize, const sf::Color &color, sf::Font &font, sf::Vector2f pos) {

    text.setString(str);
    text.setCharacterSize(fontSize);
    text.setPosition(pos);
    text.setFont(font);
    text.setFillColor(color);
}


void Text::setFont(sf::Font &font) {
    text.setFont(font);
}

sf::FloatRect Text::getLocalBounds() const {
    return text.getLocalBounds();
}

sf::FloatRect Text::getGlobalBounds() const {
    return text.getGlobalBounds();
}

sf::Vector2f Text::getPosition() {
    return text.getPosition();
}

void Text::setOrigin(sf::Vector2f &origin) {
    text.setOrigin(origin);
}

void Text::setString(const std::string &str) {
    text.setString(str);
}

void Text::setColor(const sf::Color &color) {
    text.setFillColor(color);
}

/**
 * GUI component
 * */
void Text::draw(sf::RenderTarget &target, sf::RenderStates states) const {
//    GUIComponent::draw(target, states);
    target.draw(text);
}

void Text::addEventHandler(sf::RenderWindow &window, sf::Event event) {
//    GUIComponent::addEventHandler(window, event);
}

void Text::update() {
//    GUIComponent::update();
}

void Text::setPosition(const sf::Vector2f &pos) {
    text.setPosition(pos);
}


const std::string &Text::getString() {
    return text.getString();
}
