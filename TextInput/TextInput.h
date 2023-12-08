//
// Created by Marthel Rodriguez on 11/10/23.
//

#ifndef SFMLTEMPLATE_TEXTINPUT_H
#define SFMLTEMPLATE_TEXTINPUT_H


#include "../Components/GUIComponent.h"
#include "../MultiText/MultiText.h"
#include "../Label/Label.h"
#include "../KeyShortcuts/KeyShortcuts.h"
#include "../Container/Container.h"
//#include "../History/Actions.h"
//#include "../History/History.h"
//#include "../Snapshot/Snapshot.h"

#include <stack>
class TextInput : public GUIComponent {
/**
 *    -textInput, this will have a box that will define the size of the input,
 *    x and y coordinates for the position. An on focus click that will focus the object when being clicked on.
 *    and the dropdownItemText must be centered and must not go outside of the dropdownItemText.
 * */

private:
    MultiText multiText;
//    sf::RectangleShape textInputArea;
    Container container;
    Label label;
//    bool isFocused = true;
    std::stack<HistoryNode> actionHistory;
    bool isTextColiding();
public:
    TextInput();
    TextInput(sf::Vector2f position, sf::Vector2f size, sf::Font &textInputfont, sf::Font &labelFont, std::string label);


    /**
     * getters
     * */
     const std::string &getInput();
    /**
     * snapshot methods
     * */
    void snapshotTextString();
    void useSnapshotText();
    /**
    * SFML methods
    **/
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

    bool isFocused();

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SFMLTEMPLATE_TEXTINPUT_H
