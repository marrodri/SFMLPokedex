//
// Created by Marthel Rodriguez on 11/11/23.
//

#ifndef SFMLTEMPLATE_KEYSHORTCUTS_H
#define SFMLTEMPLATE_KEYSHORTCUTS_H

#include <SFML/Graphics.hpp>
class KeyShortcuts {
public:
    static bool isUndo(sf::Event event);
    static bool isSaveSnapshot(sf::Event event);
    static bool isUseSnapshot(sf::Event event);
};


#endif //SFMLTEMPLATE_KEYSHORTCUTS_H
