//
// Created by Marthel Rodriguez on 11/22/23.
//

#ifndef SFMLTEMPLATE_ANIMATEDSPRITE_H
#define SFMLTEMPLATE_ANIMATEDSPRITE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Components/GUIComponent.h"
enum animationType {SPRITEMENU, MAINANIMATION};

struct size {
    float width;
    float height;
};

class AnimatedSprite: public sf::Sprite, public GUIComponent{
    sf::Texture texture;
    sf::IntRect intRect;
    sf::Clock clock;
    size spriteSize = {0, 0};
    int rows;
    int cols;

private:
    int time = 250;//250 milliseconds, quarter of a second
    float width, height;

    void setup(sf::Texture &texture, int rows, int cols);

    void setupIntRect(sf::Vector2u vector2, int rows, int cols);
public:
    AnimatedSprite();



    int getTime() const;

    void setTime(int time);

    void setNewSprite(sf::Texture &texture, int rows, int cols);

    //1 row, how many cols?
    AnimatedSprite(sf::Texture &texture, int cols);

    AnimatedSprite(sf::Texture &texture, int rows, int cols);

    // we're going to change the box of the image
    void animate();

    size getSize();

    /*overriden methods(virtual methods)*/

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;
};


#endif //SFMLTEMPLATE_ANIMATEDSPRITE_H
