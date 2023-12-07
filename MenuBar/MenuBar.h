//
// Created by Marthel Rodriguez on 12/7/23.
//

#ifndef SFMLTEMPLATE_MENUBAR_H
#define SFMLTEMPLATE_MENUBAR_H


#include "../Container/Container.h"
#include "../Components/ContainerInterface.h"
#include "Menu.h"

class MenuBar :public GUIComponent, public ContainerInterface{
private:
    Container menuBarContainer;
    ItemList<Menu> menus;
    Menu windowMenu;
    Menu fileMenu;
    Menu themeMenu;

public:
    MenuBar();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

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


#endif //SFMLTEMPLATE_MENUBAR_H
