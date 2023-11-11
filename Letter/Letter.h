//
// Created by Marthel Rodriguez on 11/6/23.
//

#ifndef SFMLTEMPLATE_LETTER_H
#define SFMLTEMPLATE_LETTER_H

#include <SFML/Graphics.hpp>
#include "../Components/Component.h"
class Letter: public Component {
private:
    sf::Glyph glyphData;
    sf::Text text;
    char characterCode;
public:
    Letter();
    Letter(char characterCode, sf::Font &font, int characterSize);

    /**sfml*/
    void eventHandler(sf::RenderWindow &window, sf::Event event);

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
