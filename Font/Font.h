//
// Created by Marthel Rodriguez on 10/12/23.
//

#ifndef SFMLTEMPLATE_FONT_H
#define SFMLTEMPLATE_FONT_H


#include <SFML/Graphics/Font.hpp>

enum fontsEnum{
    OPEN_SANS, PIXEL
};

class Font {
private:
    static std::map<fontsEnum, sf::Font> fonts;
    static void loadFont(fontsEnum font);
    static std::string getPath(fontsEnum font);

public:
    static sf::Font &getFont(fontsEnum font);
};


#endif //SFMLTEMPLATE_FONT_H
