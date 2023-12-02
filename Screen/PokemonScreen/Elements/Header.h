//
// Created by Marthel Rodriguez on 11/29/23.
//

#ifndef SFMLTEMPLATE_HEADER_H
#define SFMLTEMPLATE_HEADER_H


#include "../../../Components/GUIComponent.h"
#include "../../../Data/PokemonStruct.h"
#include "../../../Text/Text.h"
#include "../../../Container/Container.h"
#include "../../../Components/PokemonScreenInterface.h"
#include <string>
#include <iostream>


class Header: public GUIComponent {
private:
    Container container;
    Text pokemonNo;
    Text pokemonName;
    Container backIcon;
    Container editIcon;
    Container printIcon;
    Container saveIcon;
    PokemonStruct pokemonData;
public:
    Header();
    Header(PokemonStruct &pokemonData, sf::Vector2f position);

    /**
     * sfml
     * */

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

    /***/
//    void setPokemonStruct(PokemonStruct &selectedPokemonData) override;
};


#endif //SFMLTEMPLATE_HEADER_H
