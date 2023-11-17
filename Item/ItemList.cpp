//
// Created by Marthel Rodriguez on 11/14/23.
//

#include "ItemList.h"


ItemList::ItemList() {

}

ItemList::ItemList(std::vector<ItemStruct> initlist) {

}

/**
 * methods
 * */

void ItemList::pushItem(ItemStruct newItemData) {
    Item newItem;
    newItem.setOnClickFunction(newItemData.functPtr);
    newItem.setFont(Font::getFont());
    newItem.setText(newItemData.text);
    newItem.setTextColor(sf::Color::White);

    if(itemList.empty()){
        newItem.setPosition({initPos.x, initPos.y+30});

    }
    else{

        newItem.setPosition({itemList.back().getPos().x, itemList.back().getPos().y + 30});
    }

    itemList.push_back(newItem);
}


void ItemList::popItem() {

}

void ItemList::setInitPos(sf::Vector2f initPos) {
    this->initPos = initPos;
}

/**
 * iterators
 **/

ItemList::iterator ItemList::begin(){
    return itemList.begin();
}

ItemList::iterator ItemList::end() {
    return itemList.end();
}


ItemList::constIterator ItemList::begin() const {
    return itemList.begin();
}

ItemList::constIterator ItemList::end() const {
    return itemList.end();
}

/**
 * getters
 * */
std::vector<Item> &ItemList::getItemList() {
    return itemList;
}


