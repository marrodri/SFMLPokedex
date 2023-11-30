//
// Created by Marthel Rodriguez on 11/30/23.
//

#include "SpriteDisplay.h"
#include "../../../Font/Font.h"
#include "../../../Helper/HelperFunctions.h"

SpriteDisplay::SpriteDisplay(): container({260, 150}, {200, 200}, sf::Color::Blue),
                                placeholder("Sprite Animation", 25, Font::getFont(), {250, 100}){
    HelperFunctions::centerItem(container, placeholder);
}

SpriteDisplay::SpriteDisplay(int pokemonNo) {

}

void SpriteDisplay::draw(sf::RenderTarget &target, sf::RenderStates states) const {
//    GUIComponent::draw(target, states);
container.draw(target, states);
placeholder.draw(target, states);

}

void SpriteDisplay::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void SpriteDisplay::update() {

}


