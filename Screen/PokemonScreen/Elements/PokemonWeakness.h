//
// Created by Marthel Rodriguez on 11/30/23.
//

#ifndef SFMLTEMPLATE_POKEMONWEAKNESS_H
#define SFMLTEMPLATE_POKEMONWEAKNESS_H
#include "../../../Components/GUIComponent.h"
#include "../../../Text/Text.h"
#include "../../../Container/Container.h"
#include "../../../Components/PokemonScreenInterface.h"

class PokemonWeakness : public  GUIComponent{
private:
    Container container;
    Text placeholder;
    Container firstWeakness;
    Container secondWeakness;
    Container thirdWeakness;
    //TODO: Container weaknesses
    PokemonStruct pokemonData;
public:
    PokemonWeakness();
    PokemonWeakness(int pokemonNo);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;
};


#endif //SFMLTEMPLATE_POKEMONWEAKNESS_H
