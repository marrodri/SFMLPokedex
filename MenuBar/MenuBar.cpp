//
// Created by Marthel Rodriguez on 12/7/23.
//

#include "MenuBar.h"

MenuBar::MenuBar() : menuBarContainer({0, 0}, {1000, 30}, sf::Color(0xc9c9c9ff)) {
    menuBarContainer.setOutlineThickness(0);
    windowMenu = Menu(WINDOW_MENU);
    fileMenu = Menu(FILE_MENU);
    themeMenu = Menu(THEME_MENU);
    menus.pushItemHorizontally(windowMenu);
    menus.pushItemHorizontally(fileMenu);
    menus.pushItemHorizontally(themeMenu);
}

void MenuBar::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(menuBarContainer);
    for (auto menu = menus.begin(); menu != menus.end(); menu++) {
        menu->draw(target, states);
    }
}


void MenuBar::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    ///eventhandler on the items.
    if (MouseEvents<Container>::hovered(menuBarContainer, window)) {
        enableState(HOVERED);

    } else {
        disabledState(HOVERED);
    }
    if (MouseEvents<sf::RectangleShape>::mouseClicked(window, event)) {
        if (MouseEvents<Container>::hovered(menuBarContainer, window)) {
            enableState(CLICKED);
            enableState(FOCUSED);
        } else {
            disabledState(CLICKED);
            disabledState(FOCUSED);
        }
    }
    for (auto menu = menus.begin(); menu != menus.end(); menu++) {
        menu->addEventHandler(window, event);
    }
}

void MenuBar::update() {
    ///update on the items.

    for (auto menu = menus.begin(); menu != menus.end(); menu++) {
        menu->update();
    }


}

/**
 * Container interface
 * */

sf::Vector2f MenuBar::getPosition() {
    return sf::Vector2f();
}

sf::Vector2f MenuBar::getSize() {
    return sf::Vector2f();
}

sf::FloatRect MenuBar::getLocalBounds() const {
    return sf::FloatRect();
}

sf::FloatRect MenuBar::getGlobalBounds() const {
    return sf::FloatRect();
}

void MenuBar::setOrigin(sf::Vector2f &origin) {

}

void MenuBar::setPosition(const sf::Vector2f &pos) {

}

void MenuBar::setFillColor(const sf::Color &color) {

}

void MenuBar::setTexture(const sf::Texture &texture) {

}

void MenuBar::setSize(sf::Vector2f size) {

}

void MenuBar::setOutlineThickness(float outlineThickness) {

}

void MenuBar::setOutlineColor(const sf::Color &color) {

}


