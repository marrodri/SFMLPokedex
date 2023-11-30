//
// Created by Marthel Rodriguez on 11/21/23.
//

#ifndef SFMLTEMPLATE_POKEMONSCREEN_H
#define SFMLTEMPLATE_POKEMONSCREEN_H


#include "../../Components/GUIComponent.h"
#include "../../Container/Container.h"
#include "../../Text/Text.h"

class PokemonScreen: public GUIComponent {
private:
    sf::RectangleShape container;
    sf::Text title;
public:
    PokemonScreen();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
};


#endif //SFMLTEMPLATE_POKEMONSCREEN_H
