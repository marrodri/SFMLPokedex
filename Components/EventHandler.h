//
// Created by Marthel Rodriguez on 10/12/23.
//

#ifndef SFMLTEMPLATE_EVENTHANDLER_H
#define SFMLTEMPLATE_EVENTHANDLER_H

//activate when an event occurs(like pressing a button, or mouse is clicked a specific area)
#include <SFML/Graphics.hpp>
class EventHandler {
public:
    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event) = 0;
    virtual void update() = 0;
};
#endif //SFMLTEMPLATE_EVENTHANDLER_H
