//
// Created by Marthel Rodriguez on 11/22/23.
//

#ifndef SFMLTEMPLATE_GRIDBUTTON_H
#define SFMLTEMPLATE_GRIDBUTTON_H

#include "../Components/GUIComponent.h"
#include "../MouseEvents/MouseEvents.h"
#include "../Helper/HelperFunctions.h"
#include "../Components/ButtonInterface.h"
#include "../Data/PokemonStruct.h"
#include "../AnimatedSprite/AnimatedSprite.h"
struct coordStruct {
    float x;
    float y;
};
class GridButton : public GUIComponent, private ButtonInterface {
private:
    sf::RectangleShape box;
    sf::Text text;
    sf::Text number;
    AnimatedSprite sprite3D;
    sf::Text pokemonName;
    PokemonStruct pokemonData;
    coordStruct numPos = {13,16};
    //TODO: create a pointer struct for storing the Pokemon
    /**
    * button interface methods
    **/
    void onClick() override;

    void setOnClickFunction() override;

    void onHoverSound() override;

    void onClickSound() override;

public:
    GridButton();

    GridButton(sf::Font &font, sf::Vector2f pos, int i);

    GridButton(sf::Font &font, sf::Vector2f pos, PokemonStruct &pokemonData);

    /*
     * getters
     * */
    sf::Vector2f getPosition();

    sf::Vector2f getSize();

    /**
     * setters
     * */
    void setPosition(sf::Vector2f pos);

    void setPokemonData(PokemonStruct &pokemondata);


public:

    /**
     * GUI component
     **/
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;
};


#endif //SFMLTEMPLATE_GRIDBUTTON_H
