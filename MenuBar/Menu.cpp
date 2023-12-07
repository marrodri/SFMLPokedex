//
// Created by Marthel Rodriguez on 12/7/23.
//

#include "Menu.h"

Menu::Menu() {

}

Menu::Menu(menuOptionsEnum optionEnum) {
    switch (optionEnum) {
        case WINDOW_MENU:
            button = MenuItem(Container(WINDOW_OPTION_POS, WINDOW_OPTION_SIZE, sf::Color::White),
                              Text("window", 14, sf::Color::Black, Font::getFont(OPEN_SANS), {0, 0}));
            for (int i = 0; i < 1; i++) {
                MenuItem newOption(
                        Container({WINDOW_OPTION_POS.x, WINDOW_OPTION_POS.y + 30}, {80, 30}, sf::Color::White),
                        Text("exit", 14, sf::Color::Black, Font::getFont(OPEN_SANS), {0, 0}));
                newOption.setOutlineThickness(0.5);
                newOption.setOutlineColor(sf::Color::Black);
                options.pushItemVertically(newOption);
            }

            break;
        case FILE_MENU:
            button = MenuItem(Container({0, 0}, {80, 30}, sf::Color::White),
                              Text("window", 14, sf::Color::Black, Font::getFont(OPEN_SANS), {0, 0}));
            for (int i = 0; i < 1; i++) {
                MenuItem newOption(Container({0, 30}, {80, 30}, sf::Color::White),
                                   Text("exit", 14, sf::Color::Black, Font::getFont(OPEN_SANS), {0, 0}));
                options.pushItemVertically(newOption);
            }
            break;
        case THEME_MENU:
            button = MenuItem(Container({0, 0}, {80, 30}, sf::Color::White),
                              Text("window", 14, sf::Color::Black, Font::getFont(OPEN_SANS), {0, 0}));
            break;
    }
}


void Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(button);
    //if visible.
    for (auto option = options.begin(); option != options.end(); option++) {
        option->draw(target, states);
    }
}

void Menu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    ///onClick for the buttons.
}

void Menu::update() {
    ///update for visibility.
}

sf::Vector2f Menu::getPosition() {
    return button.getPosition();

}

sf::Vector2f Menu::getSize() {
    return button.getSize();

}

sf::FloatRect Menu::getLocalBounds() const {
    return button.getLocalBounds();

}

sf::FloatRect Menu::getGlobalBounds() const {
    return button.getGlobalBounds();

}

void Menu::setOrigin(sf::Vector2f &origin) {
    button.setOrigin(origin);
}

void Menu::setPosition(const sf::Vector2f &pos) {
    button.setPosition(pos);
}

void Menu::setFillColor(const sf::Color &color) {
    button.setFillColor(color);
}

void Menu::setTexture(const sf::Texture &texture) {
    button.setTexture(texture);
}

void Menu::setSize(sf::Vector2f size) {
    button.setSize(size);
}

void Menu::setOutlineThickness(float outlineThickness) {
    button.setOutlineThickness(outlineThickness);
}

void Menu::setOutlineColor(const sf::Color &color) {
    button.setOutlineColor(color);
}


