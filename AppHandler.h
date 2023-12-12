//
// Created by Marthel Rodriguez on 12/6/23.
//

#ifndef SFMLTEMPLATE_APPHANDLER_H
#define SFMLTEMPLATE_APPHANDLER_H

#include <iostream>
#include <string>
#include <SFML/Graphics/Color.hpp>
#include "Data/PokemonStruct.h"
#include "Data/PokemonList.h"

class AppHandler {
private:
    static std::string searchInput;
    /**
     * filters
     * */
    static bool pokemonFilterHasChanged;
    static TypesEnum pokemonTypeFilter1;
    static TypesEnum pokemonTypeFilter2;
    static TypesEnum pokemonWeaknessFilter1;
    static TypesEnum pokemonWeaknessFilter2;
    static TypesEnum pokemonWeaknessFilter3;

    /**
     * home page no page.
     * */
    static int currPage;
    static int pageMaxCap;

    /**
     * app configuration
     * */
    static int currentTheme;
    static int currentFontSize;
    static int currentFontFamily;
    static int currentFontColor;

    /**/
    static std::array<sf::Color, 3> backgroundColor;
    static std::array<sf::Color, 3> fileTreeBackgroundColor;
    static std::array<sf::Color, 3> subcontainersBackgroundColor;


public:
    //make this private
    static PokemonList pokemonList;

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
     static void setPokemonFilterHasChanged(bool filterHasChanged);
     static bool getPokemonFilterHasChanged();
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
    static void nextPage();

    static void prevPage();

    static int getCurrentPage();

    static void setPageMaxCap();

    static sf::Color &getBackgroundColor();

    static sf::Color &getFileTreeBackgroundColor();


};


#endif //SFMLTEMPLATE_APPHANDLER_H
