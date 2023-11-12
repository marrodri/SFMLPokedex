//
// Created by Marthel Rodriguez on 11/10/23.
//

#include "TextInput.h"
#include "../MouseEvents/MouseEvents.h"

TextInput::TextInput() {

}

TextInput::TextInput(sf::Vector2f position, sf::Vector2f size,
                     sf::Font &textInputfont, sf::Font &labelFont, std::string label):
                     multiText(position, 24, labelFont)
 {
    ///initializing textInputArea.
    textInputArea.setSize(size);
    textInputArea.setPosition(position);
    textInputArea.setFillColor(sf::Color::Black);
    textInputArea.setOutlineColor(sf::Color::White);
    textInputArea.setOutlineThickness(1);

    ///initializing label
    this->label.setLabelString(label);
    this->label.setFont(labelFont);
    this->label.setFontSize(24);
    //find a way to calculate the space between characterSize and position.
    sf::Vector2f labelPos = sf::Vector2f ({position.x, position.y - (size.y / 2) - 24});
    this->label.setPosition(labelPos);

    ///initialize multiText
    multiText.setPosition(position);
    multiText.setFont(textInputfont);
    multiText.setTextCharacterSize(24);
}

bool TextInput::isTextColiding() {
    return (multiText.getFullWidth() >= (textInputArea.getSize().x -10));
}


/**
 * Snapshot methods
 * */
void TextInput::snapshotTextString() {
    std::string newSnapshot;
    std::cout << "snapshoting new string to snapshot\n";
    for(auto letterIterator = multiText.begin(); letterIterator != multiText.end(); letterIterator++){
        std::cout << letterIterator->getChar() <<"\n";
        newSnapshot += letterIterator->getChar();
    }
    setStringSnapshot(newSnapshot);
}

void TextInput::useSnapshotText() {
    std::string snapshotedString = getStringSnapshot();
    while(!multiText.empty()){
        multiText.deleteText();
    }
    for(char letter: snapshotedString){
        multiText.pushNewLetter(letter);
    }
}


/**
 * SFML methods
 * */

void TextInput::addEventHandler(sf::RenderWindow &window, sf::Event event) {

    ///mouse event handler
    if (MouseEvents<sf::RectangleShape>::hovered(textInputArea, window))
    {
        enableState(HOVERED);
    }
    else{
        disabledState(HOVERED);
    }
    if(MouseEvents<sf::RectangleShape>::mouseClicked(window, event)){
        if(MouseEvents<sf::RectangleShape>::hovered(textInputArea, window)){
            enableState(CLICKED);
        }
        else{
            disabledState(CLICKED);
        }
    }
    ///keypress event handler
    if (event.type == sf::Event::KeyPressed && isFocused) {
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
            else if (KeyShortcuts::isSaveSnapshot(event))
            {
                snapshotTextString();
            }
            else if (KeyShortcuts::isUseSnapshot(event)){
                useSnapshotText();
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && !multiText.empty()) {
            History::pushNewAction(multiText.top().getChar(), WRITE, TEXTINPUT);
            multiText.deleteText();
        }
    } else if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)
               && !isTextColiding() && isFocused) {
        multiText.pushNewLetter(event.text.unicode);
        History::pushNewAction('\0', DELETE, TEXTINPUT);
    }
}

void TextInput::update() {
    if(checkState(HOVERED) && !checkState(CLICKED)){
        textInputArea.setFillColor(sf::Color::Blue);
    }
    else{
        textInputArea.setFillColor(sf::Color::Black);
    }
    if(checkState(CLICKED)){
        isFocused = true;
    }
    else if(!checkState(CLICKED)){
        isFocused = false;
    }
    if(isFocused){
        multiText.update();
    }
}

void TextInput::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(textInputArea);
    target.draw(label);
    target.draw(multiText);
}
