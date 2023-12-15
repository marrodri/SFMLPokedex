//
// Created by Marthel Rodriguez on 12/11/23.
//

#ifndef SFMLTEMPLATE_FILETREESCREEN_H
#define SFMLTEMPLATE_FILETREESCREEN_H


#include "../../Container/Container.h"
#include "../../Text/Text.h"
#include "../../Components/ContainerInterface.h"
#include "../PokemonScreen/Elements/Header.h"
#include "../../FileTree/FileItem.h"
#include "../../FileTree/FileTree.h"

class FileTreeScreen: public GUIComponent, public ContainerInterface {
private:
    Container fileTreeContainer;
    Container fileTreeBackgrounImage;
    Text fileTreePlaceHolder;
    Header header;
    FileTree fileTree;
public:
    FileTreeScreen();

    /**
     * gui methods
     * */


    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;


    /**
     * container methods
     * */

private:
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


#endif //SFMLTEMPLATE_FILETREESCREEN_H
