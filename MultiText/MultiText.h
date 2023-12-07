//
// Created by Marthel Rodriguez on 10/28/23.
//

#ifndef SFMLTEMPLATE_MULTITEXT_H
#define SFMLTEMPLATE_MULTITEXT_H

#include <list>
#include "../Components/GUIComponent.h"
#include <iostream>
#include "../Letter/Letter.h"

#include <array>
class MultiText : public GUIComponent {
private:
    sf::Glyph prevLetterGlyph;
    std::vector<std::list<Letter>> multiTextGrid;
    int lines = 0;
    Letter prevLetter;
    bool isKeyPressed = false;
    sf::Vector2f initialPosition;
    int characterSize=64;
    sf::Vector2f bounds;
    sf::Color color;
    sf::Font font;
    std::string inputtedString;
//  attributes for cursor.
    bool toggleCursor = false;
    sf::Clock clock;
    sf::Text cursor;
    float yPadding = 13;

    //isOnFocus(bonus), this should be used only in
    //the eventHandler and someparts in update();
    bool isFocussed = true;



    /**
     * private methods.
     **/
    void updateCursorPosition();
    void highlightText();
    bool isKeyword(std::list<Letter>::iterator letter);
    ///These are needed for the search, migrate them to the
    ///searchInput class. Here its not required.
    bool stringCompare(const std::string &keyword, std::list<Letter>::iterator letter);
    int getKeywordLen(std::list<Letter>::iterator letter);
public:
    MultiText();

    MultiText(int xPos, int yPos, int sizeFont);
    MultiText(sf::Vector2f position, int sizeFont, sf::Font &font);
    MultiText(const std::string initStr, sf::Vector2f position, sf::Vector2f bounds,int sizeFont,sf::Font &font);

    /**
     * methods
     **/
    void deleteText();
    //  TODO: push new letter to the lattest array item.
    //however, if the char is a '\n', call pushNewLine().
    void pushNewLetter(char newCharacter);
    //  TODO: push a new array that will form a new linebreak.
    void pushNewLine();
    //  TODO: delete the most recent line. like a stack.
    //        a line is push
    void deleteLine();
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
    void setColor(const sf::Color &color);
    //TODO: migrate this to the textField.
    void setOnFocus(bool focus);
//    void setTextTypeColor(Letter &letter);

    /**
     * getters
     **/
     int getFullWidth();
     //this is needed for the search text input.
     std::string &getString();
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
