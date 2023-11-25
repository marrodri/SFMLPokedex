//
// Created by Marthel Rodriguez on 11/23/23.
//

#include "Logo.h"
#include "../../Images/Images.h"

///perfect initializer for the logo container.
Logo::Logo() {
    logoContainer.setSize({230,80});
//    logoContainer.setFillColor(sf::Color::Yellow);
    logoContainer.setOutlineThickness(1);
    logoContainer.setOutlineColor(sf::Color::White);
    logoContainer.setPosition(10,20);
    logoContainer.setTexture(&Images::getImage(LOGO));
    logoContainer.setSize({230,60});

}

void Logo::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(logoContainer);
}

void Logo::addEventHandler(sf::RenderWindow &window, sf::Event event) {
//    GUIComponent::addEventHandler(window, event);
}

void Logo::update() {
//    GUIComponent::update();
}
