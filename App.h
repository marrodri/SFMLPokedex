//
// Created by Marthel Rodriguez on 9/18/23.
//

#ifndef SFMLTEMPLATE_APP_H
#define SFMLTEMPLATE_APP_H

#include <iostream>
#include <SFML/Graphics.hpp>


#include "Components/GUIComponent.h"

class App {
private:
    static std::vector<GUIComponent*> components;

public:
    /**
     * main
     **/
    static void addComponent(GUIComponent& component);
    static void run();
};


#endif //SFMLTEMPLATE_APP_H
