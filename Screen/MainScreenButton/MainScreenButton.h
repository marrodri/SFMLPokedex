//
// Created by Marthel Rodriguez on 11/25/23.
//

#ifndef SFMLTEMPLATE_MAINSCREENBUTTON_H
#define SFMLTEMPLATE_MAINSCREENBUTTON_H


#include "../../Components/GUIComponent.h"
#include "../../Components/ButtonInterface.h"

class MainScreenButton : public GUIComponent, private ButtonInterface{
private:
    sf::RectangleShape buttonContainer;
    sf::Text text; //TODO: update dropdownItemText to a texture for the arrows.


    /**
    * menuItem interface methods
    **/
    void onClick() override;
    void setOnClickFunction() override;
    void onHoverSound() override;
    void onClickSound() override;
public:
    MainScreenButton(sf::Vector2f position, std::string text);

    /**
     * gui component sfml.
     **/
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;
};


#endif //SFMLTEMPLATE_MAINSCREENBUTTON_H
