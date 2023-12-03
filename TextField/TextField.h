//
// Created by Marthel Rodriguez on 12/2/23.
//

#ifndef SFMLTEMPLATE_TEXTFIELD_H
#define SFMLTEMPLATE_TEXTFIELD_H


#include "../MultiText/MultiText.h"
#include "../Container/Container.h"

//dimensions of the description.
//pos: 470*150 (try with 490*150, it has to be lower)
//size: 450, 200.
class TextField : public  GUIComponent{
private:
    //ui
    Container container;
    sf::Font font;
    sf::Color color;
    //data and logic objects
    MultiText multiText;
    std::stack<HistoryNode> actionHistory;
//    bool isFocused = false;
    ///check the length of the current array item
    ///and see if it has reached the border. if it does
    ///create a new array that increments the y padding.
    bool hasTextColided();

    ///returns true, when the current array has no characters
    ///in the list. when being true and backspace pressed,
    /// then delete the current array item.
    bool isLineEmpty();

public:
    /// TODO
    ///  multiText must be in the form of textField.
    ///  Or it should just have the option of going down.
    ///  when the textField checks that the currentLine has ra
    ///  reached its end of the line, then create another line to go down.
    ///  to make this work, an array of List<Letter> could do the trick.
    ///  array index for the y padding, list<Letter> for the x padding.
    ///  when pressing back to an empty list, will delete the current list
    ///  from the array, and cursor will be placed at the end of the  list
    ///  of the current last array item.
    TextField();
    TextField(const std::string &initStr);

    bool isTextColiding();


    //TODO: this is going to be needed for the global config.
    void setFont(sf::Font &font);
    void setColor(sf::Color &color);
    void setCharacterSize(int characterSize);

    //TODO: nedded for showing the transparent background.
    void setAlpha(int alpha);
    void setText(const std::string &str);
    void clear();

    /**
     * GUI
     * */

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;
};


#endif //SFMLTEMPLATE_TEXTFIELD_H
