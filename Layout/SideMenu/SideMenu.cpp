//
// Created by Marthel Rodriguez on 11/21/23.
//

#include "SideMenu.h"



SideMenu::SideMenu() {

    sideMenuContainer.setSize({230,445});
    sideMenuContainer.setFillColor(sf::Color::Red);
    sideMenuContainer.setOutlineThickness(1);
    sideMenuContainer.setOutlineColor(sf::Color::White);
    sideMenuContainer.setPosition(10,100);

}

void SideMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sideMenuContainer);
}

void SideMenu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
//    GUIComponent::addEventHandler(window, event);
}

void SideMenu::update() {
//    GUIComponent::update();
}
