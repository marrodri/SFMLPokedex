//
// Created by Marthel Rodriguez on 11/14/23.
//

#ifndef SFMLTEMPLATE_DROPDOWNITEM_H
#define SFMLTEMPLATE_DROPDOWNITEM_H

#include "../Components/GUIComponent.h"
#include "../MultiText/MultiText.h"
#include "../MouseEvents/MouseEvents.h"
#include <iostream>
#include "../Font/Font.h"
#include "../Item/ItemStruct.h"
#include "../Helper/HelperFunctions.h"
#include "../SoundFX/SoundFX.h"
#include "../Components/ContainerInterface.h"
#include "../Data/PokemonStruct.h"
#include "../Container/Container.h"
#include "../Text/Text.h"


class DropdownItem : public GUIComponent, public ContainerInterface {
private:
    Container dropdownItemContainer;
    Text dropdownItemText;
    sf::Color hoveredColor = sf::Color::Blue;
    std::string data;
    TypesEnum pokemonTypeFilter = ANOTHERTYPE;

    void (*pFunc)() = nullptr;

    void (*pFuncType)(TypesEnum) = nullptr;

    ///private methods
    void setText(TypesEnum pokemonType);

public:
    DropdownItem();

    DropdownItem(TypesEnum pokemonType);

    /**
     * onClick function
     * */

    void setPokemonType(TypesEnum pokemonType);

    TypesEnum getPokemonType();

    void setOnClickFunct(void (*pFuncType)(TypesEnum));

    void onClick();

    /**
     * setters
     * */



    void setText(const std::string &text);

    void setFont(sf::Font &font);

    void setTextColor(const sf::Color &color);

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

    void setPosition(const sf::Vector2f &pos) override;

    void setFillColor(const sf::Color &color) override;

    void setTexture(const sf::Texture &texture) override;

    void setSize(sf::Vector2f size) override;

    void setOutlineThickness(float outlineThickness) override;

    void setOutlineColor(const sf::Color &color) override;
};


#endif //SFMLTEMPLATE_DROPDOWNITEM_H
