//
// Created by Marthel Rodriguez on 11/30/23.
//

#include "Description.h"
#include "../../../Helper/HelperFunctions.h"
#include "../../../Font/Font.h"

Description::Description(): container({470, 150}, {450, 200}, sf::Color::Blue),
                            placeholder("Description", 25, Font::getFont(), {250, 100}) {
    HelperFunctions::centerItem(container, placeholder);
}

Description::Description(int pokemonNo) {

}

void Description::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(container);
    target.draw(placeholder);
}

void Description::addEventHandler(sf::RenderWindow &window, sf::Event event) {
}

void Description::update() {
}
