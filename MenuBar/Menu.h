//
// Created by Marthel Rodriguez on 12/7/23.
//

#ifndef SFMLTEMPLATE_MENU_H
#define SFMLTEMPLATE_MENU_H


#include "../Components/ContainerInterface.h"
#include "../Components/GUIComponent.h"
#include "../Container/Container.h"
#include "../Text/Text.h"
#include "MenuItem.h"
#include "../Item/ItemList.h"

enum menuOptionsEnum {WINDOW_MENU, FILE_MENU, THEME_MENU};

class Menu : public GUIComponent, public ContainerInterface{
private:
    MenuItem button;
    ItemList<MenuItem> options;
     sf::Vector2f WINDOW_OPTION_POS={0,0};
     sf::Vector2f WINDOW_OPTION_SIZE= {80, 30};
//    const sf::Vector2f FILE_MENU_POS={};
//    const sf::Vector2f FILE_MENU_SIZE={};
//    const sf::Vector2f THEME_MENU_POS={};
//    const sf::Vector2f THEME_MENU_SIZE={};


public:
    Menu();
    Menu(menuOptionsEnum optionEnum);
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


#endif //SFMLTEMPLATE_MENU_H
