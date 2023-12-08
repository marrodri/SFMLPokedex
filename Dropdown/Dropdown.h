//
// Created by Marthel Rodriguez on 11/15/23.
//

#ifndef SFMLTEMPLATE_DROPDOWN_H
#define SFMLTEMPLATE_DROPDOWN_H

#include "../Item/ItemList.h"
#include "../Components/GUIComponent.h"
#include "DropdownItem.h"
#include "../Text/Text.h"

class Dropdown :public  GUIComponent, public ContainerInterface{
private:
    Item selectedFilter;
    Container dropdownContainer;
    Text dropdownLabel;
//    DropdownItem buttondropDownItem;
//    ItemList<DropdownItem> itemList;
    ItemList<Item> itemList;
    bool isDropdownVisible=true;
    sf::Vector2f initPos;

    Item *selectedItem;
    /// TODO: create a variable to store the item that will be used to draw.
    ///       when clicking the selectedItem, it will show the dropdown menu.
    ///       and when clicking the one of the other items, pass the reference
    ///       of that item to the selectedItem, so it can be drawn.
    ///       -when building the pokedex: with the selectedItem,
    ///         it will call checkType, which it will be used to filter out the
    ///         pokemons from the pokedex.
public:
    Dropdown();

     //**
     // methods
     // */
    void toggleDropdownMenu();


    /**
     * GUIComponent virtual methods
     * */

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;


private:
    sf::Vector2f getPosition() override;

    sf::Vector2f getSize() override;

    sf::FloatRect getLocalBounds() const override;

    sf::FloatRect getGlobalBounds() const override;

    void setOrigin(sf::Vector2f &origin) override;

    void setPosition(const sf::Vector2f &pos) override;

    void setFillColor(const sf::Color &color) override;

    void setTexture(const sf::Texture &texture) override;

    void setSize(sf::Vector2f size) override;

    void setOutlineThickness(float outlineThickness) override;

    void setOutlineColor(const sf::Color &color) override;
};


#endif //SFMLTEMPLATE_DROPDOWN_H
