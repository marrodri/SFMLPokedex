//
// Created by Marthel Rodriguez on 11/14/23.
//

#ifndef SFMLTEMPLATE_ITEMLIST_H
#define SFMLTEMPLATE_ITEMLIST_H

#include <vector>
#include <list>
#include "Item.h"




template<typename T>
class ItemList {
private:
    sf::Vector2f initPos;
public:
    std::vector<T> itemList;
    ItemList();
    ItemList(std::vector<ItemStruct> initlist);


    /**
     * methods
     * */
    void setInitPos(sf::Vector2f initPos);

    void pushItem(ItemStruct newItemData);
    void pushItemVertically(T &newItem);
    void pushItemHorizontally(T &newItem);
    void popItem();
    /**
     * getters
     * */
    std::vector<T> &getItemList();
    T &getItem(int i);



    /**
     * iterators
     **/

    typedef  typename std::vector<T>::iterator iterator;
    iterator begin();
    iterator end();

    typedef  typename std::vector<T>::const_iterator constIterator;
    constIterator begin() const;
    constIterator end() const;
};

#include "ItemList.cpp"


#endif //SFMLTEMPLATE_ITEMLIST_H
