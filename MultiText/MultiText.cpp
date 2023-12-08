//
// Created by Marthel Rodriguez on 10/28/23.
//

#include "MultiText.h"
#include "../Font/Font.h"


MultiText::MultiText() {


}

MultiText::MultiText(const std::string initStr, sf::Vector2f position, sf::Vector2f bounds,int sizeFont,sf::Font &font) {
    initialPosition = position;
    characterSize = sizeFont;
    this->bounds=bounds;

    cursor.setFont(Font::getFont(OPEN_SANS));
    cursor.setString("|");
    cursor.setCharacterSize(sizeFont);
    cursor.setPosition(position.x, position.y);
    cursor.setFillColor(color);
    this->font = font;
    pushNewLine();
    for (char letter: initStr) {
        pushNewLetter(letter);
    }
}


MultiText::MultiText(sf::Vector2f position, int sizeFont, sf::Font &font) {
    initialPosition = position;
    characterSize = sizeFont;

    cursor.setFont(Font::getFont(OPEN_SANS));

    cursor.setString("|");
    cursor.setCharacterSize(sizeFont);
    cursor.setPosition(position.x, position.y);
    cursor.setFillColor(color);

    std::string initString = "multi-dropdownItemText initial";
    pushNewLine();
//
}

/**
 * iterators
 **/
 ///iterate the currentLine
MultiText::iterator MultiText::begin() {
    return multiTextGrid[lines-1].begin();
}

MultiText::iterator MultiText::end() {
    return multiTextGrid[lines-1].end();
}

/**
 * methods
 * */
void MultiText::deleteText() {
    multiTextGrid[lines - 1].pop_back();
    inputtedString.pop_back();
    if(multiTextGrid[lines - 1].empty() && lines > 1){
        multiTextGrid.pop_back();
        inputtedString.pop_back();
        lines--;
    }
}

void MultiText::pushNewLine() {
    if(!multiTextGrid.empty()){
        inputtedString.push_back('\n');
    }
    multiTextGrid.push_back(std::list<Letter>());
    lines = multiTextGrid.size();
}

void MultiText::pushNewLetter(char newCharacter) {
    if (newCharacter == '\n') {
        pushNewLine();

        return;
    }
    std::cout << "push letter with size of:" << characterSize<<"\n";
    std::cout << "multiText bound x:" << bounds.x<<"\n";
    std::cout << "multiText bound y:" << bounds.y<<"\n";

    Letter newLetter(newCharacter, this->font, characterSize, color);
    inputtedString.push_back(newCharacter);
    ///highlighting different letter.
//    setTextTypeColor(newLetter);

    //pushing new letter at the very beggining of the line.
    if (multiTextGrid[lines - 1].empty()) {
        newLetter.setPosition(initialPosition.x, initialPosition.y + (yPadding*(lines-1)));
        multiTextGrid[lines - 1].push_back(newLetter);
    } else {
        //update the multitext each time.
        prevLetter = multiTextGrid[lines - 1].back();
        prevLetterGlyph = prevLetter.getGlyph();

        sf::Vector2f prevPosition = prevLetter.getPosition();

        newLetter.setPosition(prevPosition.x + prevLetterGlyph.advance, initialPosition.y + (yPadding*(lines-1)));
        multiTextGrid[lines - 1].push_back(newLetter);
    }
    if(getFullWidth() >= bounds.x -10){
        pushNewLine();
    }

}

///update the cursor based on the current line.
void MultiText::updateCursorPosition() {
    if (!multiTextGrid[lines - 1].empty()) {
        cursor.setPosition(multiTextGrid[lines - 1].back().getPosition().x +
                           (multiTextGrid[lines - 1].back().getGlyph().advance - 5), initialPosition.y+ (yPadding*(lines-1)));
    } else {
        cursor.setPosition(initialPosition.x, initialPosition.y+ (yPadding*(lines-1)));
    }
}

