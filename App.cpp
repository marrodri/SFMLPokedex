//
// Created by Marthel Rodriguez on 9/18/23.
//

#include "App.h"
#include <iostream>

#include <SFML/Graphics.hpp>
#include "Font/Font.h"
#include "TextInput/TextInput.h"
#include "Item/Item.h"
#include "Dropdown/Dropdown.h"
#include "Layout/Layout.h"
#include "Layout/MainScreen/Views/GridView.h"
#include "Layout/SideMenu/SideMenu.h"
#include "Layout/Logo/Logo.h"
#include "Layout/SearchInput/SearchInput.h"
#include "Images/Images.h"
#include "AnimatedSprite/AnimatedSprite.h"
#include "Button/GridButton.h"
#include "Layout/MainScreen/MainScreen.h"

std::vector<GUIComponent*> App::components;

void App::init(){
    Font font;
    TextInput firstNameInput(sf::Vector2f(80,310), sf::Vector2f(220,60), font.getFont(), font.getFont(), "First Name");
    TextInput lastNameInput(sf::Vector2f(80,450), sf::Vector2f(220,60), font.getFont(), font.getFont(), "Last Name");
    addComponent(firstNameInput);
    addComponent(lastNameInput);
}

void App::addComponent(GUIComponent& component){
    components.push_back(&component);
}

void App::run() {
    srand(time(0));
    //init window
    const int  WINDOW_WIDTH=950;
    const int  WINDOW_HEIGHT=600;
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "My window");
    window.setFramerateLimit(60);

    ///animated sprite
    //bulbasaur
//    AnimatedSprite animatedSprite(Images::get3DImage(0),1,41);
    //polywhirl

    sf::RectangleShape wholeSprite;
//    wholeSprite.setTexture(&Images::get3DImage(0));
//    wholeSprite.setPosition(0,0);
//    wholeSprite.setSize({100, 100});
    AnimatedSprite animatedSprite(Images::get3DImage(0),1,40);
    animatedSprite.setPosition(50,50);
    animatedSprite.setTime(50);

    //animated screen
    MainScreen mainScreen;
    ///SearchInput.
    SearchInput  searchInput;
    ///Side Menu
    SideMenu sideMenu;
    ///Logo
    Logo logo;

    ///Background
    Layout screen(sf::Vector2f({WINDOW_WIDTH, WINDOW_HEIGHT}));
    /**
     * order of animation(far behind->most from): background->screen
     * */
//    addComponent(screen);
    addComponent(animatedSprite);

//    addComponent(mainScreen);
//    addComponent(searchInput);
//    addComponent(sideMenu);
//    addComponent(logo);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            for(GUIComponent* &g: components){
                g->addEventHandler(window, event);
            }
        }
        for(GUIComponent* &g: components){
            g->update();
        }
        window.clear();
        for(GUIComponent* &g: components){
            window.draw(*g);
        }
        window.draw(wholeSprite);
        window.display();
    }
}
