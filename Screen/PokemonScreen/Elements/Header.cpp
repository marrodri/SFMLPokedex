//
// Created by Marthel Rodriguez on 11/29/23.
//

#include "Header.h"
#include "../../../Font/Font.h"
#include "../../../Helper/HelperFunctions.h"
#include "../../../Images/Images.h"

Header::Header() : container({250, 100}, {90 * 8, 40}, sf::Color::Magenta),
                   pokemonName("Pokemon Name", 25, Font::getFont(), {250, 100}),
                   pokemonNo("001:", 25, Font::getFont(), {300, 100}),
                   backIcon({180, 100}, {40, 40}, sf::Color::Red),
                   editIcon({180, 100}, {40, 40}, sf::Color::Yellow),
                   printIcon({180, 100}, {40, 40}, sf::Color::White),
                   saveIcon({180, 100}, {40, 40}, sf::Color::Cyan){
    backIcon.setTexture(Images::getImage(BOX));
    HelperFunctions::centerItemHorizontally(container, pokemonName, 200);
    HelperFunctions::centerItemHorizontally(container, pokemonNo, 70);
    HelperFunctions::positionItemByBounds(container, backIcon, {0, 0});


    HelperFunctions::positionItemByBounds(container, editIcon, {580, 0});
    HelperFunctions::positionItemByBounds(container, printIcon, {630, 0});
    HelperFunctions::positionItemByBounds(container, saveIcon, {680, 0});
}

Header::Header(PokemonStruct &pokemonData, sf::Vector2f position) {

}

void Header::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    container.draw(target, states);
    pokemonName.draw(target, states);
    pokemonNo.draw(target, states);

    backIcon.draw(target, states);

     editIcon.draw(target,states);
     printIcon.draw(target,states);
     //TODO: move this to the edit screen.
//    saveIcon.draw(target,states);
}

void Header::addEventHandler(sf::RenderWindow &window, sf::Event event) {
//    GUIComponent::addEventHandler(window, event);
}

void Header::update() {
//    GUIComponent::update();
}




