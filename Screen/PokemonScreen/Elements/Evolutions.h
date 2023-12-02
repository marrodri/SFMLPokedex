//
// Created by Marthel Rodriguez on 11/30/23.
//

#ifndef SFMLTEMPLATE_EVOLUTIONS_H
#define SFMLTEMPLATE_EVOLUTIONS_H


#include "../../../Components/GUIComponent.h"
#include "../../../Container/Container.h"
#include "../../../Text/Text.h"
#include "../../../AnimatedSprite/AnimatedSprite.h"

//for evolutions constructor.
//container({470, 150}, {450, 200}, sf::Color::Blue),
//placeholder("Description", 25, Font::getFont(), {250, 100}) {
//HelperFunctions::centerItem(container, placeholder);
class Evolutions : public GUIComponent{
private:
    Container container;
    Text placeholder;
    AnimatedSprite firstEvol;
    Text firstEvolName;
    AnimatedSprite secEvol;
    Text secEvolName;
    AnimatedSprite finalEvol;
    Text finalEvolName;
//    icon arrow.
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
