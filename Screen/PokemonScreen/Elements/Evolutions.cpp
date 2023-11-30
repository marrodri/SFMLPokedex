//
// Created by Marthel Rodriguez on 11/30/23.
//

#include "Evolutions.h"
#include "../../../Font/Font.h"
#include "../../../Helper/HelperFunctions.h"

Evolutions::Evolutions():
container({260, 360}, {450, 160}, sf::Color::Cyan),
placeholder("Evolutions", 25, Font::getFont(), {250, 100})
{
    HelperFunctions::centerItem(container, placeholder);
}

Evolutions::Evolutions(int pokemonNo) {

}

void Evolutions::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    container.draw(target, states);
    placeholder.draw(target, states);
}

void Evolutions::addEventHandler(sf::RenderWindow &window, sf::Event event) {
}

void Evolutions::update() {
}

