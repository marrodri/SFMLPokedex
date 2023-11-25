//
// Created by Marthel Rodriguez on 11/22/23.
//

#include "GridView.h"
#include "../../../Font/Font.h"

/**
 * constructors
 * */
GridView::GridView() {

}

GridView::GridView(sf::Vector2f pos) :position(pos){

}

/**
 * methods
 * */

///private method
GridButton *GridView::createNewGridButton(int i) {
    GridButton *newGridButton = new GridButton(Font::getFont(), position, 1);
    if(listOfGridButtons.empty()){
        newGridButton->setPosition(position);
    }
    else{
        sf::Vector2f size = listOfGridButtons.back()->getSize();
        sf::Vector2f pos = listOfGridButtons.back()->getPosition();

        if (listOfGridButtons.size() % 8 == 0)
        {
            //increment it's y coordinate.
            newGridButton->setPosition({position.x, pos.y + size.y+2});
        }
        else{
            //increment the x coordinate.
            newGridButton->setPosition({pos.x + size.x+2, pos.y});
        }

    }
    return newGridButton;
}

void GridView::pushItem(int i) {
    listOfGridButtons.push_back(createNewGridButton(i));
}


/**
 * gui methods
 * */
void GridView::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(GridButton *gridButton: listOfGridButtons){
        gridButton->draw(target, states);
    }
}

void GridView::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    for(GridButton *gridButton: listOfGridButtons){
        gridButton->addEventHandler(window, event);
    }
}

void GridView::update() {
    for(GridButton *gridButton: listOfGridButtons){
        gridButton->update();
    }
}
