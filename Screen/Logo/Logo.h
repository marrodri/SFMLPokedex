//
// Created by Marthel Rodriguez on 11/23/23.
//

#ifndef SFMLTEMPLATE_LOGO_H
#define SFMLTEMPLATE_LOGO_H

#include "../../Components/GUIComponent.h"
#include "../../Components/ButtonInterface.h"

class Logo :public GUIComponent, private ButtonInterface{
private:
    sf::RectangleShape logoContainer;

    /**
    * button interface methods
    **/
    void onClick() override;
    void setOnClickFunction() override;
    void onHoverSound() override;
    void onClickSound() override;

public:
    Logo();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

};


#endif //SFMLTEMPLATE_LOGO_H
