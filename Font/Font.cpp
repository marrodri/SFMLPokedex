//
// Created by Marthel Rodriguez on 10/12/23.
//

#include "Font.h"

std::map<fontsEnum, sf::Font> Font::fonts;

//void Font::loadFont() {
//    font.loadFromFile("OpenSans-Bold.ttf");
//}


std::string Font::getPath(fontsEnum font){
    switch(font){
        case OPEN_SANS:
            return "Resources/Fonts/OpenSans-Bold.ttf";
        case PIXEL:
            return "Resources/Fonts/pixel.ttf";
    }
}

void Font::loadFont(fontsEnum font) {
    fonts[font].loadFromFile(getPath(font));
}

sf::Font &Font::getFont(fontsEnum font) {
    loadFont(font);
    return fonts[font];
}
