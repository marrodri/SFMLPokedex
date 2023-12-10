//
// Created by Marthel Rodriguez on 11/14/23.
//

#ifndef SFMLTEMPLATE_ITEMLIST_CPP
#define SFMLTEMPLATE_ITEMLIST_CPP

#include "ItemList.h"


template<typename T>
ItemList<T>::ItemList() {

}

template<typename T>
ItemList<T>::ItemList(std::vector<ItemStruct> initlist) {

}


/**
 * position methods
 * */
template<typename T>
void ItemList<T>::updateListPosition(sf::Vector2f pos) {
//
//    for (auto item = itemList.begin(); item != itemList.end(); item++) {
//        sf::Vector2f prevPos = item->getPosition();
//        item->setPosition({prevPos.x + pos.x, prevPos.y + pos.y});
//    }

    auto item = itemList.begin();
    if (item != itemList.end()) {
        std::cout << "posx: " << pos.x << ", posy: " << pos.y << "\n";
        item->setPosition(pos);
        sf::Vector2f prevPos = item->getPosition();
        item++;
        while (item != itemList.end()) {
            item->setPosition({prevPos.x, prevPos.y + item->getSize().y});
            prevPos = item->getPosition();
            item++;
        }
    }
}

template<typename T>
void ItemList<T>::setColumnListPosition(sf::Vector2f pos) {

    auto item = itemList.begin();
//    if (item) {


        item->setPosition(pos);
        item++;
        while (item != itemList.end()) {
            sf::Vector2f prevPos = item->getPosition();
            item->setPosition({prevPos.x, prevPos.y + item->getSize().y});
        }
//    }
}

/**
 * methods
 * */


template<typename T>
void ItemList<T>::pushItemHorizontally(T &newItem) {
    if (itemList.empty()) {
        itemList.push_back(newItem);
    } else {
        newItem.setPosition(
                {itemList.back().getPosition().x + itemList.back().getSize().
                        x, itemList.back().getPosition().y});
    }
    itemList.push_back(newItem);
}

template<typename T>
void ItemList<T>::pushItemVertically(T &newItem) {
    if (itemList.empty()) {
        itemList.push_back(newItem);
    } else {
        newItem.setPosition(
                {itemList.back().getPosition().x, itemList.back().getPosition().y + itemList.back().getSize().
                        y});
    }
//    itemList.insert(itemList.begin(),newItem);
    itemList.push_back(newItem);
}


template<typename T>
void ItemList<T>::pushFrontItemVertically(T &newItem) {
    if (itemList.empty()) {
        itemList.push_back(newItem);
    } else {
        newItem.setPosition(
                {itemList.back().getPosition().x, itemList.back().getPosition().y + itemList.back().getSize().
                        y});
    }
    itemList.insert(itemList.begin(), newItem);
}


template<typename T>
void ItemList<T>::popItem() {
    if (!itemList.empty())
        itemList.pop_back();
}

template<typename T>
void ItemList<T>::setInitPos(sf::Vector2f initPos) {
    this->initPos = initPos;
}

/**
 * iterators
 **/

template<typename T>
typename ItemList<T>::iterator ItemList<T>::begin() {
    return itemList.begin();
}

template<typename T>
typename ItemList<T>::iterator ItemList<T>::end() {
    return itemList.end();
}


template<typename T>
typename ItemList<T>::constIterator ItemList<T>::begin() const {
    return itemList.begin();
}

template<typename T>
typename ItemList<T>::constIterator ItemList<T>::end() const {
    return itemList.end();
}

/**
 * getters
 * */
template<typename T>
std::vector<T> &ItemList<T>::getItemList() {
    return itemList;
}

template<typename T>
T &ItemList<T>::getItem(int i) {
    return itemList(i);
}

template<typename T>
bool ItemList<T>::empty() {
    return itemList.empty();
}

template<typename T>
sf::Vector2f ItemList<T>::getLastItemPosition() {
    if (itemList.size() > 0) {
        return itemList[itemList.size() - 1].getPosition();
    }
}

#endif