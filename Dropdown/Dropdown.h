//
// Created by Marthel Rodriguez on 11/15/23.
//

#ifndef SFMLTEMPLATE_DROPDOWN_H
#define SFMLTEMPLATE_DROPDOWN_H

#include "../Item/ItemList.h"
#include "../Components/GUIComponent.h"

class Dropdown :public  GUIComponent{
private:
    Item button;
    ItemList itemList;
    bool isDropdownVisible=true;

    void toggleDropDownVisibility();
public:
    Dropdown();

    /**
     *
     **/
     void setButton(std::string text, void (*pFunct)());
     void setItemList(std::vector<ItemStruct> listOfItemStructs);


    /*
     * GUIComponent virtual methods
     * */

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;
};


#endif //SFMLTEMPLATE_DROPDOWN_H
