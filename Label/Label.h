//
// Created by Marthel Rodriguez on 11/11/23.
//

#ifndef SFMLTEMPLATE_LABEL_H
#define SFMLTEMPLATE_LABEL_H

#include "../Components/GUIComponent.h"

class Label : public GUIComponent {
private:
    sf::Text label;
    std::string labelString;
public:
    Label();
    Label(std::string &labelString, sf::Vector2f position, int fontSize, sf::Font &font);

    /**
     * setters
     **/
    void setLabelString(std::string &labelString);
    void setPosition(sf::Vector2f position);
    void setFontSize(int fontSize);
    void setFont(sf::Font &font);

    /**
     * getters
     * */
     std::string getLabelString();

    /**
     * snapshot
     * */

    /**
     * SFML Methods
     * */
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SFMLTEMPLATE_LABEL_H
