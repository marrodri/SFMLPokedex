//
// Created by Marthel Rodriguez on 11/21/23.
//

#ifndef SFMLTEMPLATE_IMAGES_H
#define SFMLTEMPLATE_IMAGES_H

#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Data/PokemonStruct.h"


enum images
{
    LOGO, BACKGROUND1, BACKGROUND2, BACKGROUND3, BUTTON, BOX, CROSS, ARROW, FOLDER, FILE_IMG
};


class Images {
private:
    static std::map<images, sf::Texture> textures;
    static std::map<TypesEnum, sf::Texture> texturesTypesIcons;
    static std::array<sf::Texture,150> textures3D;

    static std::string getPath(images image);

    static std::string get3DPokemonPath(int i);

    static std::string getPokemonTypePath(TypesEnum pokemonType);

    static void load(images image);
    static void load3DTexture(int i);
    static void loadPokemonTypeTexture(TypesEnum pokemonType);

public:
    Images();

    static  const sf::Texture &getImage(images image);
    static sf::Texture &get3DImage(int i);
    static sf::Texture &getPokemonTypeImage(TypesEnum pokemonType);

};


#endif //SFMLTEMPLATE_IMAGES_H
