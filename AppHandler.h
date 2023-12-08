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

    static TypesEnum pokemonTypeFilter1;
    static TypesEnum pokemonTypeFilter2;
    static TypesEnum pokemonWeaknessFilter1;
    static TypesEnum pokemonWeaknessFilter2;
    static TypesEnum pokemonWeaknessFilter3;




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
    void setPokemonTypeFilter1();
    void setPokemonTypeFilter2();
    void setPokemonWeaknessFilter1();
    void setPokemonWeaknessFilter2();
    void setPokemonWeaknessFilter3();





    TypesEnum getPokemonTypeFilter1();
    TypesEnum getPokemonTypeFilter2();
    TypesEnum getPokemonWeaknessFilter1();
    TypesEnum getPokemonWeaknessFilter2();
    TypesEnum getPokemonWeaknessFilter3();


    /**
     * fileTree configuration.
     **/

};


#endif //SFMLTEMPLATE_APPHANDLER_H
