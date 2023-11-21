//
// Created by Marthel Rodriguez on 11/21/23.
//

#include "SearchInput.h"

SearchInput::SearchInput() {
    textInput.setSize({500,200});
    textInput.setFillColor(sf::Color::Green);
    textInput.setPosition(200,200);
}

std::string &SearchInput::getCurrentInput() {
    //get current input from TextInput
}

void SearchInput::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(textInput);
}

void SearchInput::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    GUIComponent::addEventHandler(window, event);
}

void SearchInput::update() {
    GUIComponent::update();
}


