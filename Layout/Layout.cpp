//
// Created by Marthel Rodriguez on 10/12/23.
//

#include "Layout.h"


Layout::Layout() {

}


Layout::Layout(sf::Vector2f windowSize) {
    background.setFillColor(sf::Color::Blue);
    background.setSize(windowSize);
    background.setPosition(0,0);
}


Layout::Layout(sf::Vector2f dimensions, sf::Font font) {

}

void Layout::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(background);
    ///TODO: Draw the other elements of the front-end.
}

void Layout::addEventHandler(sf::RenderWindow &window, sf::Event event) {
//    GUIComponent::addEventHandler(window, event);
}

void Layout::update() {
//    GUIComponent::update();
}
