//
// Created by Marthel Rodriguez on 11/21/23.
//

#ifndef SFMLTEMPLATE_SEARCHINPUT_H
#define SFMLTEMPLATE_SEARCHINPUT_H

#include "../../Components/GUIComponent.h"
#include "../../TextInput/TextInput.h"
#include "../../Item/ItemList.h"
#include "SearchItem.h"

class SearchInput :public GUIComponent {
private:
    sf::Text label;
    TextInput textInput;
    Container labelContainer;
    ItemList<SearchItem> searchResults;
    std::array<int,5> fetchedPokemons = {-1,-1,-1,-1};
    int searchResultsCounter=0;
    bool isSearched = false;
    // try to create the cursor move back and forth.
    //    TextInput class.
    SearchItem &createNewSearchResult(PokemonStruct pokemonData);
    bool isEndOfTheArray(const std::string &str1, const std::string &str2);
    std::array<int,5> searchPokemonDatabase(const std::string &search);

public:
    SearchInput();

    /**
     * methods
     **/
    //this will be used for fetching the existing pokemon,
    //in the binary tree.
    std::string &getCurrentInput();

    bool isFocused();



    /**
     * GUI methods
     * */
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;


    void clearResults();
};


#endif //SFMLTEMPLATE_SEARCHINPUT_H
