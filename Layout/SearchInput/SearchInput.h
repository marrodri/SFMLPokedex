//
// Created by Marthel Rodriguez on 11/21/23.
//

#ifndef SFMLTEMPLATE_SEARCHINPUT_H
#define SFMLTEMPLATE_SEARCHINPUT_H

#include "../../Components/GUIComponent.h"
class SearchInput :public GUIComponent {
private:
    sf::RectangleShape textInput;
    sf::Text placeholder;
    //try to create the cursor move back and forth.
    //    TextInput class.
public:
    SearchInput();

    /**
     * methods
     * */
    //this will be used for fetching the existing pokemon,
    //in the binary tree.
    std::string &getCurrentInput();


    /**
     * GUI methods
     * */
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;


};


#endif //SFMLTEMPLATE_SEARCHINPUT_H
