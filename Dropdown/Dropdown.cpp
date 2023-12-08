//
// Created by Marthel Rodriguez on 11/15/23.
//

#include "Dropdown.h"

//TODO, create the dropdown container.
//DropdownItem()

Dropdown::Dropdown() : dropdownContainer({50, 50}, {200, 200}, sf::Color::White),
                       dropdownLabel("Pokemon Type 1", 24, Font::getFont(PIXEL), {50, 50}) {
    dropdownLabel.setColor(sf::Color::Black);
    Item button1;
    button1.setText("menuItem 1");
    Item button2;
    button2.setText("menuItem 2");
    Item button3;
    button3.setText("menuItem 3");

    ///TODO for tomorrow friday 8:
    ///another button for displaying the selected items.

    ///create a new toggler for the dropdown, renam the item to dropdownItem.
    ///connect the AppHandler dropdown filters to the dropdown class.
    ///whether by passing as a pointer, or connect it with the front end the bakcend class.
    HelperFunctions::positionItemByBounds(dropdownContainer, dropdownLabel, {60, 15});
    HelperFunctions::positionItemByBounds(dropdownContainer, button1, {0, 50});
    itemList.pushItemVertically(button1);
    itemList.pushItemVertically(button2);
    itemList.pushItemVertically(button3);
}

void Dropdown::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    target.draw(dropdownContainer);
    target.draw(dropdownLabel);
    target.draw(selectedFilter);
    if (isDropdownVisible) {
        for (auto itemIterator = itemList.begin(); itemIterator != itemList.end(); ++itemIterator) {
            itemIterator->draw(target, states);
        }
    }
}

void Dropdown::addEventHandler(sf::RenderWindow &window, sf::Event event) {
//    selectedFilter.addEventHandler(window, event);
//    upon clicking the selectedFilter.
    if (isDropdownVisible) {
        for (auto itemIterator = itemList.begin(); itemIterator != itemList.end(); ++itemIterator) {
            itemIterator->addEventHandler(window, event);
        }
    }
}

void Dropdown::update() {
    selectedFilter.update();
    if (isDropdownVisible) {
        for (auto itemIterator = itemList.begin(); itemIterator != itemList.end(); ++itemIterator) {
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


//void Dropdown::setData(Item &clickedItem) {
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
