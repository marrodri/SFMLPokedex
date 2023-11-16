//
// Created by Marthel Rodriguez on 11/14/23.
//

#ifndef SFMLTEMPLATE_HELPERFUNCTIONS_H
#define SFMLTEMPLATE_HELPERFUNCTIONS_H


/**
 * TODO: build a static class that works as a helper
 * for the whole app.
 * */
#include <SFML/Graphics.hpp>
template<typename T>
class HelperFunctions {
public:
    static void centerText(const T &obj, sf::Text &text);
};

#include "HelperFunctions.cpp"

#endif //SFMLTEMPLATE_HELPERFUNCTIONS_H
