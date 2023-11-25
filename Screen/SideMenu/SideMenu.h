//
// Created by Marthel Rodriguez on 11/21/23.
//

#ifndef SFMLTEMPLATE_SIDEMENU_H
#define SFMLTEMPLATE_SIDEMENU_H

#include "../../Components/GUIComponent.h"
class SideMenu : public GUIComponent{
    sf::RectangleShape sideMenuContainer;
    sf::Text placeholder;

public:
    SideMenu();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;
};


#endif //SFMLTEMPLATE_SIDEMENU_H
