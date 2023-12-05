//
// Created by Marthel Rodriguez on 11/30/23.
//

#include "PokemonType.h"
#include "../../../Font/Font.h"
#include "../../../Helper/HelperFunctions.h"
#include "../../../Images/Images.h"
#include "../../ScreenHandler.h"

PokemonType::PokemonType() : container({720, 440}, {200, 80}, sf::Color(0xbfbfbfff)),
                             placeholder("Pokemon Type", 15, Font::getFont(OPEN_SANS), {250, 100}),
                             firstType({100, 100}, {60, 25}, sf::Color::White),
                             secondType({100, 100}, {60, 25}, sf::Color::White),
                             thirdType({100, 100}, {60, 25}, sf::Color::White) {


    firstType.setTexture(Images::getPokemonTypeImage(NORMAL));
    secondType.setTexture(Images::getPokemonTypeImage(POISON));
    thirdType.setTexture(Images::getPokemonTypeImage(ICE));
    HelperFunctions::centerItem(container, placeholder);
    HelperFunctions::positionItemByBounds(container, placeholder, {65, 10});
    HelperFunctions::centerItemHorizontally(container, firstType, 5);
    HelperFunctions::centerItemHorizontally(container, secondType, 70);
    HelperFunctions::centerItemHorizontally(container, thirdType, 135);
}

PokemonType::PokemonType(int pokemonNo) {
}

void PokemonType::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(container);
    target.draw(placeholder);
    target.draw(firstType);
    target.draw(secondType);
//    target.draw(thirdType);
}

void PokemonType::addEventHandler(sf::RenderWindow &window, sf::Event event) {
}

void PokemonType::update() {
    if (!ScreenHandler::getPokemonScreenElementLoaded(POKEMON_TYPES)) {
        pokemonData = ScreenHandler::getSelectedPokemonData();
        firstType.setTexture(Images::getPokemonTypeImage(pokemonData.types[0]));
        secondType.setTexture(Images::getPokemonTypeImage(pokemonData.types[1]));
        thirdType.setTexture(Images::getPokemonTypeImage(pokemonData.types[2]));
        ScreenHandler::setPokemonScreenElementLoaded(POKEMON_TYPES, true);
    }
}
