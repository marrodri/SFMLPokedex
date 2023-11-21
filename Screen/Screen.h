//
// Created by Marthel Rodriguez on 10/12/23.
//

#ifndef SFMLTEMPLATE_SCREEN_H
#define SFMLTEMPLATE_SCREEN_H
#include <SFML/Graphics.hpp>
#include "../Components/GUIComponent.h"
//this is where the background will be used.
class Screen : public GUIComponent {
    //sf::drawable has no idea how to draw a screen.
    //the children must be implemented how to draw in the screen.

    //virtual void ... const = 0; //telling the children that is a must to draw.
    sf::RectangleShape box;
    sf::Text text;
    sf::Font font;
    sf::RectangleShape background;
    //DropDown Menu Bar.


public:
    Screen();
    Screen(sf::Vector2f windowSize);
    Screen(sf::Vector2f dimensions, sf::Font font);


    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;


};


#endif //SFMLTEMPLATE_SCREEN_H
