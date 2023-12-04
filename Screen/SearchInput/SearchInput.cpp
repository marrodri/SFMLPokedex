//
// Created by Marthel Rodriguez on 11/21/23.
//

#include "SearchInput.h"
#include "../../Font/Font.h"
#include "../../Helper/HelperFunctions.h"

/// TODO: bring the working textInput and modify it with a
///       dropdown that will show the results from it's
///       search

//(sf::Vector2f position, sf::Vector2f size, sf::Font &textInputfont,
// sf::Font &labelFont, std::string label)
SearchInput::SearchInput(): textInput({405, 40},{550, 50},Font::getFont(), Font::getFont(),""),

labelContainer({250,40},{150,50}, sf::Color::White),
label("SEARCH: ",Font::getFont(),32){
    labelContainer.setOutlineColor(sf::Color::Black);
    labelContainer.setOutlineThickness(3);
    label.setFillColor(sf::Color::Black);
    HelperFunctions::centerItem(labelContainer, label);
//    textInput.setSize({715,50});
//    textInput.setFillColor(sf::Color::White);
//    textInput.setOutlineThickness(3);
//    textInput.setOutlineColor(sf::Color::Black);
//    textInput.setPosition(250,40);
}

std::string &SearchInput::getCurrentInput() {
    //get current input from TextInput
}

void SearchInput::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(textInput);
    target.draw(labelContainer);
    target.draw(label);
}

void SearchInput::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    textInput.addEventHandler(window, event);
}

void SearchInput::update() {
    textInput.update();
}


