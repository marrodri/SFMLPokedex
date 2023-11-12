//
// Created by Marthel Rodriguez on 10/28/23.
//

#ifndef SFMLTEMPLATE_MULTITEXT_H
#define SFMLTEMPLATE_MULTITEXT_H

#include <list>
#include "../Components/GUIComponent.h"
#include <iostream>
#include "../Letter/Letter.h"

class MultiText : public GUIComponent {
private:
    sf::Glyph prevLetterGlyph;
    std::list<Letter> multiText;
    Letter prevLetter;
    bool isKeyPressed = false;
    sf::Vector2f initialPosition;
    int characterSize=24;

//  attributes for cursor.
    bool toggleCursor = false;
    sf::Clock clock;
    sf::Text cursor;

    //isOnFocus(bonus), this should be used only in
    //the eventHandler and someparts in update();
    bool isFocussed = true;


    /**
     * private methods.
     **/
    void updateCursorPosition();
    void highlightText();
    bool isKeyword(std::list<Letter>::iterator letter);
    bool stringCompare(const std::string &keyword, std::list<Letter>::iterator letter);
    int getKeywordLen(std::list<Letter>::iterator letter);
public:
    MultiText();
    MultiText(int xPos, int yPos, int sizeFont);
    MultiText(sf::Vector2f position, int sizeFont, sf::Font &font);

    /**
     * methods
     **/
    void deleteText();
    void pushNewLetter(char newCharacter);

    /**
     * Iterators.
     **/
    typedef std::list<Letter>::iterator iterator;
    iterator begin();
    iterator end();

    /**
     * setters
     **/
    void setPosition(sf::Vector2f position);
    void setTextCharacterSize(int textCharacterSize);
    void setFont(sf::Font &font);
    void setOnFocus(bool focus);
//    void setTextTypeColor(Letter &letter);

    /**
     * getters
     **/
     int getFullWidth();
     bool empty();
     Letter &top();

    /**
     * SFML virtual methods
     **/
    void addEventHandler(sf::RenderWindow &window, sf::Event event);

    void update();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif //SFMLTEMPLATE_MULTITEXT_H
