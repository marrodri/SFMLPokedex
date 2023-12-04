//
// Created by Marthel Rodriguez on 10/12/23.
//

#ifndef SFMLTEMPLATE_SCREEN_H
#define SFMLTEMPLATE_SCREEN_H
#include <SFML/Graphics.hpp>
#include "../Components/GUIComponent.h"
#include "PokemonScreen/PokemonScreen.h"
#include "Home/Home.h"
#include "ScreenEnum.h"
#include "MainScreenButton/MainScreenButton.h"
#include "Logo/Logo.h"
#include "SideMenu/SideMenu.h"
#include "SearchInput/SearchInput.h"


//this is where the background will be used.
class Screen : public GUIComponent {
    //sf::drawable has no idea how to draw a screen.
    //the children must be implemented how to draw in the screen.

    //virtual void ... const = 0; //telling the children that is a must to draw.
    sf::RectangleShape box;
    sf::Text text;
    sf::Font font;
    sf::RectangleShape background;
    //pokemon screen'
    Home mainScreen;
    PokemonScreen pokemonScreen;
    screenEnum currScreenEnum = POKEMON;

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

    SearchInput  searchInput;
    SideMenu sideMenu;
    Logo logo;

public:
    Screen();
    Screen(sf::Vector2f windowSize);
    Screen(sf::Vector2f dimensions, sf::Font font);

    /**
     * setters
     **/

    /**
     * getters
     **/
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;


};


#endif //SFMLTEMPLATE_SCREEN_H
