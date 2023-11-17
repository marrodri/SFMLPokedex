//
// Created by Marthel Rodriguez on 11/14/23.
//

#include "Item.h"

/**
 * constructors
 * */

//void outputClicked(){
//    std::cout <<"clicked :)";
//}

Item::Item() {

    setFont(Font::getFont());
    textUI.setString("sample Text");
    textUI.setCharacterSize(10);

    box.setPosition({200, 200});
    box.setSize({100, 30});
    HelperFunctions<sf::RectangleShape>::centerText(box,textUI);
    box.setOutlineColor(sf::Color::White);
    box.setOutlineThickness(1);
//    pOnClick = outputClicked;
}

/**
 * setters
 **/
void Item::setPosition(sf::Vector2f position) {
    box.setPosition(position);
    HelperFunctions<sf::RectangleShape>::centerText(box, textUI);

}

void Item::setText(std::string text) {
    textUI.setString(text);
    HelperFunctions<sf::RectangleShape>::centerText(box, textUI);
}

void Item::setFont(sf::Font &font) {
    textUI.setFont(font);
}

void Item::setTextColor(const sf::Color &color) {
    textUI.setFillColor(color);
}

void Item::setBorderWidth(int borderWidth) {

}

void Item::setHoverColor(const sf::Color &color) {
    hoveredColor = color;
}

//TODO Later.
void Item::setDropdownShadow() {

}

void Item::setOnClickFunction(void (*pOnClick)()) {
    this->pOnClick = pOnClick;
}


sf::Vector2f Item::getPos(){
    return box.getPosition();
}

/**
 * GUIComponent virtual methods
 * */
void Item::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(box);
    target.draw(textUI);
}

void Item::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<sf::RectangleShape>::hovered(box,window)){
        std::cout << "hovered :)\n";
        enableState(HOVERED);
        SoundFX::playHoverSound();
    }
    else{
        disabledState(HOVERED);
    }
    if(MouseEvents<sf::RectangleShape>::mouseClicked(window, event)){
        //kinda works, but it still receiving data.
        if(MouseEvents<sf::RectangleShape>::hovered(box, window)){
            enableState(CLICKED);
            SoundFX::playClickSound();
        }
    }
    else{
        disabledState(CLICKED);
    }
}

void Item::update() {

    if(checkState(HOVERED)){
        box.setFillColor(sf::Color::Blue);
    }
    else{
        box.setFillColor(sf::Color::Black);
    }
    if(checkState(CLICKED)){
        pOnClick();
    }

}
