//
// Created by Marthel Rodriguez on 9/18/23.
//

#include "App.h"
#include <SFML/Graphics.hpp>
#include "Font/Font.h"
#include "Screen/Screen.h"
#include "Screen/SideMenu/SideMenu.h"
#include "Screen/Logo/Logo.h"
#include "Screen/SearchInput/SearchInput.h"
#include "MenuBar/MenuBar.h"
#include "Dropdown/Dropdown.h"


std::vector<GUIComponent *> App::components;


void App::addComponent(GUIComponent &component) {
    components.push_back(&component);
}

void App::run() {
    srand(time(0));
    //init window
    const int WINDOW_WIDTH = 1000;
    const int WINDOW_HEIGHT = 600;
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "My window");
    window.setFramerateLimit(60);

    /*
     * initializing UI
     * */

    Screen screen(sf::Vector2f({WINDOW_WIDTH, WINDOW_HEIGHT}));
    MenuBar menuBar;
    Dropdown dropdown;
    /**
     * order of animation(far behind->most from): background->screen
     **/
    /**
    * adding components
    */
//    addComponent(screen);
//    addComponent(menuBar);
    addComponent(dropdown);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            for (GUIComponent *&g: components) {
                g->addEventHandler(window, event);
            }
        }
        for (GUIComponent *&g: components) {
            g->update();
        }
        window.clear();
        for (GUIComponent *&g: components) {
            window.draw(*g);
        }
        window.display();
    }
}

