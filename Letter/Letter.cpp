//
// Created by Marthel Rodriguez on 11/6/23.
//

#include "Letter.h"


Letter::Letter() {
}

Letter::Letter(char characterCode, sf::Font &font, int characterSize) {
    characterCode = characterCode;
    text.setFont(font);
    text.setString(characterCode);
    text.setCharacterSize(characterSize);
    glyphData = font.getGlyph(characterCode, characterSize, "regular");
    text.setPosition(0,0);
}

void Letter::setPosition(float x, float y){
    text.setPosition(x,y);
}

/**
 * getters
 * */

sf::Vector2f Letter::getPosition() {
    return text.getPosition();
}

sf::Glyph Letter::getGlyph() {
    return glyphData;
}

/**
 * SFML main methods
 * */

void Letter::eventHandler(sf::RenderWindow &window, sf::Event event) {
}

void Letter::update() {
}

void Letter::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(text);
}
