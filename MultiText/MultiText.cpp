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
    //highlighting different letter.
//    setTextTypeColor(newLetter);

    //pushing new letter
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


bool MultiText::stringCompare(const std::string &keyword, iterator letter){
    int length = keyword.size();
    int counter =0;
    std::cout << "string cmp++++++\n";
    for(auto letter=multiText.begin(); letter != multiText.end() && letter->getChar() == keyword[counter]
    &&  counter < keyword.size(); letter++){
        std::cout <<"letter: "<< letter->getChar() <<"\n";
        std::cout <<"keyword[counter]: "<< keyword[counter]<<"\n";
        counter++;
    }
    if(counter == length){
        std::cout << "returning true stringCmp\n";
        return true;
    }
    std::cout << "returning false stringCmp\n";
    return false;
}

//return the size of the keyword, otherwise
bool MultiText::isKeyword(std::list<Letter>::iterator letter){
    if(letter->getChar() == 'i' || letter->getChar() == 'c' || letter->getChar() == 'd' || letter->getChar() == 'f'){
//        return true;
        if(stringCompare("int", letter)){
            return true;
        }
        if(stringCompare("char", letter)){
            return true;
        }
        if(stringCompare("double", letter)){
            return true;
        }
        if(stringCompare("float", letter)){
            return true;
        }
    }

    return false;
}

int MultiText::getKeywordLen(std::list<Letter>::iterator letter){
    if(stringCompare("int", letter)){
        return 3;
    }
    if(stringCompare("char", letter)){
        return 4;
    }
    if(stringCompare("double", letter)){
        return 6;
    }
    if(stringCompare("float", letter)){
        return 5;
    }
    return 0;
}


void MultiText::highlightText() {
    int keywordLen =0;
    for(auto letter=multiText.begin(); letter != multiText.end(); )
    {
        std::cout << letter->getChar()<<"->";
        if (isKeyword(letter)){
            keywordLen = getKeywordLen(letter);
            if(keywordLen >0){
                for(int i=0; i < (keywordLen - 1); i++){
                    letter->setColor(sf::Color::Blue);
                    std::cout << letter->getChar() <<"";
                    ++letter;
                }
                letter->setColor(sf::Color::Blue);
                ++letter;
            }
        }
        else if(isalpha(letter->getChar())){
            letter->setColor(sf::Color::White);
            ++letter;
        }
        else if(isdigit(letter->getChar())){
            letter->setColor(sf::Color::Red);
            ++letter;
        }
        else{
            letter->setColor(sf::Color::Green);
            ++letter;
        }
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
}

void MultiText::setOnFocus(bool focus) {
    isFocussed= focus;
}




/**
 * SFML inherited functions.
 **/

void MultiText::addEventHandler(sf::RenderWindow &window, sf::Event event) {
}

void MultiText::update() {
    sf::Time time = clock.getElapsedTime();
    if(time.asSeconds() >= 1){
        toggleCursor = !toggleCursor;
        clock.restart();
    }
    updateCursorPosition();
    highlightText();
}

void MultiText::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    //adding a cursor to the multiText.
    for(Letter letter: multiText) {
        target.draw(letter);
    }
    if(toggleCursor && isFocussed){
        target.draw(cursor);
    }
}

