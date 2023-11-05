//
// Created by Marthel Rodriguez on 10/28/23.
//

#include "MultiText.h"
#include "../Font/Font.h"

MultiText::MultiText() {
    std::string initString="multi-text initial";
    for (char letter: initString) {
        sf::Text newLetter;
        newLetter.setFont(Font::getFont());
        newLetter.setString(letter);
        newLetter.setCharacterSize(24);
        newLetter.setPosition(50,50);
        multiText.push_back(newLetter);
    }
}

// -
void MultiText::pushNewLetter(sf::Text letter) {

}

// -
void MultiText::calculateTextPosition() {
}

// -
void MultiText::deleteText() {
    multiText.pop_back();
}

sf::Text MultiText::setNewLetter(char newCharacter) {
    sf::Text newLetter;
    newLetter.setFont(Font::getFont());
    newLetter.setString(newCharacter);
    newLetter.setCharacterSize(24);

    if (multiText.empty()) {
        newLetter.setPosition(50,0);
        currentLetterCode = newCharacter;
    }
    else{
        //update the multitext each time.
        prevLetter = multiText.back();
        prevLetterCode = currentLetterCode;
        currentLetterCode = newCharacter;
        prevLetterGlyph = Font::getFont().getGlyph(prevLetterCode,24,"regular");

        sf::Vector2f prevPosition = prevLetter.getPosition();
        newLetter.setPosition(prevPosition.x + prevLetterGlyph.advance,0);
    }
    return (newLetter);
}


/**
 * SFML inherited functions.
 **/
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
        multiText.push_back(setNewLetter(event.text.unicode));
    }


}

void MultiText::update() {

}

void MultiText::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    //adding a cursor to the multiText.

    //
    for(sf::Text letter: multiText) {
        target.draw(letter);
    }

}

