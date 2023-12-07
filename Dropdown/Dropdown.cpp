//
// Created by Marthel Rodriguez on 11/15/23.
//

#include "Dropdown.h"

//TODO, create the dropdown container.
//DropdownItem()

Dropdown::Dropdown(){
//    menuItem.setOnClickFunction(&Dropdown::toggleDropdownMenu);
//    menuItem.setText("menuItem 1");
//    menuItem.setOnClickTemplateFunction(&Dropdown::toggleDropdownMenu, *this);
//
//    itemList.setInitPos(menuItem.getPos());
//
//    Item<Dropdown> button1;
//    button1.setText("menuItem 1");
//    button1.setOnClickTemplateFunction(&Dropdown::setData, *this);
//    Item<Dropdown> button2;
//    button2.setText("menuItem 2");
//    button2.setOnClickTemplateFunction(&Dropdown::setData, *this);
//
//    Item<Dropdown> button3;
//    button3.setText("menuItem 3");
//    button3.setOnClickTemplateFunction(&Dropdown::setData, *this);
//
//    itemList.pushItem(button1);
//    itemList.pushItem(button2);
//    itemList.pushItem(button3);
}

void Dropdown::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(button);
    if (isDropdownVisible) {
//        for (auto itemIterator = itemList.begin();  itemIterator != itemList.end(); ++itemIterator){
//            itemIterator->draw(target, states);
//        }
    }
}

void Dropdown::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    button.addEventHandler(window,event);
    if (isDropdownVisible) {
//        for (auto itemIterator = itemList.begin();  itemIterator != itemList.end(); ++itemIterator){
//            itemIterator->addEventHandler(window, event);
//        }
    }
}

void Dropdown::update() {
    button.update();
    if (isDropdownVisible) {
        for (auto itemIterator = itemList.begin();  itemIterator != itemList.end(); ++itemIterator){
            itemIterator->update();
        }
    }
}

void Dropdown::toggleDropdownMenu() {
    isDropdownVisible = !isDropdownVisible;

}


void Dropdown::setData(Item<Dropdown> &clickedItem) {
    //when this item is click, pass the data of the item to the header, with the goal of
    // displaying the data at the main menuItem. How?
    //ways to do it: pass the MAIN item that must be updated. and when the item which the
    //user clicks, then pass the data attributes to the MAIN item and update the string,
    //or objects/data of the main item, and update the MAIN item UI. then close the dropdown
    //menu, but this should be a different detail.
    std::cout << "setting data for dropdown menu\n";
    toggleDropdownMenu();
    button.setText(clickedItem.getData());
}
