//
// Created by Marthel Rodriguez on 9/18/23.
//

#include "App.h"
#include <iostream>

#include <SFML/Graphics.hpp>

//#include "UIComponent.h"
#include "Font/Font.h"
#include "MultiText/MultiText.h"
#include "TextInput/TextInput.h"

void App::run() {
    const int  WINDOW_WIDTH=600;
    const int  WINDOW_HEIGHT=800;
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "My window");

    Font font;
    sf::Text text;
    TextInput firstNameInput(sf::Vector2f(80,310), sf::Vector2f(220,60), font.getFont(), font.getFont(), "First Name");
    TextInput lastNameInput(sf::Vector2f(80,450), sf::Vector2f(220,60), font.getFont(), font.getFont(), "Last Name");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            firstNameInput.eventHandler(window, event);
            lastNameInput.eventHandler(window, event);
        }
        firstNameInput.update();
        lastNameInput.update();
        window.clear();
        window.draw(firstNameInput);
        window.draw(lastNameInput);

        window.display();
    }
}
