//
// Created by Marthel Rodriguez on 12/7/23.
//

#include "Menu.h"

Menu::Menu() {

}

Menu::Menu(menuOptionsEnum optionEnum) {
    switch (optionEnum) {
        case WINDOW_MENU:
            menuItem = MenuItem(Container(WINDOW_OPTION_POS, WINDOW_OPTION_SIZE, sf::Color::White),
                                Text("window", 14, sf::Color::Black, Font::getFont(OPEN_SANS), {0, 0}));
            menuItem.setOutlineThickness(0.5);
            menuItem.setOutlineColor(sf::Color::Black);
            for (int i = 0; i < 1; i++) {
                MenuItem newOption(
                        Container({WINDOW_OPTION_POS.x, WINDOW_OPTION_POS.y + 30}, {80, 30}, sf::Color::White),
                        Text("exit", 14, sf::Color::Black, Font::getFont(OPEN_SANS), {0, 0}));
                newOption.setOutlineThickness(0.5);
                newOption.setOutlineColor(sf::Color::Black);
                menuOptions.pushItemVertically(newOption);
            }
            break;
        case FILE_MENU:
            menuItem = MenuItem(Container({FILE_MENU_POS.x, FILE_MENU_POS.y}, {80, 30}, sf::Color::White),
                                Text("File", 14, sf::Color::Black, Font::getFont(OPEN_SANS), {0, 0}));
            menuItem.setOutlineThickness(0.5);
            menuItem.setOutlineColor(sf::Color::Black);
            for (int i = 0; i < 1; i++) {
                MenuItem newOption(Container({FILE_MENU_POS.x, 30}, {80, 30}, sf::Color::White),
                                   Text("open", 14, sf::Color::Black, Font::getFont(OPEN_SANS), {0, 0}));
                newOption.setOutlineThickness(0.5);
                newOption.setOutlineColor(sf::Color::Black);
                menuOptions.pushItemVertically(newOption);
            }
            break;
        case THEME_MENU:
            menuItem = MenuItem(Container({THEME_MENU_POS.x, THEME_MENU_POS.y}, {160, 30}, sf::Color::White),
                                Text("Theme", 14, sf::Color::Black, Font::getFont(OPEN_SANS), {0, 0}));
            menuItem.setOutlineThickness(0.9);
            menuItem.setOutlineColor(sf::Color::Black);
            for (int i = 0; i < 3; i++) {
                MenuItem newOption;
                switch (i) {
                    case 0:
                        newOption = MenuItem(Container({THEME_MENU_POS.x, 30}, {160, 30}, sf::Color::White),
                                             Text("Change Background", 14, sf::Color::Black, Font::getFont(OPEN_SANS),
                                                  {0, 0}));
                        break;
                    case 1:
                        newOption = MenuItem(Container({THEME_MENU_POS.x, 30}, {160, 30}, sf::Color::White),
                                             Text("Change Font Color", 14, sf::Color::Black, Font::getFont(OPEN_SANS),
                                                  {0, 0}));
                        break;
                    case 2:
                        newOption = MenuItem(Container({THEME_MENU_POS.x, 30}, {160, 30}, sf::Color::White),
                                             Text("Change Font Family", 14, sf::Color::Black, Font::getFont(OPEN_SANS),
                                                  {0, 0}));
                        break;
                }
                newOption.setOutlineThickness(0.5);
                newOption.setOutlineColor(sf::Color::Black);
                menuOptions.pushItemVertically(newOption);
            }
            break;
    }
}


void Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(menuItem);
    //if visible.
    if (menuItem.checkState(FOCUSED)) {
        for (auto menuOption = menuOptions.begin(); menuOption != menuOptions.end(); menuOption++) {
            menuOption->draw(target, states);
        }
    }
}

void Menu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    ///onClick for the buttons.
    menuItem.addEventHandler(window, event);
//    menuItem.checkState(FOCUSED)
    if (menuItem.checkState(FOCUSED)) {
        for (auto menuOption = menuOptions.begin(); menuOption != menuOptions.end(); menuOption++) {
            menuOption->addEventHandler(window, event);
        }
    }

}

void Menu::update() {
    ///update for visibility.
    menuItem.update();
    if (menuItem.checkState(FOCUSED)) {
        for (auto menuOption = menuOptions.begin(); menuOption != menuOptions.end(); menuOption++) {
            menuOption->update();
        }
    }
}

sf::Vector2f Menu::getPosition() {
    return menuItem.getPosition();

}

sf::Vector2f Menu::getSize() {
    return menuItem.getSize();

}

sf::FloatRect Menu::getLocalBounds() const {
    return menuItem.getLocalBounds();

}

sf::FloatRect Menu::getGlobalBounds() const {
    return menuItem.getGlobalBounds();

}

void Menu::setOrigin(sf::Vector2f &origin) {
    menuItem.setOrigin(origin);
}

void Menu::setPosition(const sf::Vector2f &pos) {
    menuItem.setPosition(pos);
}

void Menu::setFillColor(const sf::Color &color) {
    menuItem.setFillColor(color);
}

void Menu::setTexture(const sf::Texture &texture) {
    menuItem.setTexture(texture);
}

void Menu::setSize(sf::Vector2f size) {
    menuItem.setSize(size);
}

void Menu::setOutlineThickness(float outlineThickness) {
    menuItem.setOutlineThickness(outlineThickness);
}

void Menu::setOutlineColor(const sf::Color &color) {
    menuItem.setOutlineColor(color);
}


