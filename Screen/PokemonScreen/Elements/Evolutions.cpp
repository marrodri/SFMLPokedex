//
// Created by Marthel Rodriguez on 11/30/23.
//

#include "Evolutions.h"
#include "../../../Font/Font.h"
#include "../../../Helper/HelperFunctions.h"
#include "../../../Images/Images.h"
#include "../../ScreenHandler.h"
#include "../../../SFMLPokedex.h"

Evolutions::Evolutions() :
        container({260, 360}, {450, 160}, sf::Color(0x81e67cff)),
        placeholder("Evolutions", 25, Font::getFont(), {250, 100}) {
    HelperFunctions::centerItem(container, placeholder);
}

//TODO: reupdate this firstEval.
Evolutions::Evolutions(const std::array<int, 3> &evolutions, int cols) :
        placeholder("Evolutions:", 25, Font::getFont(), {250, 100}),
        container({260, 360}, {450, 160}, sf::Color(0x81e67cff)),
        firstArrow({}, {40, 40}, sf::Color::White),
        secondArrow({}, {40, 40}, sf::Color::White),
        firstEvol(Images::get3DImage(evolutions[0]), 1, cols),
        secEvol(Images::get3DImage(evolutions[0]), 1, cols),
        finalEvol(Images::get3DImage(evolutions[0]), 1, cols) {
    firstEvol.setTime(50);
    secEvol.setTime(50);
    finalEvol.setTime(50);

    firstArrow.setTexture(Images::getImage(ARROW));
    secondArrow.setTexture(Images::getImage(ARROW));

    //title
    HelperFunctions::positionItemByBounds(container, placeholder, {80, 20});

    ///first evol
    HelperFunctions::centerItemHorizontally(container, firstEvol, 50);
    HelperFunctions::positionItemByBounds(container, firstArrow, {120, 70});

    ///second evol
    HelperFunctions::centerItem(container, secEvol);

    ///third evol
    HelperFunctions::positionItemByBounds(container, secondArrow, {290, 70});
    HelperFunctions::centerItemHorizontally(container, finalEvol, 380);


}

void Evolutions::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    container.draw(target, states);
    placeholder.draw(target, states);
    firstEvol.draw(target, states);
    secEvol.draw(target, states);
    finalEvol.draw(target, states);
    firstArrow.draw(target, states);
    secondArrow.draw(target, states);
}

void Evolutions::addEventHandler(sf::RenderWindow &window, sf::Event event) {
}

void Evolutions::update() {
    if (!ScreenHandler::getPokemonScreenElementLoaded(EVOLUTIONS)) {
        //init the data for the animation.
        pokemonData = ScreenHandler::getSelectedPokemonData();

        std::cout << "firstEvol " << pokemonData.evolutions[0] << "cols: "
                  << SFMLPokedex::pokemonList.getPokemonData(pokemonData.evolutions[0]).cols << "\n";
        std::cout << "secondEvol " << pokemonData.evolutions[1] << "cols: "
                  << SFMLPokedex::pokemonList.getPokemonData(pokemonData.evolutions[1]).cols << "\n";
        std::cout << "finalEvol " << pokemonData.evolutions[2] << "cols: "
                  << SFMLPokedex::pokemonList.getPokemonData(pokemonData.evolutions[2]).cols << "\n";
        firstEvol =
                AnimatedSprite(Images::get3DImage(pokemonData.evolutions[0]), 1,
                               SFMLPokedex::pokemonList.getPokemonData(pokemonData.evolutions[0]-1).cols);
        firstEvol.setTime(40);
        //second evolution
        secEvol = AnimatedSprite(Images::get3DImage(pokemonData.evolutions[1]), 1,
                                 SFMLPokedex::pokemonList.getPokemonData(pokemonData.evolutions[1] -1).cols);
        secEvol.setTime(40);
        //final evolution
        finalEvol = AnimatedSprite(Images::get3DImage(pokemonData.evolutions[2]), 1,
                                   SFMLPokedex::pokemonList.getPokemonData(pokemonData.evolutions[2] -1).cols);
        finalEvol.setTime(40);

        //bring the helperFunctions from the constructor.
        HelperFunctions::centerItemHorizontally(container, firstEvol, 50);
        HelperFunctions::centerItem(container, secEvol);
        HelperFunctions::centerItemHorizontally(container, finalEvol, 380);

        ScreenHandler::setPokemonScreenElementLoaded(EVOLUTIONS, true);
    }
    if (ScreenHandler::getPokemonScreenElementLoaded(EVOLUTIONS)) {
        firstEvol.update();
        secEvol.update();
        finalEvol.update();
    }


}



