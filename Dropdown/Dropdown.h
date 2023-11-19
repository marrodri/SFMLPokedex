//
// Created by Marthel Rodriguez on 11/15/23.
//

#ifndef SFMLTEMPLATE_DROPDOWN_H
#define SFMLTEMPLATE_DROPDOWN_H

#include "../Item/ItemList.h"
#include "../Components/GUIComponent.h"

class Dropdown :public  GUIComponent{
private:
    Item<Dropdown> button;
    ItemList<Dropdown> itemList;
    bool isDropdownVisible=true;
    sf::Vector2f initPos;

    Item<Dropdown> *selectedItem;
    /// TODO: create a variable to store the item that will be used to draw.
    ///       when clicking the selectedItem, it will show the dropdown menu.
    ///       and when clicking the one of the other items, pass the reference
    ///       of that item to the selectedItem, so it can be drawn.
    ///       -when building the pokedex: with the selectedItem,
    ///         it will call checkType, which it will be used to filter out the
    ///         pokemons from the pokedex.
public:
    Dropdown();

    /**
     *
     **/
     void setButton(std::string text, void (*pFunct)());
     void setItemList(std::vector<ItemStruct> listOfItemStructs);

    void toggleDropdownMenu();

    /*
     * GUIComponent virtual methods
     * */

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;
};


#endif //SFMLTEMPLATE_DROPDOWN_H
