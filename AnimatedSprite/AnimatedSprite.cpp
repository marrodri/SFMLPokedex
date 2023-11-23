//
// Created by Marthel Rodriguez on 11/22/23.
//

#include "AnimatedSprite.h"


AnimatedSprite::AnimatedSprite() {

}

AnimatedSprite::AnimatedSprite(sf::Texture &texture, int rows, int cols) {
    setup(texture, rows, cols);
//    setupIntRect(texture.getSize(), rows, cols);
}

void AnimatedSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::Sprite s = (*this);
    target.draw(s);
}


void AnimatedSprite::animate() {
    if (clock.getElapsedTime().asMilliseconds() > time) {
        if (intRect.left >= intRect.width) {
            //reset the rectangle to the first frame
            intRect.left = 0;
        } else {
            //move the rectangle to the next frame
            intRect.left += intRect.width;
        }
        clock.restart();
        //update rect so it can set the new frame.
        setTextureRect(intRect);
    }
}

//texture was initialized somewhere before.
void AnimatedSprite::setup(sf::Texture &texture, int rows, int cols) {
    setTexture(texture);
    width = texture.getSize().x;
    height = texture.getSize().y;

    setupIntRect(texture.getSize(), rows, cols);
}

void AnimatedSprite::setupIntRect(sf::Vector2u imgSize, int rows, int cols) {
    intRect.width = std::round((imgSize.x) / static_cast<float>(cols));
    std::cout << "intRect.width: "<< intRect.width << "times cols 40: "<< intRect.width * cols;
    intRect.height = imgSize.y / rows;
    intRect.left = 0;
    intRect.top = 0;
    setTextureRect(intRect);
}

int AnimatedSprite::getTime() const {
    return time;
}

void AnimatedSprite::setTime(int time) {
    AnimatedSprite::time = time;
}



size AnimatedSprite::getSize() {
    return {width, height};
}

void AnimatedSprite::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    //NOT NEEDED, UNLESS TO MAKE SOUND OF THE POKEMON
}

void AnimatedSprite::update() {
//    GUIComponent::update();
    animate();
}
