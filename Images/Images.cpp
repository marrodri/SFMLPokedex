//
// Created by Marthel Rodriguez on 11/21/23.
//

#include "Images.h"

std::map<images, sf::Texture> Images::textures;
std::array<sf::Texture,150> Images::textures3D;

std::string Images::getPath(images image) {
//    return std::__cxx11::string();
    switch (image) {
        case BACKGROUND1:
            return "Resources/Images/pokemon-background-blue-opacity.png";
        case BACKGROUND2:
            return "";
        case BACKGROUND3:
            return "";
        case POKEMONSPRITE1:
            break;
        case POKEMONSPRITE2:
            break;
    }
    return "";
}


//for the 3d, you will create an array of paths.

std::string Images::get3DPokemonPath(int i) {
//    return "Resources/Sprites/3DSprites/001.png";
    return "Resources/Sprites/3DSprites/061.png";
}

void Images::load(images image) {
    textures[image].loadFromFile(getPath(image));
}

void Images::load3DTexture(int i){
    textures3D[i].loadFromFile(get3DPokemonPath(i));
}


sf::Texture &Images::getImage(images image) {
    load(image);
    return textures[image];
}


sf::Texture &Images::get3DImage(int i){
    load3DTexture(i);
    return textures3D[i];

}