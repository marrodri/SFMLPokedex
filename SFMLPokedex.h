//
// Created by Marthel Rodriguez on 11/29/23.
//

#ifndef SFMLTEMPLATE_SFMLPOKEDEX_H
#define SFMLTEMPLATE_SFMLPOKEDEX_H


#include "Data/PokemonList.h"

enum screenEnum{MAINMENU, POKEMON};
enum pokemonScreenEnum{PAGE1, PAGE2};
class SFMLPokedex {
private:
    static int currentPage;
    static int maxPage;
    static screenEnum currScreen;
    static pokemonScreenEnum currPokemonScreen;

public:
    /**
     * pageMethods
     **/


    /**
     * pokemonListMethods
     **/
    static PokemonList pokemonList;
};

//screenshot of a pokemon document, where you can edit the types.


#endif //SFMLTEMPLATE_SFMLPOKEDEX_H
