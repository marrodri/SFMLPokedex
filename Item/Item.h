//
// Created by Marthel Rodriguez on 11/14/23.
//

#ifndef SFMLTEMPLATE_ITEM_H
#define SFMLTEMPLATE_ITEM_H

#include "../Components/GUIComponent.h"
#include "../MultiText/MultiText.h"
#include "../MouseEvents/MouseEvents.h"
#include <iostream>
#include "../Font/Font.h"
#include "../Helper/HelperFunctions.h"

struct ItemStruct{
    std::string text;
    void (*functPtr)();
};

class Item : public GUIComponent {
private:
    sf::RectangleShape box;
    sf::Text textUI;
    sf::Color hoveredColor = sf::Color::Blue;

    void (*pOnClick)();
public:
    Item();
    /**
     * onClick function
     * */

    /**
     * setters
     * */
    void setPosition(sf::Vector2f position);
    void setText(std::string text);
    void setFont(sf::Font &font);
    void setTextColor(const sf::Color &color);
    void setBorderWidth(int borderWidth);
    void setHoverColor(const sf::Color &color);
    //TODO: check how to create a dropdown shadow for the item.
    void setDropdownShadow();
    //TODO: check how to pass a function that will be run when being clicked.
    void setOnClickFunction(void (*pOnClick)());

    /**
     * getters
     * */
     sf::Vector2f getPos();


    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;


};


#endif //SFMLTEMPLATE_ITEM_H
