//
// Created by Marthel Rodriguez on 11/10/23.
//

#include "TextInput.h"
#include "../MouseEvents/MouseEvents.h"
#include "../Font/Font.h"

TextInput::TextInput() {

}

TextInput::TextInput(sf::Vector2f position, sf::Vector2f size,
                     sf::Font &textInputfont, sf::Font &labelFont, std::string label):
                     multiText(position, 24, labelFont),
                     container(position, size, sf::Color::White)
 {
    ///initializing textInputArea.
    container.setOutlineColor(sf::Color::Black);
    container.setOutlineThickness(3);

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
    return (multiText.getFullWidth() >= (container.getSize().x -10));
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
    if (MouseEvents<Container>::hovered(container, window))
    {
        enableState(HOVERED);
    }
    else{
        disabledState(HOVERED);
    }
    if(MouseEvents<sf::RectangleShape>::mouseClicked(window, event)){
        if(MouseEvents<Container>::hovered(container, window)){
            enableState(CLICKED);
        }
        else{
            disabledState(CLICKED);
        }
    }
    ///keypress event handler
    if (event.type == sf::Event::KeyPressed && isFocused) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)
        ) {
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
        //when deleting a character,
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && !multiText.empty()) {
            History::pushNewAction(multiText.top().getChar(), WRITE, TEXTINPUT);
            multiText.deleteText();
            //when using backspace, store the write function with the most recent character to write it back.
        }
    } else if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)
               && !isTextColiding() && isFocused) {
        //when writing characters, store the delete function to history.
        multiText.pushNewLetter(event.text.unicode);
        History::pushNewAction('\0', DELETE, TEXTINPUT);
    }
}

void TextInput::update() {
    if(checkState(HOVERED) && !checkState(CLICKED)){
        //add a lower grey color when being hovered.
        container.setFillColor(sf::Color(0xdcdcdeff));
    }
    else{
        container.setFillColor(sf::Color::White);
    }
    if(checkState(CLICKED)){
        isFocused = true;
        multiText.setOnFocus(true);
    }
    else if(!checkState(CLICKED)){
        isFocused = false;
        multiText.setOnFocus(false);
    }
    if(isFocused){
        multiText.update();
    }
}

void TextInput::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    container.draw(target, states);
    target.draw(label);
    target.draw(multiText);
}
