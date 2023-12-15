//
// Created by Marthel Rodriguez on 11/21/23.
//

#ifndef SFMLTEMPLATE_HOME_H
#define SFMLTEMPLATE_HOME_H

#include "../../Components/GUIComponent.h"
#include "./Views/GridView.h"
#include "../../Container/Container.h"
//#include "MainScreenButton/MainScreenButton.h"

class Home: public GUIComponent{
private:
    GridView gridView;
    Container homeScreenContainer;

public:
    Home();

    bool checkFilter(int j);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

    void updateGridView();
};


#endif //SFMLTEMPLATE_HOME_H
