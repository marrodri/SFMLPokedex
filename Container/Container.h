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
    Container(sf::Vector2f pos, sf::Vector2f size, sf::Color &color);
    Container(sf::Vector2f pos, sf::Vector2f size, sf::Texture &texture);

    /**
     * getters;
     **/
     sf::Vector2f getPosition();
    sf::Vector2f getSize();
     sf::FloatRect getLocalBounds() const;
     sf::FloatRect getGlobalBounds() const;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;
};


#endif //SFMLTEMPLATE_CONTAINER_H
