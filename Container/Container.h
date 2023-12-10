//
// Created by Marthel Rodriguez on 11/29/23.
//

#ifndef SFMLTEMPLATE_CONTAINER_H
#define SFMLTEMPLATE_CONTAINER_H


#include "../Components/GUIComponent.h"

class Container : public GUIComponent {
private:
    sf::RectangleShape container;
    sf::Text text;
public:
    Container();
    Container(sf::Vector2f pos, sf::Vector2f size, const sf::Color &color);
    Container(sf::Vector2f pos, sf::Vector2f size, sf::Texture &texture);

    /**
     * getters;
     **/
     sf::Vector2f getPosition();
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize();
     sf::FloatRect getLocalBounds() const;
     sf::FloatRect getGlobalBounds() const;

     /**
      * setters
      * */
    void setOrigin(sf::Vector2f &origin);
    void setPosition(const sf::Vector2f &pos);
    void setFillColor(const sf::Color &color);
    void setTexture(const sf::Texture &texture);
    void setSize(sf::Vector2f size);
    void setOutlineThickness(float outlineThickness);
    void setOutlineColor(const sf::Color &color);


    /**
     * gui components
     * */

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;



};


#endif //SFMLTEMPLATE_CONTAINER_H
