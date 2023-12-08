//
// Created by Marthel Rodriguez on 11/14/23.
//


#include "Item.h"

/**
 * constructors
 **/


Item::Item() {
    setFont(Font::getFont(OPEN_SANS));
    textUI.setString("sample Text");
    textUI.setCharacterSize(10);

    dropdownItemContainer.setPosition({200, 200});
    dropdownItemContainer.setSize({100, 30});
    HelperFunctions::centerText(dropdownItemContainer,textUI);
    dropdownItemContainer.setOutlineColor(sf::Color::White);
    dropdownItemContainer.setOutlineThickness(1);
}


/**
 * methods
 **/


//void Item::onClick() {
////    if (pFunc) {
////        pFunc();
////    }
////    else {
////        std::cout << "pOnClick is null; set a function\n";
////    }
//    if (this->pTemplateFunc) {
//        (*objInst.*(pTemplateFunc))();
//    }
//    else {
//        std::cout << "tempPOnClick is not initialized.\n";
//    }
//    if(this->pTemplateFuncWithItem){
//        (*objInst.*(pTemplateFuncWithItem))(*this);
//    }
//    else {
//        std::cout << "tempPOnClickWithItem is not initialized.\n";
//    }
//}

/**
 * setters
 **/

void Item::setPosition(const sf::Vector2f &pos) {
    dropdownItemContainer.setPosition(pos);
    HelperFunctions::centerText(dropdownItemContainer, textUI);
}


void Item::setText(const std::string &text) {
    data = text;
    textUI.setString(text);
    HelperFunctions::centerText(dropdownItemContainer, textUI);
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


/**
 * getters
 * */


sf::Vector2f Item::getPos(){
    return dropdownItemContainer.getPosition();
}


std::string &Item::getData() {
    return data;
}

/**
 * GUIComponent virtual methods
 * */

void Item::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(dropdownItemContainer);
    target.draw(textUI);
}


void Item::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents<Container>::hovered(dropdownItemContainer,window)) {
        std::cout << "hovered :)\n";
        enableState(HOVERED);
        SoundFX::playHoverSound();
    }
    else {
        disabledState(HOVERED);
    }
    if (MouseEvents<Container>::mouseClicked(window, event)) {
        //kinda works, but it still receiving data.
        if (MouseEvents<Container>::hovered(dropdownItemContainer, window)) {
            enableState(CLICKED);
            SoundFX::playClickSound();
//            onClick();
        }
    }
    else{
        disabledState(CLICKED);
    }
}

void Item::update() {
    if (checkState(HOVERED)) {
        dropdownItemContainer.setFillColor(sf::Color::Blue);
    }
    else {
        dropdownItemContainer.setFillColor(sf::Color::Black);
    }
//    if (checkState(CLICKED)) {
//        onClick();
//    }
}



sf::Vector2f Item::getPosition()  {
return dropdownItemContainer.getPosition();
}

sf::Vector2f Item::getSize()  {
return dropdownItemContainer.getSize();
}

sf::FloatRect Item::getLocalBounds() const  {
return dropdownItemContainer.getLocalBounds();
}

sf::FloatRect Item::getGlobalBounds() const  {
return dropdownItemContainer.getGlobalBounds();
}

void Item::setOrigin(sf::Vector2f &origin)  {
dropdownItemContainer.setOrigin(origin);
}

//    void setPosition(const sf::Vector2f &pos) override {
//        dropdownItemContainer.setPosition(pos);
//    }

void Item::setFillColor(const sf::Color &color)  {
dropdownItemContainer.setFillColor(color);
}

void Item::setTexture(const sf::Texture &texture)  {
dropdownItemContainer.setTexture(texture);
}

void Item::setSize(sf::Vector2f size)  {
dropdownItemContainer.setSize(size);
}

void Item::setOutlineThickness(float outlineThickness)  {
dropdownItemContainer.setOutlineThickness(outlineThickness);
}

void Item::setOutlineColor(const sf::Color &color)  {
    dropdownItemContainer.setOutlineColor(color);
}


