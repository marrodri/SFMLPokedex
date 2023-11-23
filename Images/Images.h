//
// Created by Marthel Rodriguez on 11/21/23.
//

#ifndef SFMLTEMPLATE_IMAGES_H
#define SFMLTEMPLATE_IMAGES_H

#include <map>
#include <SFML/Graphics.hpp>


enum images
{
    BACKGROUND1, BACKGROUND2, BACKGROUND3, POKEMONSPRITE1, POKEMONSPRITE2
};
class Images {
    static std::map<images, sf::Texture> textures;
    static std::array<sf::Texture,150> textures3D;

    static std::string getPath(images image);

    static std::string get3DPokemonPath(int i);

    static void load(images image);
    static void load3DTexture(int i);

public:
    static sf::Texture &getImage(images image);
    static sf::Texture &get3DImage(int i);

};


#endif //SFMLTEMPLATE_IMAGES_H
