//
// Created by Marthel Rodriguez on 11/21/23.
//

#ifndef SFMLTEMPLATE_MAINSCREEN_H
#define SFMLTEMPLATE_MAINSCREEN_H

#include "../../Components/GUIComponent.h"
#include "./Views/GridView.h"
#include "MainScreenButton/MainScreenButton.h"

class MainScreen: public GUIComponent{
private:
    GridView gridView;
    sf::RectangleShape homeScreenContainer;
    int currPage;
    int numberOfPages;
    ///IMPORTANT DRAW RIGHT NOW
    ///TODO: add the logic of going to previous page and next page
    ///     to the onClick of these 2 attributes.
    MainScreenButton leftButton;
    MainScreenButton rightButton;
    //later
    sf::Text currPageIndex;
    sf::Text bgmTitle;
    sf::Text sfxOrigin;
    sf::Text BackgroundImageName;
public:
    MainScreen();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;
};


#endif //SFMLTEMPLATE_MAINSCREEN_H
