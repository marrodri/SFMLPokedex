//
// Created by Marthel Rodriguez on 11/21/23.
//

#include "SearchInput.h"

/// TODO: bring the working textInput and modify it with a
///       dropdown that will show the results from its
///       search
SearchInput::SearchInput() {
    textInput.setSize({715,50});
    textInput.setFillColor(sf::Color::White);
    textInput.setOutlineThickness(3);
    textInput.setOutlineColor(sf::Color::Black);
    textInput.setPosition(250,40);
}

std::string &SearchInput::getCurrentInput() {
    //get current input from TextInput
}

void SearchInput::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(textInput);
}

void SearchInput::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void SearchInput::update() {

}


