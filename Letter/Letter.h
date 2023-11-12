//
// Created by Marthel Rodriguez on 11/6/23.
//

#ifndef SFMLTEMPLATE_LETTER_H
#define SFMLTEMPLATE_LETTER_H

#include "../Components/GUIComponent.h"

class Letter : public GUIComponent {
private:
    sf::Glyph glyphData;
    sf::Text text;
    char characterCode;
public:
    Letter();
    Letter(char characterCode, sf::Font &font, int characterSize);

    /**sfml*/
    void addEventHandler(sf::RenderWindow &window, sf::Event event);

    void update();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void setPosition(float x, float y);
    void setColor(const sf::Color &color);

    /**
     * getters
     * */
    sf::Glyph getGlyph();
    sf::Vector2f getPosition();
    char getChar();

};


#endif //SFMLTEMPLATE_LETTER_H
