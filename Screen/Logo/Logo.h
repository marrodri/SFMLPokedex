//
// Created by Marthel Rodriguez on 11/23/23.
//

#ifndef SFMLTEMPLATE_LOGO_H
#define SFMLTEMPLATE_LOGO_H

#include "../../Components/GUIComponent.h"
class Logo :public GUIComponent{
private:
    sf::RectangleShape logoContainer;

public:
    Logo();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

};


#endif //SFMLTEMPLATE_LOGO_H
