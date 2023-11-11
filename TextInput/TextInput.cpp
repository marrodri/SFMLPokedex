//
// Created by Marthel Rodriguez on 11/10/23.
//

#include "TextInput.h"

TextInput::TextInput() {

}

TextInput::TextInput(sf::Vector2f position, sf::Vector2f size,
                     sf::Font &textInputfont, sf::Font &labelFont, std::string label): multiText(position, 24, labelFont)
 {
    ///initializing textInputArea.
    textInputArea.setSize(size);
    textInputArea.setPosition(position);
    textInputArea.setFillColor(sf::Color::Green);

    ///initializing label
    this->label.setString(label);
    this->label.setFont(labelFont);
    this->label.setCharacterSize(24);
    //find a way to calculate the space between characterSize and position.
    this->label.setPosition(position.x, position.y - (size.y/2)- 24);


    ///initialize multiText
    multiText.setPosition(position);
    multiText.setFont(textInputfont);
    multiText.setTextCharacterSize(24);

    ///initialize previousActions(TOMORROW)
}

void TextInput::undoAction() {


}


bool TextInput::isTextColiding() {
    return (multiText.getFullWidth() >= textInputArea.getSize().y);
}

/**
 * SFML methods
 * */

void TextInput::eventHandler(sf::RenderWindow &window, sf::Event event) {
    //collision detection. when the length of the text goes to the border
    //of the textInputField, stop writing.
    if(!isTextColiding()){
        multiText.eventHandler(window, event);
    }

}

void TextInput::update() {
    multiText.update();
}

void TextInput::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(textInputArea);
    target.draw(label);
    target.draw(multiText);
}
