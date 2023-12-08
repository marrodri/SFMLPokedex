//
// Created by Marthel Rodriguez on 11/14/23.
//


#include "DropdownItem.h"
#include "../AppHandler.h"

/**
 * constructors
 **/


DropdownItem::DropdownItem() {
    dropdownItemContainer.setPosition({200, 200});
    dropdownItemContainer.setSize({100, 30});

    setFont(Font::getFont(PIXEL));
    dropdownItemText.setString("sample Text");
    dropdownItemText.setCharacterSize(24);
    dropdownItemText.setFillColor(sf::Color::Black);

    HelperFunctions::centerItem(dropdownItemContainer, dropdownItemText);
    dropdownItemContainer.setOutlineColor(sf::Color::Black);
    dropdownItemContainer.setOutlineThickness(2);
}

DropdownItem::DropdownItem(TypesEnum pokemonType) {
    dropdownItemContainer.setPosition({200, 200});
    dropdownItemContainer.setSize({100, 30});

    setFont(Font::getFont(PIXEL));
//    dropdownItemText.setString("sample Text");
    pokemonTypeFilter = pokemonType;
    setText(pokemonType);
    dropdownItemText.setCharacterSize(24);
    dropdownItemText.setFillColor(sf::Color::Black);

    HelperFunctions::centerItem(dropdownItemContainer, dropdownItemText);
    dropdownItemContainer.setOutlineColor(sf::Color::Black);
    dropdownItemContainer.setOutlineThickness(2);
}


/**
 * methods
 **/
void DropdownItem::setPokemonType(TypesEnum pokemonType) {
    pokemonTypeFilter = pokemonType;
}

TypesEnum DropdownItem::getPokemonType() {
    return pokemonTypeFilter;
}

void DropdownItem::setText(TypesEnum pokemonType) {
    switch (pokemonType) {
        case BUG:
            dropdownItemText.setString("BUG");
            break;
        case DRAGON:
            dropdownItemText.setString("DRAGON");
            break;
        case ELECTRIC:
            dropdownItemText.setString("ELECTRIC");
            break;
        case FIGHTING:
            dropdownItemText.setString("FIGHTING");
            break;
        case FIRE:
            dropdownItemText.setString("FIRE");
            break;
        case FLYING:
            dropdownItemText.setString("FLYING");
            break;
        case GHOST:
            dropdownItemText.setString("GHOST");
            break;
        case GRASS:
            dropdownItemText.setString("GRASS");
            break;
        case GROUND:
            dropdownItemText.setString("GROUND");
            break;
        case ICE:
            dropdownItemText.setString("ICE");
            break;
        case NORMAL:
            dropdownItemText.setString("NORMAL");
            break;
        case POISON:
            dropdownItemText.setString("POISON");
            break;
        case PSYCHIC:
            dropdownItemText.setString("PSYCHIC");
            break;
        case ROCK:
            dropdownItemText.setString("ROCK");
            break;
        case WATER:
            dropdownItemText.setString("WATER");
            break;
        case ANOTHERTYPE:
            dropdownItemText.setString("ANOTHERTYPE");
            break;

    }
}

/**
 * setters
 **/

void DropdownItem::setPosition(const sf::Vector2f &pos) {
    dropdownItemContainer.setPosition(pos);
    HelperFunctions::centerItem(dropdownItemContainer, dropdownItemText);
}


void DropdownItem::setText(const std::string &text) {
    data = text;
    dropdownItemText.setString(text);
    HelperFunctions::centerItem(dropdownItemContainer, dropdownItemText);
}


void DropdownItem::setFont(sf::Font &font) {
    dropdownItemText.setFont(font);
}


void DropdownItem::setTextColor(const sf::Color &color) {
    dropdownItemText.setFillColor(color);
}


void DropdownItem::setHoverColor(const sf::Color &color) {
    hoveredColor = color;
}


/**
 * getters
 * */


sf::Vector2f DropdownItem::getPos() {
    return dropdownItemContainer.getPosition();
}


std::string &DropdownItem::getData() {
    return data;
}

/**
 * GUIComponent virtual methods
 * */

void DropdownItem::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(dropdownItemContainer);
    target.draw(dropdownItemText);
}


void DropdownItem::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents<Container>::hovered(dropdownItemContainer, window)) {
        std::cout << "hovered :)\n";
        enableState(HOVERED);
        SoundFX::playHoverSound();
    } else {
        disabledState(HOVERED);
    }
    if (MouseEvents<Container>::mouseClicked(window, event)) {
        //kinda works, but it still receiving data.
        if (MouseEvents<Container>::hovered(dropdownItemContainer, window)) {
            enableState(CLICKED);
            SoundFX::playClickSound();
            onClick();

        }
    } else {
        disabledState(CLICKED);
    }
}

void DropdownItem::update() {
    if (checkState(HOVERED)) {
        dropdownItemContainer.setFillColor(sf::Color::Blue);
        dropdownItemText.setFillColor(sf::Color::White);
    } else {
        dropdownItemContainer.setFillColor(sf::Color::White);
        dropdownItemText.setFillColor(sf::Color::Black);
    }
//    if (checkState(CLICKED)) {
//        onClick();
//    }
}


sf::Vector2f DropdownItem::getPosition() {
    return dropdownItemContainer.getPosition();
}

sf::Vector2f DropdownItem::getSize() {
    return dropdownItemContainer.getSize();
}

sf::FloatRect DropdownItem::getLocalBounds() const {
    return dropdownItemContainer.getLocalBounds();
}

sf::FloatRect DropdownItem::getGlobalBounds() const {
    return dropdownItemContainer.getGlobalBounds();
}

void DropdownItem::setOrigin(sf::Vector2f &origin) {
    dropdownItemContainer.setOrigin(origin);
}

//    void setPosition(const sf::Vector2f &pos) override {
//        dropdownItemContainer.setPosition(pos);
//    }

void DropdownItem::setFillColor(const sf::Color &color) {
    dropdownItemContainer.setFillColor(color);
}

void DropdownItem::setTexture(const sf::Texture &texture) {
    dropdownItemContainer.setTexture(texture);
}

void DropdownItem::setSize(sf::Vector2f size) {
    dropdownItemContainer.setSize(size);
}

void DropdownItem::setOutlineThickness(float outlineThickness) {
    dropdownItemContainer.setOutlineThickness(outlineThickness);
}

void DropdownItem::setOutlineColor(const sf::Color &color) {
    dropdownItemContainer.setOutlineColor(color);
}

void DropdownItem::setOnClickFunct(void (*pFuncType)(TypesEnum)) {
    this->pFuncType =pFuncType;
}

void DropdownItem::onClick() {
    if(pFuncType){
        pFuncType(pokemonTypeFilter);
    }

}








