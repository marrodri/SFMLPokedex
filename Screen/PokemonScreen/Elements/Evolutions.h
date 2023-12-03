//
// Created by Marthel Rodriguez on 11/30/23.
//

#ifndef SFMLTEMPLATE_EVOLUTIONS_H
#define SFMLTEMPLATE_EVOLUTIONS_H


#include "../../../Components/GUIComponent.h"
#include "../../../Container/Container.h"
#include "../../../Text/Text.h"
#include "../../../AnimatedSprite/AnimatedSprite.h"
#include "../../../Data/PokemonStruct.h"

//for evolutions constructor.
//container({470, 150}, {450, 200}, sf::Color::Blue),
//placeholder("Description", 25, Font::getFont(), {250, 100}) {
//HelperFunctions::centerItem(container, placeholder);
class Evolutions : public GUIComponent{
private:
    Container container;
    Container firstArrow;
    Container secondArrow;
    Text placeholder;
    ///animatedSprites.
    AnimatedSprite firstEvol;
    AnimatedSprite secEvol;
    AnimatedSprite finalEvol;

    //    Text firstEvolName;
    //    Text secEvolName;
//    Text finalEvolName;
//    icon arrow.
    PokemonStruct pokemonData;

public:
    Evolutions();
    Evolutions(const std::array<int,3> &evolutions, int cols);

    /**
     * GUI
     **/

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;
};


#endif //SFMLTEMPLATE_EVOLUTIONS_H
