//
// Created by Marthel Rodriguez on 11/15/23.
//

#include "Dropdown.h"

void output1(){
    std::cout << "output 1 clicked\n";
}
void output2(){
    std::cout << "output 2 clicked\n";
}
void output3(){
    std::cout << "output 3 clicked\n";
}

Dropdown::Dropdown(){
//    button.setOnClickFunction(&Dropdown::toggleDropdownMenu);
    button.setText("button 1");
    button.setOnClickTemplateFunction(&Dropdown::toggleDropdownMenu, *this);

    itemList.setInitPos(button.getPos());
    itemList.pushItem({"button2",output2});
    itemList.pushItem({"button3",output3});

}

//void Dropdown::toggleDropDownVisibility(){
//    std::cout << "togglingDropDown from parent class\n";
//    isDropdownVisible = !isDropdownVisible;
//}

void Dropdown::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(button);
    if (isDropdownVisible) {
        for (auto itemIterator = itemList.begin();  itemIterator != itemList.end(); ++itemIterator){
            itemIterator->draw(target, states);
        }
    }
}

void Dropdown::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    button.addEventHandler(window,event);
    if (isDropdownVisible) {
        for (auto itemIterator = itemList.begin();  itemIterator != itemList.end(); ++itemIterator){
            itemIterator->addEventHandler(window, event);
        }
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
