//
// Created by Marthel Rodriguez on 11/21/23.
//

#include "SearchInput.h"
#include "../../Font/Font.h"
#include "../../Helper/HelperFunctions.h"
#include "SearchItem.h"
#include "../ScreenHandler.h"
#include "../../AppHandler.h"

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

void SearchInput::clearResults() {
    std::cout << "deleting containers\n";
    int results = searchResults.getItemList().size();
    for (float i = 0; i < results; i += 1) {
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
        if (!textInput.getInput().empty()) {
            if (isSearched) {
                clearResults();
                isSearched = false;
            }
            fetchedPokemons = searchPokemonDatabase(textInput.getInput());
            for (int i = 0; i < 5; i += 1) {
                std::cout << "fetchedPokemon: " << fetchedPokemons[i];
                if (fetchedPokemons[i] >= 1) {
                    std::cout << fetchedPokemons[i] << "name: "
                              << AppHandler::pokemonList.getPokemonData(fetchedPokemons[i]).name << "\n";
                    SearchItem newItem = createNewSearchResult(
                            AppHandler::pokemonList.getPokemonData(fetchedPokemons[i]));
                    searchResults.pushItemVertically(newItem);
                    searchResultsCounter++;
                }
            }
            isSearched = true;
        } else if ((textInput.getInput().empty())) {
            clearResults();
        }
        ///itemlist eventhandler
        for (auto itemIterator = searchResults.begin(); itemIterator != searchResults.end(); ++itemIterator) {
            itemIterator->addEventHandler(window, event);
        }
    }
//    if(!textInput.checkState(FOCUSED)){
//        clearResults();
//    }
    ScreenHandler::setSearchInputIsFocused(textInput.isFocused());
}

void SearchInput::update() {
    textInput.update();
    for (auto itemIterator = searchResults.begin(); itemIterator != searchResults.end(); ++itemIterator) {
        itemIterator->update();
    }
    if (!ScreenHandler::isSearchInputFocused() && searchResults.getItemList().size() > 0) {
        clearResults();
    }
}

bool SearchInput::isFocused() {

//    return ;
}

std::array<int, 5> SearchInput::searchPokemonDatabase(const std::string &search) {
    std::array<int, 5> newArr = {-1, -1, -1, -1, -1};
    int j = 0;
    for (int i = 0; i < 38 && j < 5; i++) {
        if (isEndOfTheArray(search, AppHandler::pokemonList.getPokemonData(i).name)) {
            newArr[j] = i;
            j++;
        }
    }
    return newArr;
}

bool SearchInput::isEndOfTheArray(const std::string &str1, const std::string &str2) {
    //if str1 reaches the '\0' return true.
    int j = 0;
    for (int i = 0; i < str2.size(); i++) {

        if (!str1[j] || !str2[i]) {
            return true;
        }
        if (tolower(str1[j]) != tolower(str2[i])) {
            return false;
        }
        j++;
    }
    return false;
}


