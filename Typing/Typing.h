//
// Created by Marthel Rodriguez on 10/24/23.
//

#ifndef SFMLTEMPLATE_TYPING_H
#define SFMLTEMPLATE_TYPING_H

#include "../Components/GUIComponent.h"
#include "../TextInput/TextInput.h"

class Typing : public GUIComponent {
//    TODO: build the typing class, that will be used for receiving
private:
    TextInput textInput;
    //undo actions.
public:
    Typing();
    //define the poll event.
    //define the multiText class.
    //and from the TypingClass it should update the multiText class.
    //once you have the correct form of implementing the content.
    //make the text input, that will write only inside boundaries.
    //also, keep with the idea of creating the text cursor when being on focus on the textInput.

    //other stuff to work on: undo for the textInput; top navBar.
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif //SFMLTEMPLATE_TYPING_H
