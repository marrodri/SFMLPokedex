//
// Created by Marthel Rodriguez on 12/7/23.
//

#include "MenuItem.h"
#include "../Helper/HelperFunctions.h"
#include "../MouseEvents/MouseEvents.h"

MenuItem::MenuItem() {

}

MenuItem::MenuItem(Container container, Text text) : menuItemContainer(container), MenuItemText(text) {
    HelperFunctions::centerItem(menuItemContainer, MenuItemText);
    menuItemContainer.setOutlineThickness(0);
}

/**
 * MenuItem.
 * */

void MenuItem::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(menuItemContainer);
    target.draw(MenuItemText);
}

void MenuItem::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents<Container>::hovered(menuItemContainer, window)) {
        enableState(HOVERED);
    } else {
        disabledState(HOVERED);
    }
    if (MouseEvents<sf::RectangleShape>::mouseClicked(window, event)) {
        if (MouseEvents<Container>::hovered(menuItemContainer, window)) {
            enableState(CLICKED);
            enableState(FOCUSED);
        } else {
            disabledState(CLICKED);
            disabledState(FOCUSED);
        }
    }
}

void MenuItem::update() {
    if (checkState(HOVERED) && !checkState(CLICKED)) {
        //add a lower grey color when being hovered.
        menuItemContainer.setFillColor(sf::Color::Blue);
        MenuItemText.setColor(sf::Color::White);
    } else {
        menuItemContainer.setFillColor(sf::Color::White);
        MenuItemText.setColor(sf::Color::Black);
    }
}


/**
 * container interface
 * */
sf::Vector2f MenuItem::getPosition() {
    return menuItemContainer.getPosition();
}

sf::Vector2f MenuItem::getSize() {
    return menuItemContainer.getSize();
}

sf::FloatRect MenuItem::getLocalBounds() const {
    return menuItemContainer.getLocalBounds();
}

sf::FloatRect MenuItem::getGlobalBounds() const {
    return menuItemContainer.getGlobalBounds();
}

void MenuItem::setOrigin(sf::Vector2f &origin) {
    menuItemContainer.setOrigin(origin);
}

void MenuItem::setPosition(const sf::Vector2f &pos) {
    menuItemContainer.setPosition(pos);
    HelperFunctions::centerItem(menuItemContainer, MenuItemText);
}

void MenuItem::setFillColor(const sf::Color &color) {
    menuItemContainer.setFillColor(color);
}

void MenuItem::setTexture(const sf::Texture &texture) {
    menuItemContainer.setTexture(texture);
}

void MenuItem::setSize(sf::Vector2f size) {
    menuItemContainer.setSize(size);
}

void MenuItem::setOutlineThickness(float outlineThickness) {
    menuItemContainer.setOutlineThickness(outlineThickness);
}

void MenuItem::setOutlineColor(const sf::Color &color) {
    menuItemContainer.setOutlineColor(color);
}

