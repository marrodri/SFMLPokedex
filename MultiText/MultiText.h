//
// Created by Marthel Rodriguez on 10/28/23.
//

#ifndef SFMLTEMPLATE_MULTITEXT_H
#define SFMLTEMPLATE_MULTITEXT_H

#include <list>
#include <SFML/Graphics.hpp>
#include "../Components/Component.h"
#include <iostream>
#include "../Letter/Letter.h"

class MultiText : public Component {
private:
    sf::Glyph prevLetterGlyph;
    std::list<Letter> multiText;
    Letter prevLetter;
    bool isKeyPressed = false;

    /*
     * Iterators.
     * */

    /**
     * private methods.
     **/
    void deleteText();
    void pushNewLetter(char newCharacter);

public:
    MultiText();

    /**
     * SFML virtual methods
     **/

    void eventHandler(sf::RenderWindow &window, sf::Event event);

    void update();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif //SFMLTEMPLATE_MULTITEXT_H
