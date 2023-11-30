//
// Created by Marthel Rodriguez on 11/21/23.
//

#include "PokemonScreen.h"
#include "../../Helper/HelperFunctions.h"
#include "../../Font/Font.h"

//container(sf::Vector2f pos, sf::Vector2f size, sf::Color &color)
//title(const std::string &str, int fontSize, sf::Vector2f pos, sf::Font &font);
PokemonScreen::PokemonScreen() {
    container.setSize({90*8, 4*110});
    container.setPosition({250, 100});
    container.setFillColor(sf::Color::Blue);
    title.setFont(Font::getFont());
    title.setString("Pokemon Screen");
    title.setCharacterSize(24);
    HelperFunctions::centerItem(container, title);
}

void PokemonScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(container);
    target.draw(title);
}

void PokemonScreen::addEventHandler(sf::RenderWindow &window, sf::Event event) {
//    GUIComponent::addEventHandler(window, event);
}

void PokemonScreen::update() {
//    GUIComponent::update();
}
