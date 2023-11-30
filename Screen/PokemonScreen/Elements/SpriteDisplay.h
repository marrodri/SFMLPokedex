//
// Created by Marthel Rodriguez on 11/30/23.
//

#ifndef SFMLTEMPLATE_SPRITEDISPLAY_H
#define SFMLTEMPLATE_SPRITEDISPLAY_H


#include "../../../Components/GUIComponent.h"
#include "../../../Container/Container.h"
#include "../../../Text/Text.h"

class SpriteDisplay : public GUIComponent{
private:
    Container container;
    Text placeholder;

public:
    SpriteDisplay();
    SpriteDisplay(int pokemonNo);

    /**
     * GUI
     **/

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;
};


#endif //SFMLTEMPLATE_SPRITEDISPLAY_H
