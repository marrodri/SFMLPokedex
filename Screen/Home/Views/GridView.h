//
// Created by Marthel Rodriguez on 11/22/23.
//

#ifndef SFMLTEMPLATE_GRIDVIEW_H
#define SFMLTEMPLATE_GRIDVIEW_H

#include "../../../Button/GridButton.h"
#include "../../../StateManager/PokemonManager.h"
#include "../../../Data/PokemonStruct.h"
#include <vector>
class GridView: public GUIComponent {
private:
    std::vector<GridButton*> listOfGridButtons;
    sf::Vector2f position;

    ///TODO: replace int i, with a pointer of pokemon struct
    GridButton *createNewGridButton(int i);
    GridButton *createNewGridButton(PokemonStruct &pokemonData);
    //What was this for. dont plan super ahead!!!
//    PokemonManager pokemonManager;
public:
    GridView();

    GridView(sf::Vector2f pos);

    /**
     * methods
     * */
    void pushItem(int i);
    void pushItem(PokemonStruct &pokemonData);
    void updateGridButtonData(PokemonStruct &pokemonData, int i);
    void clear();

    /**
     * overriden methods
     * */
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;


};


#endif //SFMLTEMPLATE_GRIDVIEW_H
