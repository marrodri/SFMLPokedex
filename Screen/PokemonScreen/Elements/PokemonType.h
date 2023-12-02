//
// Created by Marthel Rodriguez on 11/30/23.
//

#ifndef SFMLTEMPLATE_POKEMONTYPE_H
#define SFMLTEMPLATE_POKEMONTYPE_H


#include "../../../Components/GUIComponent.h"
#include "../../../Container/Container.h"
#include "../../../Text/Text.h"
#include "../../../Components/PokemonScreenInterface.h"

class PokemonType : public GUIComponent{
private:
    Container container;
    Text placeholder;
public:
    PokemonType();
    PokemonType(int pokemonNo);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;
};


#endif //SFMLTEMPLATE_POKEMONTYPE_H
