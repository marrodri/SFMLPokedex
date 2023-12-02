//
// Created by Marthel Rodriguez on 11/30/23.
//

#ifndef SFMLTEMPLATE_SPRITEDISPLAY_H
#define SFMLTEMPLATE_SPRITEDISPLAY_H


#include "../../../Components/GUIComponent.h"
#include "../../../Container/Container.h"
#include "../../../Text/Text.h"
#include "../../../AnimatedSprite/AnimatedSprite.h"
#include "../../../Components/PokemonScreenInterface.h"

class SpriteDisplay : public GUIComponent{
private:
    Container container;
    Text placeholder;
    AnimatedSprite sprite3D;
    PokemonStruct pokemonData;

    bool isLoaded = false;
public:
    SpriteDisplay();
    SpriteDisplay(int pokemonNo, int cols);

    /**
     * GUI Component
     **/
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;


};


#endif //SFMLTEMPLATE_SPRITEDISPLAY_H
