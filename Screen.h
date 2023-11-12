//
// Created by Marthel Rodriguez on 10/12/23.
//

#ifndef SFMLTEMPLATE_SCREEN_H
#define SFMLTEMPLATE_SCREEN_H
#include <SFML/Graphics.hpp>

class Screen : public sf::Drawable {
    //sf::drawable has no idea how to draw a screen.
    //the children must be implemented how to draw in the screen.

    //virtual void ... const = 0; //telling the children that is a must to draw.
    sf::RectangleShape box;
    sf::Text text;
    sf::Font font;
protected:
    Screen();
    Screen(sf::Vector2f dimensions, sf::Font font);
    virtual void draw(sf::RenderStates &window, sf::RenderStates states) const;
};


#endif //SFMLTEMPLATE_SCREEN_H
