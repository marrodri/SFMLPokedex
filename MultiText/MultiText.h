//
// Created by Marthel Rodriguez on 10/28/23.
//

#ifndef SFMLTEMPLATE_MULTITEXT_H
#define SFMLTEMPLATE_MULTITEXT_H


#include <list>
#include <SFML/Graphics.hpp>
#include "../Components/Component.h"
#include <iostream>
class MultiText : public Component {
private:
    sf::Glyph prevLetterGlyph;
    std::list<sf::Text> multiText;
    sf::Text prevLetter;
    char prevLetterCode;
    char currentLetterCode;
    bool isKeyPressed = false;
    int cursorIndex=0;

    /**
     * private methods.
     **/
    void pushNewLetter(sf::Text letter);
    void calculateTextPosition();
    void deleteText();
    //TODO create the function for setting the cursor
    //r
    void setCursorLeft();
    //by default, update the cursor position to right
    //each time that a new letter is added.
    //also use this when the
    void setCursorRight();
    sf::Text setNewLetter(char newCharacter);

public:
    MultiText();


    /**
     * SFML virtual methods
     **/
    // -receive the text and cocatenate the text. Delete the text when pressing
    // the backspace.
    void eventHandler(sf::RenderWindow &window, sf::Event event);

    void update();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};


#endif //SFMLTEMPLATE_MULTITEXT_H
