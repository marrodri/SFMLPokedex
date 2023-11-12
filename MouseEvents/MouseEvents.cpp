//
// Created by Marthel Rodriguez on 11/12/23.
//

#ifndef SFMLTEMPLATE_MOUSEEVENTS_CPP
#define SFMLTEMPLATE_MOUSEEVENTS_CPP
#include "MouseEvents.h"

template<typename T> sf::Clock MouseEvents<T>::clock;
template<typename T>  int MouseEvents<T>::clicks;

/**
 * public methods
 * */
template<typename T>
void MouseEvents<T>::countClicks(sf::Event event) {

}

/**
 * private methods
 * */

template<typename T>
bool MouseEvents<T>::mouseClicked(T &object, sf::RenderWindow &window) {
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    return (object.getGlobalBounds().contains(mpos) && sf::Mouse::isButtonPressed(sf::Mouse::Left));

}

template<typename T>
bool MouseEvents<T>::mouseClicked(sf::RenderWindow &window, sf::Event event) {
    return event.type == sf::Event::MouseButtonReleased;
}

template<typename T>
bool MouseEvents<T>::hovered(T &object, sf::RenderWindow &window) {
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    return object.getGlobalBounds().contains(mpos);
}


/**
 * TODO Later
 * */
template<typename T>
bool MouseEvents<T>::mouseDoubleClicked() {
    return false;
}

template<typename T>
bool MouseEvents<T>::mouseTripleClicked() {
    return false;
}

template<typename T>
bool MouseEvents<T>::draggedOver(T &object, sf::RenderWindow &window, sf::Event event) {
    return false;
}


#endif
