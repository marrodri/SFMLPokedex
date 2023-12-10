//
// Created by Marthel Rodriguez on 11/14/23.
//

#ifndef SFMLTEMPLATE_HELPERFUNCTIONS_CPP
#define SFMLTEMPLATE_HELPERFUNCTIONS_CPP

#include "HelperFunctions.h"

template<typename T>
void HelperFunctions::centerText(const T &obj, sf::Text &text)
{
    sf::FloatRect textRect = text.getGlobalBounds();
    sf::FloatRect tRect = obj.getGlobalBounds();
    sf::Vector2f center = {textRect.width/2.0f, textRect.height/2.f};
    sf::Vector2f localBounds = {center.x + text.getLocalBounds().left, center.y + text.getLocalBounds().top};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
    text.setOrigin(rounded);
    text.setPosition({tRect.left + tRect.width/2, tRect.top + tRect.height/2});
}

template<typename T, typename U>
void HelperFunctions::centerItem(const T &obj, U &item)
{
    sf::FloatRect textRect = item.getGlobalBounds();
    sf::FloatRect tRect = obj.getGlobalBounds();
    sf::Vector2f center = {textRect.width/2.0f, textRect.height/2.f};
    sf::Vector2f localBounds = {center.x + item.getLocalBounds().left, center.y + item.getLocalBounds().top};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
    item.setOrigin(rounded);
    item.setPosition({tRect.left + tRect.width/2, tRect.top + tRect.height/2});
}

template<typename T, typename U>
void HelperFunctions::centerItemVertically(const T &obj, U &item, float yCoord)
{
    sf::FloatRect itemRect = item.getGlobalBounds();
    sf::FloatRect tRect = obj.getGlobalBounds();
    sf::Vector2f center = {itemRect.width/2.0f, itemRect.height/2.f};
    sf::Vector2f localBounds = {center.x + item.getLocalBounds().left, center.y + item.getLocalBounds().top};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
    item.setOrigin(rounded);
    item.setPosition({tRect.left + tRect.width/2, tRect.top + yCoord});
}

template<typename T, typename U>
void HelperFunctions::centerItemHorizontally(const T &obj, U &item, float xCoord)
{
    sf::FloatRect itemRect = item.getGlobalBounds();
    sf::FloatRect tRect = obj.getGlobalBounds();
    sf::Vector2f center = {itemRect.width/2.0f, itemRect.height/2.f};
    sf::Vector2f localBounds = {center.x + item.getLocalBounds().left, center.y + item.getLocalBounds().top};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
    item.setOrigin(rounded);
    item.setPosition({tRect.left + xCoord, tRect.top + tRect.height/2});
}

template<typename T, typename U>
void HelperFunctions::positionItemByBounds(const T &obj, U &item, sf::Vector2f position){
    sf::FloatRect itemRect = item.getGlobalBounds();
    sf::FloatRect tRect = obj.getGlobalBounds();
    sf::Vector2f center = {itemRect.width/2.0f, itemRect.height/2.f};
    sf::Vector2f localBounds = {center.x + item.getLocalBounds().left, center.y + item.getLocalBounds().top};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
    item.setOrigin(rounded);
    item.setPosition({tRect.left + position.x, tRect.top + position.y});
}

template<typename T, typename U>
void HelperFunctions::positionItemByBoundsNoOrigin(const T &obj, U &item, sf::Vector2f position){
    sf::FloatRect itemRect = item.getGlobalBounds();
    sf::FloatRect tRect = obj.getGlobalBounds();
    sf::Vector2f center = {itemRect.width/2.0f, itemRect.height/2.f};
    sf::Vector2f localBounds = {center.x + item.getLocalBounds().left, center.y + item.getLocalBounds().top};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
//    item.setOrigin(rounded);
    item.setPosition({tRect.left + position.x, tRect.top + position.y});
}


template<typename T>
void HelperFunctions::centerTextVertically(const T &obj, sf::Text &text, float yCoord)
{
    sf::FloatRect textRect = text.getGlobalBounds();
    sf::FloatRect tRect = obj.getGlobalBounds();
    sf::Vector2f center = {textRect.width/2.0f, textRect.height/2.f};
    sf::Vector2f localBounds = {center.x + text.getLocalBounds().left, center.y + text.getLocalBounds().top};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
    text.setOrigin(rounded);
    text.setPosition({tRect.left + tRect.width/2, tRect.top + yCoord});
}

template<typename T>
void HelperFunctions::positionTextByBounds(const T &obj, sf::Text &text, sf::Vector2f position){
    sf::FloatRect textRect = text.getGlobalBounds();
    sf::FloatRect tRect = obj.getGlobalBounds();
    sf::Vector2f center = {textRect.width/2.0f, textRect.height/2.f};
    sf::Vector2f localBounds = {center.x + text.getLocalBounds().left, center.y + text.getLocalBounds().top};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
    text.setOrigin(rounded);
    text.setPosition({tRect.left + position.x, tRect.top + position.y});
}


sf::Text &HelperFunctions::setUpText(sf::Font &font, int fontSize, sf::Vector2f pos) {
    sf::Text *newText = new sf::Text;
    newText->setFont(font);
    newText->setCharacterSize(fontSize);
    newText->setPosition(pos);
    return *newText;
}


#endif
