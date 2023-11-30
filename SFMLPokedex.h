//
// Created by Marthel Rodriguez on 11/29/23.
//

#ifndef SFMLTEMPLATE_SFMLPOKEDEX_H
#define SFMLTEMPLATE_SFMLPOKEDEX_H


#include "Data/PokemonList.h"

class SFMLPokedex {
private:
    static int currentPage;
    static int maxPage;
public:

    /**
     * pageMethods
     * */

    /**
     * pokemonListMethods
     **/
    static PokemonList pokemonList;
};


#endif //SFMLTEMPLATE_SFMLPOKEDEX_H
