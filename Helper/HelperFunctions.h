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

class HelperFunctions {
public:

    template<typename T> inline static  void centerText(const T &obj, sf::Text &text);
    template<typename T> inline static void centerTextVertically(const T &obj, sf::Text &text, float yCoord);
    template<typename T> inline static void positionTextByBounds(const T &obj, sf::Text &text, sf::Vector2f position);


    template<typename T, typename U> inline static void centerItem(const T &obj, U &item);
    template<typename T, typename U>
    void inline static centerItemHorizontally(const T &obj, U &item, float xCoord);
    template<typename T, typename U>
    void inline static centerItemVertically(const T &obj, U &item, float yCoord);

    template<typename T, typename U>
    void inline static positionItemByBounds(const T &obj, U &item, sf::Vector2f position);
    template<typename T, typename U>
    void inline static positionItemByBoundsNoOrigin(const T &obj, U &item, sf::Vector2f position);
};


#include "HelperFunctions.cpp"

#endif //SFMLTEMPLATE_HELPERFUNCTIONS_H
