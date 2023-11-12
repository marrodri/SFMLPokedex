//
// Created by Marthel Rodriguez on 11/12/23.
//

#ifndef SFMLTEMPLATE_MOUSEEVENTS_H
#define SFMLTEMPLATE_MOUSEEVENTS_H

#include <SFML/Graphics.hpp>
#include <iostream>
template <typename T>
class MouseEvents {
private:
    // this is what I used to determine if a double click or triple click occurred
    static sf::Clock clock;
    static int clicks;
    static void countClicks(sf::Event event);
public:
    // returns true if the mouse clicks on the object
    static bool mouseClicked(T& object, sf::RenderWindow& window);

    // returns true if the mouse clicks anywhere in the window
    static bool mouseClicked(sf::RenderWindow& window, sf::Event event);

    // returns true if the mouse has been double clicked
    static bool mouseDoubleClicked();

    //returns true if the mouse has been triple clicked
    static bool mouseTripleClicked();

    // returns if the object has been clicked and the mouse has dragged over the object
    static bool draggedOver(T& object, sf::RenderWindow& window, sf::Event event);

    // returns tru if the mouse is hovered over the object
    static bool hovered(T& object, sf::RenderWindow& window);
};
#include "MouseEvents.cpp"

#endif //SFMLTEMPLATE_MOUSEEVENTS_H