///TODO: migrate this to textField Input.
bool MultiText::stringCompare(const std::string &keyword, iterator letter) {
    int length = keyword.size();
    int counter = 0;
    std::cout << "string cmp++++++\n";

    for (auto line: multiTextGrid) {
        for (auto letter = line.begin(); letter != line.end() && letter->getChar() == keyword[counter]
                                         && counter < keyword.size(); letter++) {
            std::cout << "letter: " << letter->getChar() << "\n";
            std::cout << "keyword[counter]: " << keyword[counter] << "\n";
            counter++;
        }
        if (counter == length) {
            std::cout << "returning true stringCmp\n";
            return true;
        }
        std::cout << "returning false stringCmp\n";
        return false;
    }

}

/// TODO: can use this for the search bar, when looking for pokemons.
///        there should be an option to enable search and disable search
///         so it can be used for the textField.
bool MultiText::isKeyword(std::list<Letter>::iterator letter) {
}

/// TODO: delete this later in the future.
int MultiText::getKeywordLen(std::list<Letter>::iterator letter) {

}

///TODO: make this to a change font color.
///     And create another static class that holds
///     the configuration of the whole app for
///     changing its theme.
void MultiText::highlightText() {
    int keywordLen = 0;
    ///TODO: rework this function.
    for (auto letter = multiTextGrid[lines - 1].begin(); letter != multiTextGrid[lines - 1].end();) {
        std::cout << letter->getChar() << "->";
        if (isKeyword(letter)) {
            keywordLen = getKeywordLen(letter);
            if (keywordLen > 0) {
                for (int i = 0; i < (keywordLen - 1); i++) {
                    letter->setColor(sf::Color::Blue);
                    std::cout << letter->getChar() << "";
                    ++letter;
                }
                letter->setColor(sf::Color::Blue);
                ++letter;
            }
        } else if (isalpha(letter->getChar())) {
            letter->setColor(sf::Color::White);
            ++letter;
        } else if (isdigit(letter->getChar())) {
            letter->setColor(sf::Color::Red);
            ++letter;
        } else {
            letter->setColor(sf::Color::Green);
            ++letter;
        }
    }
}

/**
 * getters
 * */
///get the full width of the most recent line.
int MultiText::getFullWidth() {
    int totalTextWidth = 0;
    for (Letter letter: multiTextGrid[lines - 1]) {
        totalTextWidth += letter.getGlyph().advance;
    }
    return totalTextWidth;
}

///check the most recent line is empty.
///TODO
bool MultiText::empty() {
    if(multiTextGrid.empty()){
        return true;
    }
    for(auto lines:multiTextGrid){
        if(lines.empty()){
            return true;
        }
    }
    return false;
//    return multiTextGrid[lines - 1].empty();
}

//bool MultiText::emptyLine(){
//    return multiTextGrid[lines-1].empty();
//}

///get the most recent written character.
Letter &MultiText::top() {
    return multiTextGrid[lines - 1].back();
}

/**
 * setters
 * */

void MultiText::setPosition(sf::Vector2f position) {
    initialPosition = position;
}

void MultiText::setTextCharacterSize(int textCharacterSize) {
    this->characterSize = textCharacterSize;
}

void MultiText::setFont(sf::Font &font) {
}

void MultiText::setOnFocus(bool focus) {
    isFocussed = focus;
}


/**
 * SFML inherited functions.
 **/

void MultiText::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void MultiText::update() {
    sf::Time time = clock.getElapsedTime();
    if (time.asSeconds() >= 1) {
        toggleCursor = !toggleCursor;
        clock.restart();
    }

        updateCursorPosition();


//    highlightText();
}

void MultiText::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    //adding a cursor to the multiText.
    //for(lineOfLetters of Array<List<letters>>){
    //  for(Letter letter: lineOfLetters){
    //      target.draw(letter);
    //  }
    // }
    for (auto line: multiTextGrid) {
        for (Letter letter: line) {
            target.draw(letter);
        }
    }

    if (toggleCursor && isFocussed) {
        target.draw(cursor);
    }
}

void MultiText::setColor(const sf::Color &color) {
    this->color = color;

}

std::string &MultiText::getString() {
    return inputtedString;
}



