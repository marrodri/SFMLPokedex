//
// Created by Marthel Rodriguez on 11/29/23.
//

#include "Container.h"
Container::Container(){}
Container::Container(sf::Vector2f pos, sf::Vector2f size, const sf::Color &color) {
    container.setPosition(pos);
    container.setSize(size);
    container.setFillColor(color);
    container.setOutlineThickness(2);
    container.setOutlineColor(sf::Color::White);

    /**
     *
     **/
}

Container::Container(sf::Vector2f pos, sf::Vector2f size, sf::Texture &texture) {

}

sf::Vector2f Container::getPosition() {
    return container.getPosition();
}

sf::Vector2f Container::getSize() {
    return container.getSize();
}

 sf::FloatRect Container::getGlobalBounds() const{
    return container.getGlobalBounds();
}

sf::FloatRect Container::getLocalBounds() const{
    return container.getLocalBounds();
}

void Container::setPosition(const sf::Vector2f &pos) {
    container.setPosition(pos);
}

void Container::setOrigin(sf::Vector2f &origin) {
//    fileItemContainer.setOrigin(origin);
}


/**
 * gui component
 * */

void Container::draw(sf::RenderTarget &target, sf::RenderStates states) const {
//    GUIComponent::draw(target, states);
    target.draw(container);
}

void Container::addEventHandler(sf::RenderWindow &window, sf::Event event) {
//    GUIComponent::addEventHandler(window, event);
}

void Container::update() {
//    GUIComponent::update();
}

void Container::setTexture(const sf::Texture &texture) {
    container.setTexture(&texture);
}

void Container::setFillColor(const sf::Color &color) {
    container.setFillColor(color);
}

void Container::setSize(sf::Vector2f size) {
    container.setSize(size);

}

void Container::setOutlineThickness(float outlineThickness) {
    container.setOutlineThickness(outlineThickness);

}

void Container::setOutlineColor(const sf::Color &color) {
    container.setOutlineColor(color);

}


