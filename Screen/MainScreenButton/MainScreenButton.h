//
// Created by Marthel Rodriguez on 11/25/23.
//

#ifndef SFMLTEMPLATE_MAINSCREENBUTTON_H
#define SFMLTEMPLATE_MAINSCREENBUTTON_H


#include "../../Components/GUIComponent.h"
#include "../../Components/ButtonInterface.h"
#include "../../Components/ContainerInterface.h"

class MainScreenButton : public GUIComponent, public ContainerInterface,private ButtonInterface{
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

    /**
     * container interface methods
     * */

    sf::Vector2f getPosition() override;

    sf::Vector2f getSize() override;

    sf::FloatRect getLocalBounds() const override;

    sf::FloatRect getGlobalBounds() const override;

    void setOrigin(sf::Vector2f &origin) override;

    void setPosition(const sf::Vector2f &pos) override;

    void setFillColor(const sf::Color &color) override;

    void setTexture(const sf::Texture &texture) override;

    void setSize(sf::Vector2f size) override;

    void setOutlineThickness(float outlineThickness) override;

    void setOutlineColor(const sf::Color &color) override;
};


#endif //SFMLTEMPLATE_MAINSCREENBUTTON_H
