//
// Created by Marthel Rodriguez on 11/14/23.
//

#ifndef SFMLTEMPLATE_ITEMLIST_H
#define SFMLTEMPLATE_ITEMLIST_H

#include <vector>
#include <list>
#include "Item.h"




class ItemList {
private:

public:
    std::vector<Item> itemList;
    ItemList();
    ItemList(std::vector<ItemStruct> initlist);

    /**
     * methods
     * */

    void pushItem(ItemStruct newItemData);
    void popItem();
    /**
     * getters
     * */
    std::vector<Item> &getItemList();



    /**
     * iterators
     * */
     typedef std::vector<Item>::iterator iterator;
    iterator begin();
    iterator end();

    typedef std::vector<Item>::const_iterator constIterator;
    constIterator begin() const;
    constIterator end() const;



};


#endif //SFMLTEMPLATE_ITEMLIST_H
