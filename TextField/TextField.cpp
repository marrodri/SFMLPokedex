//
// Created by Marthel Rodriguez on 12/2/23.
//

#include "TextField.h"

//pos: 470*150 (try with 490*150, it has to be lower)
//size: 450, 200.
//constructor params 20, Font::getFont(), {250, 300}
TextField::TextField(const std::string &initStr) : container({490, 150}, {450, 200}, sf::Color::Red) {
    /**
     * pass the pos where it shall be initial pos
     **/
}


/**
 * methods
 **/
void TextField::setText(const std::string &str) {
    ///   TODO: call the setText from the MultiText.
    ///         in it, it will check for \n for adding new lines
    ///         and check if the current line has collided for
    ///         adding a new line.
}


/***
 * GUI Methods
 * */

void TextField::draw(sf::RenderTarget &target, sf::RenderStates states) const {
//    GUIComponent::draw(target, states);
    container.draw(target, states);
}


void TextField::addEventHandler(sf::RenderWindow &window, sf::Event event) {

    ///bring the mouseEvents handler
}

void TextField::update() {
//    GUIComponent::update();
}

TextField::TextField() {

}





