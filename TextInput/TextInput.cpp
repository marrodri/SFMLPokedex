//
// Created by Marthel Rodriguez on 11/10/23.
//

#include "TextInput.h"

TextInput::TextInput() {

}

TextInput::TextInput(sf::Vector2f position, sf::Vector2f size,
                     sf::Font &textInputfont, sf::Font &labelFont, std::string label) {
    //initializing textInputArea.
    textInputArea.setSize(size);
    textInputArea.setPosition(position);
    textInputArea.setFillColor(sf::Color::Green);

    //initializing label
    this->label.setString(label);
    this->label.setFont(labelFont);
    this->label.setCharacterSize(24);
    //find a way to calculate the space between characterSize and position.
    this->label.setPosition(position.x, position.y - (size.y/2)- 24);





}


void TextInput::eventHandler(sf::RenderWindow &window, sf::Event event) {

}

void TextInput::update() {
    multiText.update();
}

void TextInput::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    //test this
    target.draw(textInputArea);
    target.draw(label);
    //
//    target.draw(multiText);
}
