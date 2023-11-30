//
// Created by Marthel Rodriguez on 11/21/23.
//

#ifndef SFMLTEMPLATE_POKEMONSCREEN_H
#define SFMLTEMPLATE_POKEMONSCREEN_H


#include "../../Components/GUIComponent.h"
#include "../../Container/Container.h"
#include "../../Text/Text.h"
#include "Elements/Header.h"
#include "Elements/SpriteDisplay.h"
#include "Elements/Description.h"
#include "Elements/Evolutions.h"
#include "Elements/PokemonWeakness.h"
#include "Elements/PokemonType.h"

class PokemonScreen: public GUIComponent {
private:
    Header header;
    SpriteDisplay spriteDisplay;
    Description description;
    Evolutions evolutions;
    PokemonType pokemonType;
    PokemonWeakness pokemonWeakness;

    sf::RectangleShape container;
    sf::Text title;
public:
    PokemonScreen();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
};


#endif //SFMLTEMPLATE_POKEMONSCREEN_H
