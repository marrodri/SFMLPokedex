//
// Created by Marthel Rodriguez on 12/3/23.
//

#ifndef SFMLTEMPLATE_CONTAINERINTERFACE_H
#define SFMLTEMPLATE_CONTAINERINTERFACE_H

#include "SFML/Graphics.hpp"
class ContainerInterface{
    /**
 * getters;
 **/
    virtual sf::Vector2f getPosition()=0;
    virtual sf::Vector2f getSize()=0;
    virtual sf::FloatRect getLocalBounds() const=0;
    virtual sf::FloatRect getGlobalBounds() const=0;

    /**
     * setters
     * */
    virtual void setOrigin(sf::Vector2f &origin)=0;
    virtual void setPosition(const sf::Vector2f &pos)=0;
    virtual void setFillColor(const sf::Color &color)=0;
    virtual void setTexture(const sf::Texture &texture)=0;
    virtual void setSize(sf::Vector2f size)=0;
    virtual void setOutlineThickness(float outlineThickness)=0;
    virtual void setOutlineColor(const sf::Color &color)=0;


};
#endif //SFMLTEMPLATE_CONTAINERINTERFACE_H
