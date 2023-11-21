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
#include "Screen/Screen.h"

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
    //init window
    const int  WINDOW_WIDTH=800;
    const int  WINDOW_HEIGHT=600;
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "My window");
    window.setFramerateLimit(60);
    Font font;
    Screen screen(sf::Vector2f({800,600}));
    addComponent(screen);
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
        window.display();
    }
}
