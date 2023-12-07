//
// Created by Marthel Rodriguez on 11/29/23.
//

#ifndef SFMLTEMPLATE_TEXT_H
#define SFMLTEMPLATE_TEXT_H

#include "../Components/GUIComponent.h"

class Text: public GUIComponent {
private:
    sf::Text text;
public:
    Text();

    Text(const std::string &str, int fontSize,  sf::Font &font,sf::Vector2f pos);
    Text(const std::string &str, int fontSize, const sf::Color &color, sf::Font &font, sf::Vector2f pos);
    /**
     * setters
     **/
    void setFont(sf::Font &font);
    void setOrigin(sf::Vector2f &origin);
    void setPosition(const sf::Vector2f &pos);
    void setString(const std::string &str);

    /**
     * getters
     * */
    sf::FloatRect getLocalBounds() const;
    sf::FloatRect getGlobalBounds() const;
    sf::Vector2f getPosition();
    const std::string &getString();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

    void setColor(const sf::Color &color);
};


#endif //SFMLTEMPLATE_TEXT_H
