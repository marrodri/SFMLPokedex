//
// Created by Marthel Rodriguez on 12/11/23.
//

#include "FileTreeScreen.h"
#include "../../Font/Font.h"
#include "../../Helper/HelperFunctions.h"
#include "../../Images/Images.h"
#include "../../AppHandler.h"

FileTreeScreen::FileTreeScreen(): header("Select a file to unlock a pokemon") {
    fileTreeBackgrounImage.setSize({90 * 8, 4 * 110});
    fileTreeBackgrounImage.setTexture(Images::getImage(BACKGROUND2));
    fileTreeBackgrounImage.setPosition({250, 100});
    fileTreeBackgrounImage.setOutlineThickness(4);
    ///
    fileTreeContainer.setSize({90 * 8, 4 * 110});
    fileTreeContainer.setPosition({250, 100});
    fileTreeContainer.setFillColor(sf::Color(0x4290e3af));
    ///
    fileTreePlaceHolder.setFont(Font::getFont(OPEN_SANS));
    fileTreePlaceHolder.setString("FileTree screen");
    fileTreePlaceHolder.setCharacterSize(24);
    HelperFunctions::centerItem(fileTreeContainer, fileTreePlaceHolder);
}

void FileTreeScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(fileTreeBackgrounImage);
    target.draw(fileTreeContainer);
    target.draw(fileTreePlaceHolder);
    target.draw(header);
}

void FileTreeScreen::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    header.addEventHandler(window, event);
}

void FileTreeScreen::update() {
    header.update();

    fileTreeContainer.setFillColor(AppHandler::getFileTreeBackgroundColor());

}

sf::Vector2f FileTreeScreen::getPosition() {
    return sf::Vector2f();
}

sf::Vector2f FileTreeScreen::getSize() {
    return sf::Vector2f();
}

sf::FloatRect FileTreeScreen::getLocalBounds() const {
    return sf::FloatRect();
}

sf::FloatRect FileTreeScreen::getGlobalBounds() const {
    return sf::FloatRect();
}

void FileTreeScreen::setOrigin(sf::Vector2f &origin) {

}

void FileTreeScreen::setPosition(const sf::Vector2f &pos) {

}

void FileTreeScreen::setFillColor(const sf::Color &color) {

}

void FileTreeScreen::setTexture(const sf::Texture &texture) {

}

void FileTreeScreen::setSize(sf::Vector2f size) {

}

void FileTreeScreen::setOutlineThickness(float outlineThickness) {

}

void FileTreeScreen::setOutlineColor(const sf::Color &color) {

}
