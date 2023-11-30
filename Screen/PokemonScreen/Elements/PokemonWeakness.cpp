//
// Created by Marthel Rodriguez on 11/30/23.
//

#include "PokemonWeakness.h"
#include "../../../Font/Font.h"
#include "../../../Helper/HelperFunctions.h"


PokemonWeakness::PokemonWeakness(): container({720, 360}, {200, 80}, sf::Color::Red),
                                    placeholder("PokemonWeakness", 15, Font::getFont(), {250, 100}) {
    HelperFunctions::centerItem(container, placeholder);
}

PokemonWeakness::PokemonWeakness(int pokemonNo) {

}

void PokemonWeakness::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(container);
    target.draw(placeholder);
}

void PokemonWeakness::addEventHandler(sf::RenderWindow &window, sf::Event event) {
//    GUIComponent::addEventHandler(window, event);
}

void PokemonWeakness::update() {
//    GUIComponent::update();
}
