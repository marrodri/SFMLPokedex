//
// Created by Marthel Rodriguez on 11/6/23.
//

#include "Letter.h"


#include <iostream>
Letter::Letter() {
}

Letter::Letter(char characterCode, sf::Font &font, int characterSize, const sf::Color &color) {
    std::cout << "characterSize from Letter: " << characterSize << "\n";
    this->characterCode = characterCode;
    text.setFont(font);
    text.setString(characterCode);
    text.setCharacterSize(characterSize);
    text.setFillColor(color);
    glyphData = font.getGlyph(characterCode, characterSize, "regular");
    text.setPosition(0,0);

}

void Letter::setPosition(float x, float y){
    text.setPosition(x,y);
}

void Letter::setColor(const sf::Color &color) {
    text.setFillColor(color);
}

/**
 * getters
 **/

sf::Vector2f Letter::getPosition() {
    return text.getPosition();
}

sf::Glyph Letter::getGlyph() {
    return glyphData;
}

char Letter::getChar() {
    return characterCode;
}

/**
 * SFML main methods
 **/

void Letter::addEventHandler(sf::RenderWindow &window, sf::Event event) {
}

void Letter::update() {
}

void Letter::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(text);
}
