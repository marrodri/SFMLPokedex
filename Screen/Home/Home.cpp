//
// Created by Marthel Rodriguez on 11/21/23.
//

#include "Home.h"
#include "../../Font/Font.h"
#include "../../SFMLPokedex.h"

Home::Home(): gridView(sf::Vector2f (250, 100)) {
    int j=0;

    for (int i =0; i<28; i++) {
        //TODO: implement the filter here that will check the current
        //      pokemondata, if it passes the filter, push it; otherwise
        //      skip it. HINT: This is going to be much easier than expected.
        gridView.pushItem(SFMLPokedex::pokemonList.getPokemonData(j+28));
        PokemonStruct passedPok = SFMLPokedex::pokemonList.getPokemonData(j);
        std::cout << passedPok.number << "\n";
        std::cout << passedPok.name << "\n";
        std::cout << passedPok.about << "\n";
        j++;
        if (((j+28))==38) {
            j=0;
        }
    }

    homeScreenContainer.setFillColor(sf::Color::Black);
    homeScreenContainer.setPosition({247, 100});
    homeScreenContainer.setSize({699, 490});

//    currPageIndex.setFont(Font::getFont());
//    currPageIndex.setCharacterSize(24);
//    currPageIndex.setString("1/10");
//    currPageIndex.setPosition({760, 552});
}

void Home::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(homeScreenContainer);
    target.draw(gridView);
}

void Home::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    gridView.addEventHandler(window, event);
}

void Home::update() {
    gridView.update();

    //update for the main page.
    //update the currPageIndex;
}


