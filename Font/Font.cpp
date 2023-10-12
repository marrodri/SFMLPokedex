//
// Created by Marthel Rodriguez on 10/12/23.
//

#include "Font.h"

sf::Font Font::font;

void Font::loadFont() {
    font.loadFromFile("joystix-monospace.otf");
}

sf::Font &Font::getFont() {
    loadFont();
    return font;
}
