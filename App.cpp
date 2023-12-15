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
#include "FileTree/FileTree.h"


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
//    FileTree fileTree;
    Dropdown dropdown1("Pokemon Type Filter 1", &AppHandler::setPokemonTypeFilter1, {20, 105});
    Dropdown dropdown2("Pokemon Type Filter 2", &AppHandler::setPokemonTypeFilter2, {20, 195});
    Dropdown dropdown3("Pokemon Weakness Filter 1", &AppHandler::setPokemonWeaknessFilter1, {20, 285});
    Dropdown dropdown4("Pokemon Weakness Filter 2", &AppHandler::setPokemonWeaknessFilter2, {20, 375});
    /**
     * order of animation(far behind->most from): background->screen
     **/
    /**
    * adding components
    */
    addComponent(screen);
    addComponent(dropdown4);
    addComponent(dropdown3);
    addComponent(dropdown2);
    addComponent(dropdown1);
    addComponent(menuBar);
//    addComponent(fileTree);



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

