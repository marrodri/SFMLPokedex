//
// Created by Marthel Rodriguez on 11/30/23.
//

#include "Description.h"
#include "../../../Helper/HelperFunctions.h"
#include "../../../Font/Font.h"
#include "../../ScreenHandler.h"

Description::Description(): container({470, 150}, {450, 200}, sf::Color::Blue),
                            title("Description:", 25, Font::getFont(OPEN_SANS), {250, 100}),
                            textField("about pokemon")
                            {

    HelperFunctions::positionItemByBounds(container, title,{80,20});
//                        HelperFunctions::positionItemByBounds(fileItemContainer, textField,{90,50});

//    ScreenHandler::getSelectedPokemonData().about;
}

Description::Description(int pokemonNo) {

}

void Description::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(container);
    target.draw(title);
    target.draw(textField);
}

void Description::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    textField.addEventHandler(window, event);
    if(event.type == sf::Event::TextEntered){
        std::cout << "setting data to " << pokemonData.number << ": "<< pokemonData.name <<"\n";
        PokemonList::setDescription(pokemonData.number, textField.getString());
    }



}

void Description::update() {
    if (!ScreenHandler::getPokemonScreenElementLoaded(DESCRIPTION)) {
        pokemonData = ScreenHandler::getSelectedPokemonData();
        textField.clear();
        textField.setText(pokemonData.about);


        ScreenHandler::setPokemonScreenElementLoaded(DESCRIPTION, true);
    }
    if (ScreenHandler::getPokemonScreenElementLoaded(DESCRIPTION)) {
        textField.update();

    }
}
