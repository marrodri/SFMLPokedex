//
// Created by Marthel Rodriguez on 11/10/23.
//

#include "TextInput.h"

TextInput::TextInput() {

}

TextInput::TextInput(sf::Vector2f position, sf::Vector2f size,
                     sf::Font &textInputfont, sf::Font &labelFont, std::string label):
                     multiText(position, 24, labelFont)
 {
    ///initializing textInputArea.
    textInputArea.setSize(size);
    textInputArea.setPosition(position);
    textInputArea.setFillColor(sf::Color::Black);
    textInputArea.setOutlineColor(sf::Color::White);
     textInputArea.setOutlineThickness(1);

    ///initializing label
    this->label.setLabelString(label);
    this->label.setFont(labelFont);
    this->label.setFontSize(24);
    //find a way to calculate the space between characterSize and position.
    sf::Vector2f labelPos = sf::Vector2f ({position.x, position.y - (size.y / 2) - 24});
    this->label.setPosition(labelPos);


    ///initialize multiText
    multiText.setPosition(position);
    multiText.setFont(textInputfont);
    multiText.setTextCharacterSize(24);
}



bool TextInput::isTextColiding() {
    return (multiText.getFullWidth() >= (textInputArea.getSize().x -10));
}

/**
 * SFML methods
 * */

void TextInput::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z)
        && !Undo::empty()){
            Action prevAction =Undo::undoAction();
            switch(prevAction.action){
                case WRITE:
                    multiText.pushNewLetter(prevAction.letter);
                    break;
                case DELETE:
                    multiText.deleteText();
                    break;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && !multiText.empty()) {
            Undo::pushNewAction(multiText.top().getChar(),WRITE, TEXTINPUT);
            multiText.deleteText();
        }
    } else if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)
               && !isTextColiding()) {
        multiText.pushNewLetter(event.text.unicode);
        Undo::pushNewAction('\0', DELETE, TEXTINPUT);
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
