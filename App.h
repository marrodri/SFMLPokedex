//
// Created by Marthel Rodriguez on 9/18/23.
//

#ifndef SFMLTEMPLATE_APP_H
#define SFMLTEMPLATE_APP_H

#include <iostream>
#include <SFML/Graphics.hpp>

const int WINDOW_WIDTH = 1600;
const int WINDOW_HEIGHT = 900;


enum programsEnum {
    PROGRAM_1,PROGRAM_2,PROGRAM_3,PROGRAM_4,
};
const std::array<std::string, 7> titles = {"PROGRAM_1","PROGRAM_2","PROGRAM_3","PROGRAM_4"};
class App {

    static int currPage;
    static programsEnum selectedProgram;
    static sf::Text title;
    static sf::Text centerText;
    static sf::RenderWindow window;
    static sf::RectangleShape square;
    static sf::CircleShape leftTriangle;
    static sf::CircleShape rightTriangle;

    //-Window: the main area to be drawn.
    // -Input: a block and a label. That when the user clicks on it
    // it will show a blinking cursor, showing that the input is selected.
    //
    // -Button: button will have a passed function that will run a PopUp.
    // That
    //
    // - PopUp: will show "Hello ${Name} this is your world.!!\n Today is not your birthday :(".
    // - Letter: needed!!! you know why.

    // - Elements needed. CHECK THE PORTFOLIO PROJECT.

private:
    static void init();

    static void programOnUpdate();

    static void programEventHandler(sf::Event &event);

    static void programDraw();

public:
    App();

    static void run();

//    static void setProgram(int page);

    static void nextPage();

    static void prevPage();
};


#endif //SFMLTEMPLATE_APP_H
