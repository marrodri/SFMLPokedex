//
// Created by Marthel Rodriguez on 12/5/23.
//

#ifndef SFMLTEMPLATE_SEARCHITEM_H
#define SFMLTEMPLATE_SEARCHITEM_H


#include "../../Text/Text.h"
#include "../../Container/Container.h"
#include "../../Data/PokemonStruct.h"
#include "../../Components/ContainerInterface.h"

class SearchItem: public GUIComponent, public ContainerInterface{
private:
    //BONUS: an container for the icon
    Container container;
    Text text;
    PokemonStruct pokemonData;
public:
    SearchItem();
    SearchItem(Container &container, Text text, PokemonStruct &pokemonData);


    /**
     * container virtual methods
     * */
    sf::Vector2f getPosition();

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

public:


    /**
     * GUI methods
     * */
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;


};


#endif //SFMLTEMPLATE_SEARCHITEM_H
