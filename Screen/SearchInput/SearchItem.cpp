//
// Created by Marthel Rodriguez on 12/5/23.
//

#include "SearchItem.h"
#include "../../MouseEvents/MouseEvents.h"
#include "../../Helper/HelperFunctions.h"
#include "../ScreenHandler.h"

SearchItem::SearchItem(Container &container, Text text, PokemonStruct &pokemonData) {
    this->container = container;
    this->text = text;
    this->pokemonData = pokemonData;
    HelperFunctions::centerItemHorizontally(container, text, 30);
}


void SearchItem::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(container);
    target.draw(text);
}

void SearchItem::addEventHandler(sf::RenderWindow &window, sf::Event event) {
//    GUIComponent::addEventHandler(window, event);

    if (MouseEvents<Container>::hovered(container, window)) {
        States::enableState(HOVERED);

    } else { States::disabledState(HOVERED); }
    if (MouseEvents<Container>::mouseClicked(container, window)) {
        std::cout << "searchItemClicked\n";
        std::cout << "clicking function\n";
        ScreenHandler::setSelectedPokemonData(pokemonData);
        ScreenHandler::setCurrentScreen(POKEMON);
    }
}

void SearchItem::update() {

    if (States::checkState(HOVERED)) {
        container.setFillColor(sf::Color(0xdbdbd9ff));
    } else {
        container.setFillColor(sf::Color::White);
    }
}

/**
 * container interface methods
 * */

sf::Vector2f SearchItem::getPosition() {
    return container.getPosition();
}

sf::Vector2f SearchItem::getSize() {
    return container.getSize();
}

sf::FloatRect SearchItem::getLocalBounds() const {
    return container.getLocalBounds();
}

sf::FloatRect SearchItem::getGlobalBounds() const {
    return container.getGlobalBounds();
}

void SearchItem::setOrigin(sf::Vector2f &origin) {
    return container.setOrigin(origin);
}

void SearchItem::setPosition(const sf::Vector2f &pos) {
    this->container.setPosition(pos);
    HelperFunctions::centerItemHorizontally(container, text, 150);

}

void SearchItem::setFillColor(const sf::Color &color) {
    container.setFillColor(color);
}

void SearchItem::setTexture(const sf::Texture &texture) {
    container.setTexture(texture);
}

void SearchItem::setSize(sf::Vector2f size) {
    container.setSize(size);
}

void SearchItem::setOutlineThickness(float outlineThickness) {
    container.setOutlineThickness(outlineThickness);
}

void SearchItem::setOutlineColor(const sf::Color &color) {
    container.setOutlineColor(color);
}
