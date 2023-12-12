//
// Created by Marthel Rodriguez on 12/2/23.
//


#include "TextField.h"
#include "../Font/Font.h"
#include "../MouseEvents/MouseEvents.h"
#include "../KeyShortcuts/KeyShortcuts.h"

//pos: 470*150 (try with 490*150, it has to be lower)
//size: 450, 200.
//constructor params 20, Font::getFont(), {250, 300}
TextField::TextField(const std::string &initStr) : container({470, 185}, {450, 165}, sf::Color(0x223573ff)),
                                                   multiText(initStr,{470, 185},{450, 165}, 12, Font::getFont(OPEN_SANS)) {
    /**
     * pass the pos where it shall be initial pos
     **/
     ///TODO: create a static class that fetches the color
     ///     for the textField description. Where that
     ///     static class setting, can be changed from the
     ///     menuBar. This is anothe global class for the config.
    multiText.setColor(sf::Color::White);

}


/**
 * methods
 **/
void TextField::setText(const std::string &str) {
    ///   TODO: call the setText from the MultiText.
    ///         in it, it will check for \n for adding new lines
    ///         and check if the current line has collided for
    ///         adding a new line.
    clear();
    for(auto letter:str){
        multiText.pushNewLetter(letter);
    }
}


/***
 * GUI Methods
 * */

void TextField::draw(sf::RenderTarget &target, sf::RenderStates states) const {
//    GUIComponent::draw(target, states);
    container.draw(target, states);
    multiText.draw(target, states);
}


void TextField::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents<Container>::hovered(container, window)) {
        if (MouseEvents<Container>::mouseClicked(container, window)) {
            States::enableState(FOCUSED);
            multiText.setOnFocus(true);
        }
    }
    if(States::checkState(FOCUSED)){
        multiText.addEventHandler(window, event);
        if (event.type == sf::Event::KeyPressed) {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)
                    ){
                if (KeyShortcuts::isUndo(event) && !History::empty()){
                    HistoryNode prevAction = History::undoAction();
                    switch(prevAction.action){
                        case WRITE:
                            multiText.pushNewLetter(prevAction.letter);
                            break;
                        case DELETE:
                            multiText.deleteText();
                            break;
                    }
                }
//                else if (KeyShortcuts::isSaveSnapshot(event))
//                {
//                    snapshotTextString();
//                }
//                else if (KeyShortcuts::isUseSnapshot(event)){
//                    useSnapshotText();
//                }
            }
                //when deleting a character,
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && !multiText.empty()) {
                History::pushNewAction(multiText.top().getChar(), WRITE, TEXTINPUT);
                multiText.deleteText();
                //when using backspace, store the write function with the most recent character to write it back.
            }
        } else if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)
                   ) {
            //when writing characters, store the delete function to history.
            if(isTextColiding()){
                multiText.pushNewLine();
            }
            multiText.pushNewLetter(event.text.unicode);
            History::pushNewAction('\0', DELETE, TEXTINPUT);
        }
    }


    ///bring the mouseEvents handler
}

void TextField::update() {
    if(States::checkState(FOCUSED)) {
        multiText.update();
    }
}

TextField::TextField() {

}

bool TextField::isTextColiding() {
     return (multiText.getFullWidth() >= (container.getSize().x -10));;
}

void TextField::clear() {
    while(!multiText.empty()){
        multiText.deleteText();
    }


}

std::string &TextField::getString() {
    return multiText.getString();
}





