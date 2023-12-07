//
// Created by Marthel Rodriguez on 11/30/23.
//

#include "SpriteDisplay.h"
#include "../../../Font/Font.h"
#include "../../../Helper/HelperFunctions.h"
#include "../../../Images/Images.h"
#include "../../ScreenHandler.h"

SpriteDisplay::SpriteDisplay() : container({260, 150}, {200, 200}, sf::Color::Blue),
                                 placeholder("Sprite Animation", 25, Font::getFont(OPEN_SANS), {250, 100}) {

    HelperFunctions::centerItem(container, placeholder);
}

SpriteDisplay::SpriteDisplay(int pokemonNo, int cols) : container({260, 150}, {200, 200}, sf::Color::Blue),
                                                        sprite3D(Images::get3DImage(pokemonNo), 1, cols) {
    sprite3D.setTime(20);
    HelperFunctions::centerItem(container, sprite3D);
}

void SpriteDisplay::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    container.draw(target, states);
    sprite3D.draw(target, states);
}

void SpriteDisplay::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void SpriteDisplay::update() {
    if (!ScreenHandler::getPokemonScreenElementLoaded(SPRITE_DISPLAY)) {
        pokemonData = ScreenHandler::getSelectedPokemonData();
//        sprite3D.setTexture(Images::get3DImage(pokemonData.number));
        sprite3D = AnimatedSprite(Images::get3DImage(pokemonData.number), 1, pokemonData.cols);
        sprite3D.setTime(20);
        HelperFunctions::centerItem(container, sprite3D);
        ScreenHandler::setPokemonScreenElementLoaded(SPRITE_DISPLAY, true);
    }
    if (ScreenHandler::getPokemonScreenElementLoaded(SPRITE_DISPLAY)) {
        sprite3D.update();
    }
}




