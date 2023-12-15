//
// Created by Marthel Rodriguez on 11/21/23.
//

#include "Home.h"
#include "../../Font/Font.h"

#include "../../AppHandler.h"

Home::Home() : gridView(sf::Vector2f(250, 100)) {
    int j = 0;
    ///TODO: move this logic to another function.
    ///that will always be on update for the filters.
    for (int i = 0; i < 28; i++) {
        //TODO: implement the filter here that will check the current
        //      pokemondata, if it passes the filter, push it; otherwise
        //      skip it. HINT: This is going to be much easier than expected.
        gridView.pushItem(AppHandler::pokemonList.getPokemonData(j));
        PokemonStruct passedPok = AppHandler::pokemonList.getPokemonData(j);
        std::cout << passedPok.number << "\n";
        std::cout << passedPok.name << "\n";
        std::cout << passedPok.about << "\n";
        j++;
        if (((j)) == 28) {
            j = 0;
        }
    }

    homeScreenContainer.setFillColor(sf::Color(0x34c0ebff));
    homeScreenContainer.setSize({710, 490});
    homeScreenContainer.setOutlineThickness(3);

    homeScreenContainer.setPosition({250, 98});

///TODO: build the page index.
//    currPageIndex.setFont(Font::getFont());
//    currPageIndex.setCharacterSize(24);
//    currPageIndex.setString("1/10");
//    currPageIndex.setPosition({760, 552});
}

bool Home::checkFilter(int j) {
    if (AppHandler::getPokemonTypeFilter1() == AppHandler::pokemonList.getPokemonData(j).types[0] ||
        AppHandler::getPokemonTypeFilter1() == AppHandler::pokemonList.getPokemonData(j).types[1]) {
        return true;
    }
    if (AppHandler::getPokemonTypeFilter2() == AppHandler::pokemonList.getPokemonData(j).types[0] ||
        AppHandler::getPokemonTypeFilter2() == AppHandler::pokemonList.getPokemonData(j).types[1]) {
        return true;
    }
    if (AppHandler::getPokemonWeaknessFilter1() == AppHandler::pokemonList.getPokemonData(j).weaknesses[0] ||
        AppHandler::getPokemonWeaknessFilter1() == AppHandler::pokemonList.getPokemonData(j).weaknesses[1] ||
        AppHandler::getPokemonWeaknessFilter1() == AppHandler::pokemonList.getPokemonData(j).weaknesses[2]) {
        return true;
    }
    if (AppHandler::getPokemonWeaknessFilter2() == AppHandler::pokemonList.getPokemonData(j).weaknesses[0] ||
        AppHandler::getPokemonWeaknessFilter2() == AppHandler::pokemonList.getPokemonData(j).weaknesses[1] ||
        AppHandler::getPokemonWeaknessFilter2() == AppHandler::pokemonList.getPokemonData(j).weaknesses[2]) {
        return true;
    }
    return false;
}

void Home::updateGridView() {
    gridView.clear();
    int j = 0;
    for (int i = 0; i < 28; i++) {

        //TODO: implement the filter here that will check the current
        //      pokemondata, if it passes the filter, push it; otherwise
        //      skip it. HINT: This is going to be much easier than expected.
        if (checkFilter(j)) {
            gridView.pushItem(AppHandler::pokemonList.getPokemonData(j));
        }
        PokemonStruct passedPok = AppHandler::pokemonList.getPokemonData(j);
        std::cout << passedPok.number << "\n";
        std::cout << passedPok.name << "\n";
        std::cout << passedPok.about << "\n";
        j++;
    }


}

void Home::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(homeScreenContainer);
    target.draw(gridView);
}

void Home::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    gridView.addEventHandler(window, event);
}

void Home::update() {
    if (AppHandler::getPokemonFilterHasChanged()) {
        updateGridView();
        AppHandler::setPokemonFilterHasChanged(false);
    }
    gridView.update();
    //update for the main page.
    //update the currPageIndex;

}




