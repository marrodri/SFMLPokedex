//
// Created by Marthel Rodriguez on 11/10/23.
//

#ifndef SFMLTEMPLATE_TEXTINPUT_H
#define SFMLTEMPLATE_TEXTINPUT_H


#include "../Components/Component.h"
#include "../MultiText/MultiText.h"
#include "../Undo/Actions.h"
#include "../Undo/Undo.h"
#include "../Label/Label.h"
#include "../States/States.h"
//#include "../Snapshot/Snapshot.h"

#include <stack>
class TextInput : public Component,  public States, public Undo{
/**
 *    -textInput, this will have a box that will define the size of the input,
 *    x and y coordinates for the position. An on focus click that will focus the object when being clicked on.
 *    and the text must be centered and must not go outside of the text.
 * */

private:
    MultiText multiText;
    sf::RectangleShape textInputArea;
//    sf::Text label;
    Label label;
    bool isFocused = true;
    std::stack<Action> actionHistory;


    bool isTextColiding();
public:
    TextInput();
    TextInput(sf::Vector2f position, sf::Vector2f size, sf::Font &textInputfont, sf::Font &labelFont, std::string label);

    /**
     * methods
     * */

    /**
    * SFML methods
    **/
    void eventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SFMLTEMPLATE_TEXTINPUT_H
