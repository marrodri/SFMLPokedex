//
// Created by Marthel Rodriguez on 11/11/23.
//

#include "Label.h"

Label::Label() {
    label.setFillColor(sf::Color::White);
}

Label::Label(std::string &labelString, sf::Vector2f position, int fontSize, sf::Font &font) {
    label.setFont(font);
    label.setCharacterSize(fontSize);
    label.setString(labelString);
    label.setFillColor(sf::Color::White);
    label.setPosition(position.x, position.y);
}


/**
 * setters
 * */

void Label::setLabelString(std::string &labelString) {
    this->labelString = labelString;
    label.setString(labelString);
}

void Label::setPosition(sf::Vector2f position) {
    label.setPosition(position.x, position.y);
}

void Label::setFontSize(int fontSize) {
    label.setCharacterSize(fontSize);
}

void Label::setFont(sf::Font &font) {
    label.setFont(font);
}


/**
 * SFML methods
 * */

void Label::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void Label::update() {

}

void Label::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(label);
}
