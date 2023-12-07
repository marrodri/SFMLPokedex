//
// Created by Marthel Rodriguez on 11/23/23.
//

#include "Logo.h"
#include "../../Images/Images.h"
#include "../../SoundFX/SoundFX.h"
#include "../../MouseEvents/MouseEvents.h"
#include "../ScreenHandler.h"

///perfect initializer for the logo container.
Logo::Logo() {
    logoContainer.setSize({230,80});
    logoContainer.setPosition(10,35);
    logoContainer.setTexture(&Images::getImage(LOGO));
    logoContainer.setSize({230,60});
}

/**
 * menuItem Interface methods
 **/
void Logo::onClick() {
    ScreenHandler::setCurrentScreen(HOME);
    ScreenHandler::toggleOffPokemonScreenElements();
}

void Logo::setOnClickFunction() {

}

void Logo::onHoverSound() {

}

void Logo::onClickSound() {

}


/**
 * GUI Component methods
 * */

void Logo::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(logoContainer);
}

void Logo::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents<sf::RectangleShape>::hovered(logoContainer,window)) {
        if (!checkState(HOVERED)) {
            SoundFX::playHoverSound();
            MouseEvents<sf::RectangleShape>::setHand(window);
        }
        enableState(HOVERED);
    }
    else {
        if(checkState(HOVERED)){
            MouseEvents<sf::RectangleShape>::setArrow(window);
        }
        disabledState(HOVERED);
    }
    if (MouseEvents<sf::RectangleShape>::mouseClicked(logoContainer, window)) {
        std::cout << "clicking logo menuItem, going home\n";
        SoundFX::playClickSound();
        MouseEvents<sf::RectangleShape>::setArrow(window);
        onClick();
    }
}

void Logo::update() {
//    GUIComponent::update();
}
