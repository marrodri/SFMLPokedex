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
    int depth = 10;
    ///init fileItemContainer
    fileItemContainer.setSize(size);
    fileItemContainer.setPosition({position.x + (depth * 10), position.y});

    fileItemContainer.setFillColor(sf::Color::Blue);

    ///init textUI
    this->fileItemText = Text(text, 12, Font::getFont(OPEN_SANS), {12, 12});
//    = HelperFunctions::setUpText(Font::getFont(OPEN_SANS),12, {12,12});
    this->fileItemText.setString(text);
    HelperFunctions::centerItem(fileItemContainer, this->fileItemText);
}

FileItem::FileItem(TreeNode<std::string> &data, sf::Vector2f size, sf::Vector2f position) {
    ///init data to store
    this->data = data;
    ///init fileItemContainer
    fileItemContainer.setSize(size);
    fileItemContainer.setPosition({position});
    if (data.typeOfFile == std::filesystem::file_type::directory) {
        fileItemContainer.setFillColor(sf::Color::Blue);
    } else {
        fileItemContainer.setFillColor(sf::Color::Green);
    }


    ///init textUI
    this->fileItemText = Text(data.fileName, 12, Font::getFont(OPEN_SANS), {12, 12});
    this->fileItemText.setString(data.fileName);
    HelperFunctions::centerItem(fileItemContainer, this->fileItemText);
}

/**x
 *
 * */

/**
 * GUI Methods
 * */
void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    window.draw(fileItemContainer);
    window.draw(fileItemText);
//    std::cout << "drawing fileItem: " << data.fileName << " placed  at:{x" << fileItemContainer.getPosition().x
//              << ", y:" << fileItemContainer.getPosition().y << "\n";
//    window.draw(icon);
//TODO: add a toggler that when its
    for (auto fileItem = children.begin(); fileItem != children.end(); fileItem++) {
        fileItem->draw(window, states);
    }
}

void FileItem::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        for (auto fileItem = children.begin(); fileItem != children.end(); fileItem++) {
            if (fileItem->getFileType() == std::filesystem::file_type::directory) {
                fileItem->children.updateListPosition(
                        sf::Vector2f(fileItem->getPosition().x, fileItem->getPosition().y + fileItem->getSize().y));
                fileItem++;
                if (!fileItem->children.empty()) {
                    fileItem->children.getLastItemPosition();
                    children.updateListPosition({fileItem->getPosition().x,
                                                 fileItem->children.getLastItemPosition().y + fileItem->getSize().y});

                }
            }
        }
    }
    //TODO continue here.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
        for (auto fileItem = children.begin(); fileItem != children.end(); fileItem++) {
            if (fileItem->getFileType() == std::filesystem::file_type::directory) {
                fileItem->getPosition();
                fileItem->children.updateListPosition(sf::Vector2f(fileItem->getPosition() + fileItem->getSize()));
            }
        }
    }
}

void FileItem::update() {
//    GUIComponent::update();

}

/**
 * getters
 * */

int FileItem::getDepth() {
    return data.depth;
}

std::string &FileItem::getPath() {
    return data.path;
}

std::filesystem::file_type &FileItem::getFileType() {
    return data.typeOfFile;
}

sf::Vector2f FileItem::getPosition() {
    return fileItemContainer.getPosition();
}

sf::Vector2f FileItem::getSize() {
    return fileItemContainer.getSize();
}

sf::FloatRect FileItem::getLocalBounds() const {
    return fileItemContainer.getLocalBounds();
}

sf::FloatRect FileItem::getGlobalBounds() const {
    return fileItemContainer.getGlobalBounds();
}

void FileItem::setOrigin(sf::Vector2f &origin) {
    fileItemContainer.setOrigin(origin);
}

void FileItem::setPosition(const sf::Vector2f &pos) {
    fileItemContainer.setPosition(pos);
    HelperFunctions::centerItem(fileItemContainer, fileItemText);
}

void FileItem::setFillColor(const sf::Color &color) {
    fileItemContainer.setFillColor(color);
}

void FileItem::setTexture(const sf::Texture &texture) {
    fileItemContainer.setTexture(texture);
}

void FileItem::setSize(sf::Vector2f size) {
    fileItemContainer.setSize(size);
}

void FileItem::setOutlineThickness(float outlineThickness) {
    fileItemContainer.setOutlineThickness(outlineThickness);
}

void FileItem::setOutlineColor(const sf::Color &color) {
    fileItemContainer.setOutlineColor(color);
}

void FileItem::setChildren(const ItemList<FileItem> &children) {
    this->children = children;
}

ItemList<FileItem> &FileItem::getChildren() {
    return this->children;
}

std::string FileItem::getFileName() {
    return data.fileName;
}
