//
// Created by Marthel Rodriguez on 10/12/23.
//

#ifndef SFMLTEMPLATE_COMPONENT_H
#define SFMLTEMPLATE_COMPONENT_H

#include <SFML/Graphics.hpp>

//this is an interface.
class Component : public sf::Drawable {
// before, this class had eventHandler, update and draw. Now, it was separated with the
// goal of making it more modular, so it can be used more globally.

public:
    //polymorphism, I don't know how to handle events, but
    //I NEED MY CHILDREN TO MUST USE eventHandler.
    virtual void eventHandler(sf::RenderWindow &window, sf::Event event) = 0;

    virtual void update() = 0;
    //in your sfml_portfolio you used to pass states to this class.
    //remember why!
};

#endif //SFMLTEMPLATE_COMPONENT_H
