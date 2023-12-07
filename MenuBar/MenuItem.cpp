//
// Created by Marthel Rodriguez on 12/7/23.
//

#include "MenuItem.h"
#include "../Helper/HelperFunctions.h"

MenuItem::MenuItem() {

}

MenuItem::MenuItem(Container container, Text text) : menuContainer(container), menuText(text) {
    HelperFunctions::centerItem(menuContainer, menuText);
    menuContainer.setOutlineThickness(0);
}


void MenuItem::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(menuContainer);
    target.draw(menuText);
}

void MenuItem::addEventHandler(sf::RenderWindow &window, sf::Event event) {
//    GUIComponent::addEventHandler(window, event);
}

void MenuItem::update() {
//    GUIComponent::update();
}

sf::Vector2f MenuItem::getPosition() {
    return menuContainer.getPosition();
}

sf::Vector2f MenuItem::getSize() {
    return menuContainer.getSize();
}

sf::FloatRect MenuItem::getLocalBounds() const {
    return menuContainer.getLocalBounds();
}

sf::FloatRect MenuItem::getGlobalBounds() const {
    return menuContainer.getGlobalBounds();
}

void MenuItem::setOrigin(sf::Vector2f &origin) {
    menuContainer.setOrigin(origin);
}

void MenuItem::setPosition(const sf::Vector2f &pos) {
    menuContainer.setPosition(pos);
}

void MenuItem::setFillColor(const sf::Color &color) {
    menuContainer.setFillColor(color);
}

void MenuItem::setTexture(const sf::Texture &texture) {
    menuContainer.setTexture(texture);
}

void MenuItem::setSize(sf::Vector2f size) {
    menuContainer.setSize(size);
}

void MenuItem::setOutlineThickness(float outlineThickness) {
    menuContainer.setOutlineThickness(outlineThickness);
}

void MenuItem::setOutlineColor(const sf::Color &color) {
    menuContainer.setOutlineColor(color);
}

