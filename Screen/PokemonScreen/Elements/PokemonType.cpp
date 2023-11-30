//
// Created by Marthel Rodriguez on 11/30/23.
//

#include "PokemonType.h"
#include "../../../Font/Font.h"
#include "../../../Helper/HelperFunctions.h"

PokemonType::PokemonType() : container({720, 440}, {200, 80}, sf::Color::Cyan),
                             placeholder("Pokemon Type", 15, Font::getFont(), {250, 100}) {

    HelperFunctions::centerItem(container, placeholder);
}

PokemonType::PokemonType(int pokemonNo) {
}

void PokemonType::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(container);
    target.draw(placeholder);
}

void PokemonType::addEventHandler(sf::RenderWindow &window, sf::Event event) {
}

void PokemonType::update() {
}
