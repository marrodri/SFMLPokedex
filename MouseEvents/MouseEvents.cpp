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
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        clicks++;
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


/**
 * TODO Later
 * */
template<typename T>
bool MouseEvents<T>::mouseDoubleClicked() {
    if(clicks >=1){
        sf::Time time = clock.getElapsedTime();
        if(time.asMilliseconds() < 1000000){
            if(clicks <= 2){
                clicks=0;
                clock.restart();
                std::cout << "triple click running\n";
                return true;
            }
        }
        else{
            clock.restart();
            clicks =0;
        }
    }
    return false;

template<typename T>
bool MouseEvents<T>::mouseTripleClicked() {
    if(clicks >=1){
        sf::Time time = clock.getElapsedTime();
        if(time.asMilliseconds() < 1000000){
            if(clicks <= 3){
                clicks=0;
                clock.restart();
                std::cout << "triple click running\n";
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
    return false;
}

#endif
