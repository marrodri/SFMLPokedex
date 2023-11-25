//
// Created by Marthel Rodriguez on 11/12/23.
//

#ifndef SFMLTEMPLATE_MOUSEEVENTS_CPP
#define SFMLTEMPLATE_MOUSEEVENTS_CPP
#include "MouseEvents.h"

template<typename T> sf::Clock MouseEvents<T>::clock;
template<typename T> sf::Cursor MouseEvents<T>::cursor;
template<typename T>  int MouseEvents<T>::clicks = 0;

/**
 * public methods
 * */
template<typename T>
void MouseEvents<T>::countClicks(sf::Event event) {
    if(event.type == sf::Event::MouseButtonReleased)
    {
        ++clicks;
    }
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
    countClicks(event);
    return event.type == sf::Event::MouseButtonReleased;
}

template<typename T>
bool MouseEvents<T>::hovered(T &object, sf::RenderWindow &window) {
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    return object.getGlobalBounds().contains(mpos);
}

template<typename T>
bool MouseEvents<T>::mouseDoubleClicked() {
    if (clicks >= 1) {
        sf::Time time = clock.getElapsedTime();
        if (time.asSeconds() < 2) {
            if (clicks >= 2) {
                clicks = 0;
                clock.restart();

                return true;
            }
        } else {
            clock.restart();
            clicks = 0;
        }
    }
    return false;
}

template<typename T>
bool MouseEvents<T>::mouseTripleClicked() {
    if(clicks >=1){
        sf::Time time = clock.getElapsedTime();
        if(time.asSeconds() < 3){
            if(clicks >= 3){
                clicks = 0;
                clock.restart();
                return true;
            }
        }
        else{
            clock.restart();
            clicks =0;
        }
    }
    return false;
}

template<typename T>
bool MouseEvents<T>::draggedOver(T &object, sf::RenderWindow &window, sf::Event event) {
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    return (object.getGlobalBounds().contains(mpos) && sf::Mouse::isButtonPressed(sf::Mouse::Left));
}


template<typename T>
void MouseEvents<T>::setHand(sf::RenderWindow &window) {
    if(cursor.loadFromSystem(sf::Cursor::Hand)){
        window.setMouseCursor(cursor);
    }

}

template<typename T>
void MouseEvents<T>::setArrow(sf::RenderWindow &window) {
    if(cursor.loadFromSystem(sf::Cursor::Arrow)){
        window.setMouseCursor(cursor);
    }
}

#endif
