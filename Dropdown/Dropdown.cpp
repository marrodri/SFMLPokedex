//
// Created by Marthel Rodriguez on 11/15/23.
//

#include "Dropdown.h"
#include "../AppHandler.h"

//TODO, create the dropdown fileItemContainer.
//DropdownItem()

Dropdown::Dropdown() : dropdownContainer({50, 50}, {200, 100}, sf::Color::White),
                       dropdownLabel("Pokemon Type 1", 24, Font::getFont(PIXEL), {50, 50}) {

    dropdownLabel.setColor(sf::Color::Black);
    DropdownItem button1(POISON);

    button1.setOnClickFunct(&AppHandler::setPokemonTypeFilter1);
    DropdownItem button2(PSYCHIC);
    button2.setOnClickFunct(&AppHandler::setPokemonTypeFilter1);
    DropdownItem button3(ELECTRIC);
    button3.setOnClickFunct(&AppHandler::setPokemonTypeFilter1);
    DropdownItem button4(NORMAL);
    button4.setOnClickFunct(&AppHandler::setPokemonTypeFilter1);
    DropdownItem button5(ROCK);
    button5.setOnClickFunct(&AppHandler::setPokemonTypeFilter1);

    ///TODO for tomorrow friday 8:
    ///another button for displaying the selected items.

    ///create a new toggler for the dropdown, renam the item to dropdownItem.
    ///connect the AppHandler dropdown filters to the dropdown class.
    ///whether by passing as a pointer, or connect it with the front end the bakcend class.
    HelperFunctions::positionItemByBounds(dropdownContainer, dropdownLabel, {60, 15});
    HelperFunctions::positionItemByBounds(dropdownContainer, selectedFilter, {0, 50});
    HelperFunctions::positionItemByBounds(dropdownContainer, button1, {0, 80});
    itemList.pushItemHorizontally(button1);
    itemList.pushItemHorizontally(button2);
    itemList.pushItemHorizontally(button3);
    itemList.pushItemHorizontally(button4);
    itemList.pushItemHorizontally(button5);

}

///TODO: work on this one.
//init pos{50, 50}
//strLabel: Pokemon Type 1
Dropdown::Dropdown(const std::string &strLabel, void (*pFuncType)(TypesEnum), sf::Vector2f containerPos)
        : dropdownContainer(containerPos, {200, 75}, sf::Color::White),

          dropdownLabel(strLabel, 24, Font::getFont(PIXEL), containerPos) {


    dropdownContainer.setOutlineThickness(2);
    dropdownContainer.setOutlineColor(sf::Color::Black);
    HelperFunctions::positionItemByBoundsNoOrigin(dropdownContainer, dropdownLabel, {10, 0});
    HelperFunctions::positionItemByBounds(dropdownContainer, selectedFilter, {10, 35});
    for (int i = 0; i < 5; i++) {
        //go through the states map, enable to false.
        DropdownItem newButton(static_cast<TypesEnum>(i));
        newButton.setOnClickFunct(pFuncType);
        HelperFunctions::positionItemByBounds(dropdownContainer, newButton, {10, 65});
        itemList.pushItemVertically(newButton);
    }
    for (int i = 5; i < 10; i++) {
        //go through the states map, enable to false.
        DropdownItem newButton(static_cast<TypesEnum>(i));
        newButton.setOnClickFunct(pFuncType);
        HelperFunctions::positionItemByBounds(dropdownContainer, newButton, {110, 65});
        itemList2.pushItemVertically(newButton);
    }
    dropdownLabel.setColor(sf::Color::Black);
}

void Dropdown::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    target.draw(dropdownContainer);
    target.draw(dropdownLabel);
    //selectedFilter is not initialized.
    target.draw(selectedFilter);
    if (isDropdownVisible) {
        for (auto itemIterator = itemList.begin(); itemIterator != itemList.end(); ++itemIterator) {
            itemIterator->draw(target, states);
        }
        for (auto itemIterator = itemList2.begin(); itemIterator != itemList2.end(); ++itemIterator) {
            itemIterator->draw(target, states);
        }
    }
}

