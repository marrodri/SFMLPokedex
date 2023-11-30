//
// Created by Marthel Rodriguez on 11/30/23.
//

#ifndef SFMLTEMPLATE_DESCRIPTION_H
#define SFMLTEMPLATE_DESCRIPTION_H


#include "../../../Container/Container.h"
#include "../../../Text/Text.h"

class Description: public GUIComponent {

private:
    Container container;
    Text placeholder;
public:
    Description();
    Description(int pokemonNo);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;


};


#endif //SFMLTEMPLATE_DESCRIPTION_H
