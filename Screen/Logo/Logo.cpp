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
    logoContainer.setOutlineThickness(1);
    logoContainer.setOutlineColor(sf::Color::White);
    logoContainer.setPosition(10,20);
    logoContainer.setTexture(&Images::getImage(LOGO));
    logoContainer.setSize({230,60});
}

/**
 * button Interface methods
 **/
void Logo::onClick() {
    ScreenHandler::setCurrentScreen(HOME);
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
//    GUIComponent::addEventHandler(window, event);

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
        std::cout << "clicking logo button, going home\n";
        SoundFX::playClickSound();
        MouseEvents<sf::RectangleShape>::setArrow(window);
        onClick();
    }
}

void Logo::update() {
//    GUIComponent::update();
}