void Dropdown::addEventHandler(sf::RenderWindow &window, sf::Event event) {
//    selectedFilter.addEventHandler(window, event);
//    upon clicking the selectedFilter.
    selectedFilter.addEventHandler(window, event);
    if (selectedFilter.checkState(CLICKED)) {
        toggleDropdownMenu();
        selectedFilter.disabledState(HOVERED);
        selectedFilter.disabledState(CLICKED);
        enableState(FOCUSED);
    } else if (!isDropdownVisible) {
        disabledState(FOCUSED);
    }

    if (isDropdownVisible) {
        for (auto itemIterator = itemList.begin(); itemIterator != itemList.end(); ++itemIterator) {
            itemIterator->addEventHandler(window, event);
            if(itemIterator->checkState(CLICKED)){
                selectedFilter.setText(itemIterator->getData());
                itemIterator->disabledState(CLICKED);
                itemIterator->disabledState(FOCUSED);
                isDropdownVisible=false;
            }
        }
        for (auto itemIterator = itemList2.begin(); itemIterator != itemList2.end(); ++itemIterator) {
            itemIterator->addEventHandler(window, event);
            if(itemIterator->checkState(CLICKED)){
                if(itemIterator->checkState(CLICKED)){
                    selectedFilter.setText(itemIterator->getData());
                    itemIterator->disabledState(CLICKED);
                    itemIterator->disabledState(FOCUSED);
                    isDropdownVisible=false;
                }
            }
        }
    }
}

void Dropdown::update() {
    selectedFilter.update();
    if (isDropdownVisible) {
        for (auto itemIterator = itemList.begin(); itemIterator != itemList.end(); ++itemIterator) {
            itemIterator->update();
        }
        for (auto itemIterator = itemList2.begin(); itemIterator != itemList2.end(); ++itemIterator) {
            itemIterator->update();
        }
    }
}

void Dropdown::toggleDropdownMenu() {
    isDropdownVisible = !isDropdownVisible;

}

sf::Vector2f Dropdown::getPosition() {
    return dropdownContainer.getPosition();
}

sf::Vector2f Dropdown::getSize() {
    return dropdownContainer.getSize();
}

sf::FloatRect Dropdown::getLocalBounds() const {
    return dropdownContainer.getLocalBounds();
}

sf::FloatRect Dropdown::getGlobalBounds() const {
    return dropdownContainer.getGlobalBounds();
}

void Dropdown::setOrigin(sf::Vector2f &origin) {
    dropdownContainer.setOrigin(origin);
}

void Dropdown::setPosition(const sf::Vector2f &pos) {
    dropdownContainer.setPosition(pos);
}

void Dropdown::setFillColor(const sf::Color &color) {
    dropdownContainer.setFillColor(color);
}

void Dropdown::setTexture(const sf::Texture &texture) {
    dropdownContainer.setTexture(texture);
}

void Dropdown::setSize(sf::Vector2f size) {
    dropdownContainer.setSize(size);
}

void Dropdown::setOutlineThickness(float outlineThickness) {
    dropdownContainer.setOutlineThickness(outlineThickness);
}

void Dropdown::setOutlineColor(const sf::Color &color) {
    dropdownContainer.setOutlineColor(color);
}


//void Dropdown::setData(DropdownItem &clickedItem) {
//    //when this item is click, pass the data of the item to the header, with the goal of
//    // displaying the data at the main menuItem. How?
//    //ways to do it: pass the MAIN item that must be updated. and when the item which the
//    //user clicks, then pass the data attributes to the MAIN item and update the string,
//    //or objects/data of the main item, and update the MAIN item UI. then close the dropdown
//    //menu, but this should be a different detail.
//    std::cout << "setting data for dropdown menu\n";
//    toggleDropdownMenu();
//    button.setText(clickedItem.getData());
//}
