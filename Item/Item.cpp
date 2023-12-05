//
// Created by Marthel Rodriguez on 11/14/23.
//

#ifndef SFMLTEMPLATE_ITEM_CPP
#define SFMLTEMPLATE_ITEM_CPP
#include "Item.h"

/**
 * constructors
 **/

template<typename T>
Item<T>::Item() {
    setFont(Font::getFont(OPEN_SANS));
    textUI.setString("sample Text");
    textUI.setCharacterSize(10);

    box.setPosition({200, 200});
    box.setSize({100, 30});
    HelperFunctions::centerText(box,textUI);
    box.setOutlineColor(sf::Color::White);
    box.setOutlineThickness(1);
}


/**
 * methods
 **/

template<typename T>
void Item<T>::onClick() {
//    if (pFunc) {
//        pFunc();
//    }
//    else {
//        std::cout << "pOnClick is null; set a function\n";
//    }
    if (this->pTemplateFunc) {
        (*objInst.*(pTemplateFunc))();
    }
    else {
        std::cout << "tempPOnClick is not initialized.\n";
    }
    if(this->pTemplateFuncWithItem){
        (*objInst.*(pTemplateFuncWithItem))(*this);
    }
    else {
        std::cout << "tempPOnClickWithItem is not initialized.\n";
    }
}

/**
 * setters
 **/
template<typename T>
void Item<T>::setPosition(sf::Vector2f position) {
    box.setPosition(position);
    HelperFunctions::centerText(box, textUI);

}

template<typename T>
void Item<T>::setText(const std::string &text) {
    data = text;
    textUI.setString(text);
    HelperFunctions::centerText(box, textUI);
}

template<typename T>
void Item<T>::setFont(sf::Font &font) {
    textUI.setFont(font);
}

template<typename T>
void Item<T>::setTextColor(const sf::Color &color) {
    textUI.setFillColor(color);
}

template<typename T>
void Item<T>::setBorderWidth(int borderWidth) {

}

template<typename T>
void Item<T>::setHoverColor(const sf::Color &color) {
    hoveredColor = color;
}

//TODO Later.
template<typename T>
void Item<T>::setDropdownShadow() {

}

///TODO: function setters with template
template<typename T>
void Item<T>::setOnClickTemplateFunction(void (T::*pTemplateFunc)(), T &objInst){
    this->objInst = &objInst;
    this->pTemplateFunc = pTemplateFunc;
}

template<typename T>
void Item<T>::setOnClickTemplateFunction(void (T::*pTemplateFuncWithItem)(Item<T> &item), T &objInst) {
    this->pTemplateFuncWithItem = pTemplateFuncWithItem;
    this->objInst = &objInst;
}

template<typename T>
void Item<T>::setOnClickFunction(void (*pOnClick)()) {
    this->pFunc = pOnClick;
}

/**
 * getters
 * */

template<typename T>
sf::Vector2f Item<T>::getPos(){
    return box.getPosition();
}

template<typename T>
std::string &Item<T>::getData() {
    return data;
}

/**
 * GUIComponent virtual methods
 * */
template<typename T>
void Item<T>::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(box);
    target.draw(textUI);
}

template<typename T>
void Item<T>::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<sf::RectangleShape>::hovered(box,window)){
        std::cout << "hovered :)\n";
        enableState(HOVERED);
        SoundFX::playHoverSound();
    }
    else{
        disabledState(HOVERED);
    }
    if (MouseEvents<sf::RectangleShape>::mouseClicked(window, event)) {
        //kinda works, but it still receiving data.
        if (MouseEvents<sf::RectangleShape>::hovered(box, window)) {
            enableState(CLICKED);
            SoundFX::playClickSound();
            onClick();
        }
    }
    else{
        disabledState(CLICKED);
    }
}
template<typename T>
void Item<T>::update() {
    if (checkState(HOVERED)) {
        box.setFillColor(sf::Color::Blue);
    }
    else {
        box.setFillColor(sf::Color::Black);
    }
//    if (checkState(CLICKED)) {
//        onClick();
//    }
}


#endif
