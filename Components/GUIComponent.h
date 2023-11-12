//
// Created by Marthel Rodriguez on 10/12/23.
//

#ifndef SFMLTEMPLATE_GUICOMPONENT_H
#define SFMLTEMPLATE_GUICOMPONENT_H

#include "../History/HistoryNode.h"
#include "../History/History.h"
//TODO: make this an interface
#include "../Snapshot/Snapshot.h"

#include "../States/States.h"
#include <SFML/Graphics.hpp>
#include "EventHandler.h"


class GUIComponent : public sf::Drawable, public EventHandler, public States, public History, public Snapshot  {
public:
     void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;

    //from eventHandler
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override= 0;
    void update() override = 0;

    //TODO: Implement the Snapshot Interface
};

#endif //SFMLTEMPLATE_GUICOMPONENT_H
