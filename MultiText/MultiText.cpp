//
// Created by Marthel Rodriguez on 10/28/23.
//

#include "MultiText.h"
#include "../Font/Font.h"


MultiText::MultiText() {
    std::string initString="multi-text initial";
    for (char letter: initString) {
        pushNewLetter(letter);
    }
}

// -
void MultiText::deleteText() {
    multiText.pop_back();
}

void MultiText::pushNewLetter(char newCharacter) {
    Letter newLetter(newCharacter, Font::getFont(), 24);
    if (multiText.empty()) {
        newLetter.setPosition(50,0);
        multiText.push_back(newLetter);
    }
    else{
        //update the multitext each time.
        prevLetter = multiText.back();
        prevLetterGlyph = prevLetter.getGlyph();

        sf::Vector2f prevPosition = prevLetter.getPosition();
        newLetter.setPosition(prevPosition.x + prevLetterGlyph.advance,0);
        multiText.push_back(newLetter);
    }
}

/**
 * SFML inherited functions.
 **/


// -receive the text and cocatenate the text. Delete the text when pressing
// the backspace.
void MultiText::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
            // -pop letter from the multiText.
            deleteText();
        }
    }
    else if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
        if (!isKeyPressed) {
            //clear the muliText list.
            multiText.clear();
            isKeyPressed = true;
        }
        //push new letter to the multiText.
        pushNewLetter(event.text.unicode);
    }
}

void MultiText::update() {

}

void MultiText::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    //adding a cursor to the multiText.
    for(Letter letter: multiText) {
        target.draw(letter);
    }
}

