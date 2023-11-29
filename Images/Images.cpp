//
// Created by Marthel Rodriguez on 11/21/23.
//

#include "Images.h"

std::map<images, sf::Texture> Images::textures;
std::array<sf::Texture,150> Images::textures3D;


Images::Images() {
    std::cout << "initializing Images constructor\n"<< std::endl;
}

std::string Images::getPath(images image) {
    switch (image) {
        case LOGO:
            return "Resources/Images/logo/sfmlPokedex_logo.png";
        case BACKGROUND1:
            return "Resourcexs/Images/pokemon-background-blue-opacity.png";
        case BACKGROUND2:
            return "";
        case BACKGROUND3:
            return "";
    }
    return "";
}


//for the 3d, you will create an array of paths.
//TODO: update the stub function
std::string Images::get3DPokemonPath(int pokemonNo) {
    switch (pokemonNo) {
        case 1:
            return "Resources/Sprites/3DSprites/001.png";
        case 2:
            return "Resources/Sprites/3DSprites/002.png";
        case 3:
            return "Resources/Sprites/3DSprites/003.png";
        case 4:
            return "Resources/Sprites/3DSprites/004.png";
        case 5:
            return "Resources/Sprites/3DSprites/005.png";
        case 6:
            return "Resources/Sprites/3DSprites/006.png";
        case 7:
            return "Resources/Sprites/3DSprites/007.png";
        case 8:
            return "Resources/Sprites/3DSprites/008.png";
        case 9:
            return "Resources/Sprites/3DSprites/009.png";
        case 10:
            return "Resources/Sprites/3DSprites/010.png";
        case 11:
            return "Resources/Sprites/3DSprites/011.png";
        case 12:
            return "Resources/Sprites/3DSprites/012.png";
    }
    return "";
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