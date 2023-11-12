//
// Created by Marthel Rodriguez on 10/12/23.
//

#ifndef SFMLTEMPLATE_EVENTHANDABLE_H
#define SFMLTEMPLATE_EVENTHANDABLE_H

//activate when an event occurs(like pressing a button, or mouse is clicked a specific area)
#include <SFML/Graphics.hpp>
class EventHandable {
public:
    virtual void eventHandler(sf::RenderWindow &window, sf::Event event) = 0;
};
#endif //SFMLTEMPLATE_EVENTHANDABLE_H
