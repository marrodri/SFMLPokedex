//
// Created by Marthel Rodriguez on 12/6/23.
//

#ifndef SFMLTEMPLATE_APPHANDLER_H
#define SFMLTEMPLATE_APPHANDLER_H

#include <iostream>
#include <string>
#include "Data/PokemonStruct.h"

class AppHandler {
private:
    static std::string searchInput;

    /**
     * filters
     * */
    static TypesEnum pokemonTypeFilter1;
    static TypesEnum pokemonTypeFilter2;
    static TypesEnum pokemonWeaknessFilter1;
    static TypesEnum pokemonWeaknessFilter2;
    static TypesEnum pokemonWeaknessFilter3;

    /**
     * home page no page.
     * */
     static int currPage;
     static int pageMaxCap();
     static int listOfPokemons;



public:
    /**
     * searchInput methods
     **/
    static void updateSearchInput(const std::string &input);

    static std::string getSearchInput();


    /**
     * menu bar configuration.
     **/
    static void closeProgram();

    static void openFileTree();

    static void changeBackground();

    static void changeFontFamily();

    static void changeFontColor();

    /**
     * filter configuration
     * */
    static void setPokemonTypeFilter1(TypesEnum pokemonType);

    static void setPokemonTypeFilter2(TypesEnum pokemonType);

    static void setPokemonWeaknessFilter1(TypesEnum pokemonType);

    static void setPokemonWeaknessFilter2(TypesEnum pokemonType);

    static void setPokemonWeaknessFilter3(TypesEnum pokemonType);


    static TypesEnum getPokemonTypeFilter1();
    static TypesEnum getPokemonTypeFilter2();
    static TypesEnum getPokemonWeaknessFilter1();
    static TypesEnum getPokemonWeaknessFilter2();
    static TypesEnum getPokemonWeaknessFilter3();


    /**
     * fileTree configuration.
     **/

    /**
     * home page;
     * */
     void nextPage();
     void prevPage();
     int getCurrentPage();
     void setPageMaxCap();

};


#endif //SFMLTEMPLATE_APPHANDLER_H
