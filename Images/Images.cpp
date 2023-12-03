//
// Created by Marthel Rodriguez on 11/21/23.
//

#include "Images.h"

std::map<images, sf::Texture> Images::textures;
std::array<sf::Texture,150> Images::textures3D;
std::map<TypesEnum, sf::Texture> Images::texturesTypesIcons;

Images::Images() {
    std::cout << "initializing Images constructor\n"<< std::endl;
}

std::string Images::getPath(images image) {
    switch (image) {
        case LOGO:
            return "Resources/Images/logo/sfmlPokedex_logo.png";
        case BACKGROUND1:
            return "Resources/Images/pokemon-background-blue-opacity.png";
        case BUTTON:
            return "Resources/Sprites/Textures/blue_button.png";
        case BACKGROUND3:
            return "";
        case BOX:
            return "Resources/Sprites/Textures/grey_box.png";
        case CROSS:
            return "Resources/Sprites/Textures/red_cross.png";
        case ARROW:
            return "Resources/Sprites/Textures/grey_sliderRight.png";
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
        case 13:
            return "Resources/Sprites/3DSprites/013.png";
    }
    return "";
}

std::string Images::getPokemonTypePath(TypesEnum pokemonType) {
    switch (pokemonType) {
        case BUG:
            return "Resources/Sprites/types/BugIC_FRLG.png";
        case DRAGON:
            return "Resources/Sprites/types/DragonIC_FRLG.png";
        case ELECTRIC:
            return "Resources/Sprites/types/ElectricIC_FRLG.png";
        case FIGHTING:
            return "Resources/Sprites/types/FightingIC_FRLG.png";
        case FIRE:
            return "Resources/Sprites/types/FireIC_FRLG.png";
        case FLYING:
            return "Resources/Sprites/types/FlyingIC_FRLG.png";
        case GHOST:
            return "Resources/Sprites/types/GhostIC_FRLG.png";
        case GRASS:
            return "Resources/Sprites/types/GrassIC_FRLG.png";
        case GROUND:
            return "Resources/Sprites/types/GroundIC_FRLG.png";
        case ICE:
            return "Resources/Sprites/types/IceIC_FRLG.png";
        case NORMAL:
            return "Resources/Sprites/types/NormalIC_FRLG.png";
        case POISON:
            return "Resources/Sprites/types/PoisonIC_FRLG.png";
        case PSYCHIC:
            return "Resources/Sprites/types/PsychicIC_FRLG.png";
        case ROCK:
            return "Resources/Sprites/types/RockIC_FRLG.png";
        case WATER:
            return "Resources/Sprites/types/WaterIC_FRLG.png";
        case ANOTHERTYPE:
            return "";

    }
    return "";
}

/*
 * loaders
 * */

void Images::load(images image) {
    textures[image].loadFromFile(getPath(image));
}

void Images::load3DTexture(int i){
    textures3D[i].loadFromFile(get3DPokemonPath(i));
}

void Images::loadPokemonTypeTexture(TypesEnum pokemonType) {
    texturesTypesIcons[pokemonType].loadFromFile(getPokemonTypePath(pokemonType));
}


/**
 * getters
 * */
const sf::Texture &Images::getImage(images image) {
    load(image);
    return textures[image];
}


sf::Texture &Images::get3DImage(int i){
    load3DTexture(i);
    return textures3D[i];
}

sf::Texture &Images::getPokemonTypeImage(TypesEnum pokemonType) {
    loadPokemonTypeTexture(pokemonType);
    return texturesTypesIcons[pokemonType];
}
