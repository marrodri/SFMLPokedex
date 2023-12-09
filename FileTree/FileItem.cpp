//
// Created by Marthel Rodriguez on 11/20/23.
//

#include "FileItem.h"
#include "../Helper/HelperFunctions.h"
#include "../Font/Font.h"


FileItem::FileItem() {

}

FileItem::FileItem(std::string text, sf::Vector2f size, sf::Vector2f position) {
    //depth for padding
    data.depth;
    int depth=10;
    ///init container
    container.setSize(size);
    container.setPosition({position.x +(depth*10), position.y});
    container.setFillColor(sf::Color::Blue);

    ///init textUI
    this->text = HelperFunctions::setUpText(Font::getFont(OPEN_SANS),12, {12,12});
    this->text.setString(text);
    HelperFunctions::centerText(container, this->text);
}

FileItem::FileItem(TreeNode<std::string> &data, sf::Vector2f size, sf::Vector2f position){
    ///init data to store
    this->data = data;
    ///init container
    container.setSize(size);
    container.setPosition({position});
    container.setFillColor(sf::Color::Blue);

    ///init textUI
    this->text = HelperFunctions::setUpText(Font::getFont(OPEN_SANS),12, {12,12});
    this->text.setString(data.fileName);
    HelperFunctions::centerText(container, this->text);
}
/**
 *
 * */

/**
 * GUI Methods
 * */
void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    window.draw(container);
    window.draw(text);
    window.draw(icon);
}

void FileItem::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    //nope.
}

void FileItem::update() {
//    GUIComponent::update();
}

/**
 * getters
 * */
sf::FloatRect FileItem::getGlobalBounds() const {
    return container.getGlobalBounds();
}

int FileItem::getDepth() {
    return data.depth;
}

std::string &FileItem::getPath(){
    return data.path;
}

std::filesystem::file_type &FileItem::getFileType(){
    return data.typeOfFile;
}

void FileItem::setPosition(sf::Vector2f pos){
    container.setPosition(pos);
    HelperFunctions::centerText(container, text);
}

sf::Vector2f FileItem::getPosition() const {
    return container.getPosition();
}