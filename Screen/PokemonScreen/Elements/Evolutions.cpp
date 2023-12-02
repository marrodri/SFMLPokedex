//
// Created by Marthel Rodriguez on 11/30/23.
//

#include "Evolutions.h"
#include "../../../Font/Font.h"
#include "../../../Helper/HelperFunctions.h"
#include "../../../Images/Images.h"

Evolutions::Evolutions() :
        container({260, 360}, {450, 160}, sf::Color::Cyan),
        placeholder("Evolutions", 25, Font::getFont(), {250, 100}) {
    HelperFunctions::centerItem(container, placeholder);
}

//TODO: reupdate this firstEval.
Evolutions::Evolutions(const std::array<int, 3> &evolutions, int cols) :
        container({260, 360}, {450, 160}, sf::Color::Cyan), firstEvol(Images::get3DImage(evolutions[0]), 1, cols),
        secEvol(Images::get3DImage(evolutions[0]), 1, cols),
        finalEvol(Images::get3DImage(evolutions[0]), 1, cols) {
    firstEvol.setTime(50);
    secEvol.setTime(50);
    finalEvol.setTime(50);
    HelperFunctions::centerItemHorizontally(container, firstEvol, 50);
    HelperFunctions::centerItem(container, secEvol);
    HelperFunctions::centerItemHorizontally(container, finalEvol, 380);

}

void Evolutions::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    container.draw(target, states);
    placeholder.draw(target, states);
    firstEvol.draw(target, states);
    secEvol.draw(target, states);
    finalEvol.draw(target, states);
}

void Evolutions::addEventHandler(sf::RenderWindow &window, sf::Event event) {
}

void Evolutions::update() {
    firstEvol.update();
    secEvol.update();
    finalEvol.update();
}



