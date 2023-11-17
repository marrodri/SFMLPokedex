//
// Created by Marthel Rodriguez on 11/16/23.
//

#ifndef SFMLTEMPLATE_ITEMSTRUCT_H
#define SFMLTEMPLATE_ITEMSTRUCT_H

#include <string>
struct ItemStruct{
    std::string text;
    void (*functPtr)();
};



#endif
