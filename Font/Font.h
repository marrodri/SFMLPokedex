//
// Created by Marthel Rodriguez on 10/12/23.
//

#ifndef SFMLTEMPLATE_FONT_H
#define SFMLTEMPLATE_FONT_H


#include <SFML/Graphics/Font.hpp>

class Font {
private:
    static sf::Font font;
    static void loadFont();

public:
    static sf::Font &getFont();
};


#endif //SFMLTEMPLATE_FONT_H
