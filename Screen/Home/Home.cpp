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
//        gridView.pushItem(AppHandler::pokemonList.getPokemonData(j + 28));
        PokemonStruct passedPok = AppHandler::pokemonList.getPokemonData(j);
        std::cout << passedPok.number << "\n";
        std::cout << passedPok.name << "\n";
        std::cout << passedPok.about << "\n";
        j++;
//        if (((j + 28)) == 38) {
//            j = 0;
//        }
        if (((j)) == 28) {
            j = 0;
        }
    }

    homeScreenContainer.setFillColor(sf::Color(0x34c0ebff));
    homeScreenContainer.setSize({710, 490});
    homeScreenContainer.setOutlineThickness(3);

    homeScreenContainer.setPosition({250, 98});


//    currPageIndex.setFont(Font::getFont());
//    currPageIndex.setCharacterSize(24);
//    currPageIndex.setString("1/10");
//    currPageIndex.setPosition({760, 552});
}

void Home::updateGridView() {
    gridView.clear();
    int j = 0;
    for (int i = 0; i < 28; i++) {

        //TODO: implement the filter here that will check the current
        //      pokemondata, if it passes the filter, push it; otherwise
        //      skip it. HINT: This is going to be much easier than expected.
        if (AppHandler::getPokemonTypeFilter1() == AppHandler::pokemonList.getPokemonData(j).types[0] || AppHandler::getPokemonTypeFilter1() == AppHandler::pokemonList.getPokemonData(j).types[1]) {
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
    if(AppHandler::getPokemonFilterHasChanged()){
        updateGridView();
        AppHandler::setPokemonFilterHasChanged(false);
    }
    gridView.update();
//    AppHandler::getPokemonTypeFilter1();
//    switch (AppHandler::getPokemonTypeFilter1()) {
//        case BUG:
//            std::cout << "pokemonType for Home:" << "BUG" << "\n";
//            break;
//        case DRAGON:
//            std::cout << "pokemonType for Home:" << "DRAGON" << "\n";
//            break;
//        case ELECTRIC:
//            std::cout << "pokemonType for Home:" << "ELECTRIC" << "\n";
//            break;
//        case FIGHTING:
//            std::cout << "pokemonType for Home:" << "FIGHTING" << "\n";
//            break;
//        case FIRE:
//            std::cout << "pokemonType for Home:" << "FIRE" << "\n";
//            break;
//        case FLYING:
//            std::cout << "pokemonType for Home:" << "FLYING" << "\n";
//            break;
//        case GHOST:
//            std::cout << "pokemonType for Home:" << "GHOST" << "\n";
//            break;
//        case GRASS:
//            std::cout << "pokemonType for Home:" << "GRASS" << "\n";
//            break;
//        case GROUND:
//            std::cout << "pokemonType for Home:" << "GROUND" << "\n";
//            break;
//        case ICE:
//            std::cout << "pokemonType for Home:" << "ICE" << "\n";
//            break;
//        case NORMAL:
//            std::cout << "pokemonType for Home:" << "NORMAL" << "\n";
//            break;
//        case POISON:
//            std::cout << "pokemonType for Home:" << "POISON" << "\n";
//            break;
//        case PSYCHIC:
//            std::cout << "pokemonType for Home:" << "PSYCHIC" << "\n";
//            break;
//        case ROCK:
//            std::cout << "pokemonType for Home:" << "ROCK" << "\n";
//            break;
//        case WATER:
//            std::cout << "pokemonType for Home:" << "WATER" << "\n";
//            break;
//        case ANOTHERTYPE:
//            std::cout << "pokemonType for Home:" << "NONE" << "\n";
//            break;

//    }

    //update for the main page.
    //update the currPageIndex;

}


