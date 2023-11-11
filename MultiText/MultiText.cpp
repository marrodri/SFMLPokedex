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

MultiText::MultiText(sf::Vector2f position, int sizeFont, sf::Font &font){

    initialPosition = position;
    characterSize = sizeFont;

    cursor.setFont(font);
    cursor.setString("|");
    cursor.setCharacterSize(sizeFont);
    cursor.setPosition(position.x, position.y);

    std::string initString="multi-text initial";
//
}

/**
 * iterators
 **/
 MultiText::iterator MultiText::begin() {
     return multiText.begin();
 }

MultiText::iterator MultiText::end() {
    return multiText.end();
}

/**
 * methods
 * */
void MultiText::deleteText() {
    multiText.pop_back();
}

void MultiText::pushNewLetter(char newCharacter) {
    Letter newLetter(newCharacter, Font::getFont(), characterSize);
    if (multiText.empty()) {
        newLetter.setPosition(initialPosition.x, initialPosition.y);
        multiText.push_back(newLetter);

    }
    else{
        //update the multitext each time.
        prevLetter = multiText.back();
        prevLetterGlyph = prevLetter.getGlyph();

        sf::Vector2f prevPosition = prevLetter.getPosition();
        newLetter.setPosition(prevPosition.x + prevLetterGlyph.advance,initialPosition.y);
        multiText.push_back(newLetter);
    }

}


void MultiText::updateCursorPosition() {
    if(!multiText.empty()){
        cursor.setPosition(multiText.back().getPosition().x +(multiText.back().getGlyph().advance-5), initialPosition.y);
    }
    else{
        cursor.setPosition(initialPosition.x, initialPosition.y);
    }
}

/**
 * getters
 * */
int MultiText::getFullWidth() {
    int totalTextWidth = 0;
    for(Letter letter: multiText){
        totalTextWidth += letter.getGlyph().advance;
    }
    return totalTextWidth;
}

bool MultiText::empty() {
    return multiText.empty();
}

Letter &MultiText::top() {
    return multiText.back();
}

/**
 * setters
 * */

void MultiText::setPosition(sf::Vector2f position) {
    initialPosition = position;
}

void MultiText::setTextCharacterSize(int textCharacterSize) {
    this->characterSize=textCharacterSize;
}

void MultiText::setFont(sf::Font &font) {
    //font.
}

void MultiText::setTextColor(sf::Color &color) {
    //color.
}

/**
 * SFML inherited functions.
 **/

void MultiText::eventHandler(sf::RenderWindow &window, sf::Event event) {
}

void MultiText::update() {
    sf::Time time = clock.getElapsedTime();
    if(time.asSeconds() >= 1){
        toggleCursor = !toggleCursor;
        clock.restart();
    }
    updateCursorPosition();
}

void MultiText::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    //adding a cursor to the multiText.
    for(Letter letter: multiText) {
        target.draw(letter);
    }
    if(toggleCursor){
        target.draw(cursor);
    }
}

