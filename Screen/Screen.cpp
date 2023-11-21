//
// Created by Marthel Rodriguez on 10/12/23.
//

#include "Screen.h"


Screen::Screen() {

}


Screen::Screen(sf::Vector2f windowSize) {
    background.setFillColor(sf::Color::Blue);
    background.setSize(windowSize);
    background.setPosition(0,0);
}


Screen::Screen(sf::Vector2f dimensions, sf::Font font) {

}

void Screen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(background);
    ///TODO: Draw the other elements of the front-end.
}

void Screen::addEventHandler(sf::RenderWindow &window, sf::Event event) {
//    GUIComponent::addEventHandler(window, event);
}

void Screen::update() {
//    GUIComponent::update();
}
