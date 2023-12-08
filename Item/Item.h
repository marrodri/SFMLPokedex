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
#include "ItemStruct.h"
#include "../Helper/HelperFunctions.h"
#include "../SoundFX/SoundFX.h"
#include "../Components/ContainerInterface.h"
#include "../Data/PokemonStruct.h"
#include "../Container/Container.h"


class Item : public GUIComponent, public ContainerInterface {
private:
    Container dropdownItemContainer;
    sf::Text textUI;
    sf::Color hoveredColor = sf::Color::Blue;
    std::string data;
    TypesEnum pokemonTypeFilter;


public:
    Item();

    /**
     * onClick function
     * */
    void onClick();
    void setPokemonType(TypesEnum pokemonType);
    void getPokemonType();

    /**
     * setters
     * */

    void setPosition(const sf::Vector2f &pos) override;

    void setText(const std::string &text);

    void setFont(sf::Font &font);

    void setTextColor(const sf::Color &color);

    void setBorderWidth(int borderWidth);

    void setHoverColor(const sf::Color &color);


    /**
     * getters
     **/
    sf::Vector2f getPos();

    std::string &getData();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

    /**
     * container interface
     * */
public:
    sf::Vector2f getPosition() override;

    sf::Vector2f getSize() override;

    sf::FloatRect getLocalBounds() const override;

    sf::FloatRect getGlobalBounds() const override;

    void setOrigin(sf::Vector2f &origin) override;

//    void setPosition(const sf::Vector2f &pos) override {
//        box.setPosition(pos);
//    }

    void setFillColor(const sf::Color &color) override;

    void setTexture(const sf::Texture &texture) override;

    void setSize(sf::Vector2f size) override;

    void setOutlineThickness(float outlineThickness) override;

    void setOutlineColor(const sf::Color &color) override;
};


#endif //SFMLTEMPLATE_ITEM_H
