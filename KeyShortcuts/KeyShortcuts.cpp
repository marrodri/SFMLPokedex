//
// Created by Marthel Rodriguez on 11/11/23.
//

#include "KeyShortcuts.h"


bool KeyShortcuts::isUndo(sf::Event event) {
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)));
}

bool KeyShortcuts::isSaveSnapshot(sf::Event event) {
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)));
}

bool KeyShortcuts::isUseSnapshot(sf::Event event) {
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::V) && (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)));
}
