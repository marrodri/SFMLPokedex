//
// Created by Marthel Rodriguez on 11/30/23.
//

#include "PokemonWeakness.h"
#include "../../../Font/Font.h"
#include "../../../Helper/HelperFunctions.h"
#include "../../../Images/Images.h"


PokemonWeakness::PokemonWeakness() : container({720, 360}, {200, 80}, sf::Color(0xe67c7cff)),
                                     placeholder("PokemonWeakness", 15, Font::getFont(), {250, 100}),
                                     firstWeakness({100, 100}, {60, 25}, sf::Color::White),
                                     secondWeakness({100, 100}, {60, 25}, sf::Color::White),
                                     thirdWeakness({100, 100}, {60, 25}, sf::Color::White) {
    firstWeakness.setTexture(Images::getPokemonTypeImage(BUG));
    secondWeakness.setTexture(Images::getPokemonTypeImage(DRAGON));
    thirdWeakness.setTexture(Images::getPokemonTypeImage(WATER));
    HelperFunctions::positionItemByBounds(container, placeholder, {80, 10});
    HelperFunctions::centerItemHorizontally(container, firstWeakness, 5);
    HelperFunctions::centerItemHorizontally(container, secondWeakness, 70);
    HelperFunctions::centerItemHorizontally(container, thirdWeakness, 135);

}

PokemonWeakness::PokemonWeakness(int pokemonNo) {

}

void PokemonWeakness::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(container);
    target.draw(placeholder);

    target.draw(firstWeakness);
    target.draw(secondWeakness);
    target.draw(thirdWeakness);
}

void PokemonWeakness::addEventHandler(sf::RenderWindow &window, sf::Event event) {
//    GUIComponent::addEventHandler(window, event);
}

void PokemonWeakness::update() {
//    GUIComponent::update();
}
