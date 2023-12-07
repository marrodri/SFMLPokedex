//
// Created by Marthel Rodriguez on 11/21/23.
//

#include "SearchInput.h"
#include "../../Font/Font.h"
#include "../../Helper/HelperFunctions.h"
#include "SearchItem.h"
#include "../../SFMLPokedex.h"
#include "../ScreenHandler.h"

/// TODO: bring the working textInput and modify it with a
///       dropdown that will show the results from it's
///       search

//(sf::Vector2f position, sf::Vector2f size, sf::Font &textInputfont,
// sf::Font &labelFont, std::string label)

SearchItem &SearchInput::createNewSearchResult(PokemonStruct pokemonData) {
    Container container = Container({405, 90}, {550, 50}, sf::Color::White);
    container.setOutlineColor(sf::Color::Black);
    Text text = Text(pokemonData.name, 32, Font::getFont(PIXEL), {200, 200});
    text.setColor(sf::Color::Black);
    SearchItem *newItem = new SearchItem(container, text, pokemonData);
    newItem->setPosition({405, 90});
    return *newItem;
}


SearchInput::SearchInput() : textInput({405, 40}, {550, 50}, Font::getFont(PIXEL), Font::getFont(PIXEL), ""),
                             labelContainer({250, 40}, {150, 50}, sf::Color::White),
                             label("SEARCH: ", Font::getFont(PIXEL), 32) {
    labelContainer.setOutlineColor(sf::Color::Black);
    labelContainer.setOutlineThickness(3);
    label.setFillColor(sf::Color::Black);
    HelperFunctions::centerItem(labelContainer, label);
}

std::string &SearchInput::getCurrentInput() {
    //get current input from TextInput
}

void SearchInput::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(textInput);
    target.draw(labelContainer);
    target.draw(label);
    for (auto itemIterator = searchResults.begin(); itemIterator != searchResults.end(); ++itemIterator) {
        itemIterator->draw(target, states);
    }
}

void SearchInput::clearResults(){
    std::cout << "deleting containers\n";
    for (float i = 0; i < 5; i += 1) {
        //pos{405, 40},size{550, 50}
        searchResults.popItem();
    }
    ///this is ok for the moment
    searchResults.popItem();
    searchResultsCounter = 0;
}

void SearchInput::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    textInput.addEventHandler(window, event);
    if (textInput.checkState(FOCUSED)) {
        std::cout << "textInput updated: " << textInput.getInput() << "\n";
        if (!textInput.getInput().empty() && searchResultsCounter < 5) {
            for (float i = 0; i < 5; i += 1) {
                SearchItem newItem = createNewSearchResult(SFMLPokedex::pokemonList.getPokemonData(i));
                searchResults.pushItem(newItem);
                searchResultsCounter++;
            }
        } else if ((textInput.getInput().empty() && searchResultsCounter > 0)) {
            clearResults();
        }
        ///itemlist eventhandler
        for (auto itemIterator = searchResults.begin(); itemIterator != searchResults.end(); ++itemIterator) {
            itemIterator->addEventHandler(window, event);
        }
    }
    ScreenHandler::setSearchInputIsFocused(textInput.isFocused());

}

void SearchInput::update() {
    textInput.update();
    for (auto itemIterator = searchResults.begin(); itemIterator != searchResults.end(); ++itemIterator) {
        itemIterator->update();
    }

    if (!ScreenHandler::isSearchInputFocused() && searchResultsCounter > 0) {
        clearResults();
    }

}

bool SearchInput::isFocused() {

//    return ;
}


