//
// Created by Marthel Rodriguez on 11/21/23.
//

#include "Images.h"

std::map<images, sf::Texture> Images::textures;
std::array<sf::Texture, 150> Images::textures3D;
std::map<TypesEnum, sf::Texture> Images::texturesTypesIcons;

Images::Images() {
    std::cout << "initializing Images constructor\n" << std::endl;
}

std::string Images::getPath(images image) {
    switch (image) {
        case LOGO:
            return "Resources/Images/logo/sfmlPokedex_logo.png";
        case BACKGROUND1:
            return "Resources/Images/pokemon-background-blue-opacity.png";
        case BACKGROUND2:
            return "Resources/Images/backgroundImages/pokemon-background-black-white.png";
        case BUTTON:
            return "Resources/Sprites/Textures/blue_button.png";

        case BOX:
            return "Resources/Sprites/Textures/grey_box.png";
        case CROSS:
            return "Resources/Sprites/Textures/red_cross.png";
        case ARROW:
            return "Resources/Sprites/Textures/grey_sliderRight.png";
        case FOLDER:
            return "Resources/Images/folder.png";
        case FILE_IMG:
            return "Resources/Images/file.png";
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
        case 14:
            return "Resources/Sprites/3DSprites/014.png";
        case 15:
            return "Resources/Sprites/3DSprites/015.png";
            ///CHECKPOINT
        case 16:
            return "Resources/Sprites/3DSprites/016.png";
        case 17:
            return "Resources/Sprites/3DSprites/017.png";
        case 18:
            return "Resources/Sprites/3DSprites/018.png";
        case 19:
            return "Resources/Sprites/3DSprites/019.png";
        case 20:
            return "Resources/Sprites/3DSprites/020.png";
        case 21:
            return "Resources/Sprites/3DSprites/021.png";
        case 22:
            return "Resources/Sprites/3DSprites/022.png";
        case 23:
            return "Resources/Sprites/3DSprites/023.png";
        case 24:
            return "Resources/Sprites/3DSprites/024.png";
        case 25:
            return "Resources/Sprites/3DSprites/025.png";
        case 26:
            return "Resources/Sprites/3DSprites/026.png";
        case 27:
            return "Resources/Sprites/3DSprites/027.png";
        case 28:
            return "Resources/Sprites/3DSprites/028.png";
            //add images from 29: 38.
        case 29:
            return "Resources/Sprites/3DSprites/029.png";
        case 30:
            return "Resources/Sprites/3DSprites/030.png";
        case 31:
            return "Resources/Sprites/3DSprites/031.png";
        case 32:
            return "Resources/Sprites/3DSprites/032.png";
        case 33:
            return "Resources/Sprites/3DSprites/033.png";
        case 34:
            return "Resources/Sprites/3DSprites/034.png";
        case 35:
            return "Resources/Sprites/3DSprites/035.png";
        case 36:
            return "Resources/Sprites/3DSprites/036.png";
        case 37:
            return "Resources/Sprites/3DSprites/037.png";
        case 38:
            return "Resources/Sprites/3DSprites/038.png";
        case 39:
            return "Resources/Sprites/3DSprites/039.png";
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

void Images::load3DTexture(int i) {
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


sf::Texture &Images::get3DImage(int i) {
    load3DTexture(i);
    return textures3D[i];
}

sf::Texture &Images::getPokemonTypeImage(TypesEnum pokemonType) {
    loadPokemonTypeTexture(pokemonType);
    return texturesTypesIcons[pokemonType];
}
