//
// Created by Marthel Rodriguez on 11/21/23.
//

#ifndef SFMLTEMPLATE_HOMESCREEN_H
#define SFMLTEMPLATE_HOMESCREEN_H

#include "../../Components/GUIComponent.h"
#include "./Views/GridView.h"
class HomeScreen: public GUIComponent{

private:
    GridView gridView;
    sf::RectangleShape homeScreen;
public:
    HomeScreen();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

};


#endif //SFMLTEMPLATE_HOMESCREEN_H
