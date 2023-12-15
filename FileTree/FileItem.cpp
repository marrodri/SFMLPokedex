//
// Created by Marthel Rodriguez on 11/20/23.
//

#include "FileItem.h"
#include "../Helper/HelperFunctions.h"
#include "../Font/Font.h"
#include "../Images/Images.h"
#include "../AppHandler.h"
#include "../Screen/ScreenHandler.h"


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
    fileItemContainer.setOutlineThickness(2);
    fileItemContainer.setOutlineColor(sf::Color::White);

    ///init textUI
    this->fileItemText = Text(text, 12, Font::getFont(OPEN_SANS), {12, 12});
    this->fileItemText.setString(text);
    HelperFunctions::centerItem(fileItemContainer, this->fileItemText);
}

FileItem::FileItem(TreeNode<std::string> &data, sf::Vector2f size, sf::Vector2f position) {
    ///init data to store
    this->data = data;
    ///init fileItemContainer
    fileItemContainer.setSize(size);
    fileItemContainer.setPosition({position});
    fileItemContainer.setOutlineThickness(1);
    fileItemContainer.setOutlineColor(sf::Color::White);
    if (data.typeOfFile == std::filesystem::file_type::directory) {
        fileItemContainer.setFillColor(sf::Color::Blue);
        icon.setTexture(Images::getImage(FOLDER));
        icon.setSize({20, 20});
        HelperFunctions::positionItemByBounds(fileItemContainer, icon, {10, 10});
    } else {
        fileItemContainer.setFillColor(sf::Color::Green);
        icon.setTexture(Images::getImage(FILE_IMG));
        icon.setSize({20, 20});
        HelperFunctions::positionItemByBounds(fileItemContainer, icon, {10, 10});
    }
    ///init textUI
    this->fileItemText = Text(data.fileName, 12, Font::getFont(OPEN_SANS), {12, 12});
    this->fileItemText.setString(data.fileName);
    HelperFunctions::centerItem(fileItemContainer, this->fileItemText);
}

/**
 * GUI Methods
 **/
void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(fileItemContainer);
    window.draw(fileItemText);
    window.draw(icon);
}

void FileItem::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    ///TODO: add a hover effect on the button.
    ///      also remember to add the function that will pass the
    ///         filepath to read its content.
    if (MouseEvents<Container>::hovered(fileItemContainer, window)) {
        enableState(HOVERED);
    } else {
        disabledState(HOVERED);
    }
    if (MouseEvents<Container>::mouseClicked(window, event) &&
        MouseEvents<Container>::hovered(fileItemContainer, window)) {
        //kinda works, but it still receiving data.
        enableState(CLICKED);
        SoundFX::playClickSound();
        if(data.typeOfFile !=std::filesystem::file_type::directory && (0!=data.fileName.compare("Files"))){
            std::cout << "viewing the file: " << data.fileName << "\n";
            AppHandler::readFile(data.path);
            ScreenHandler::setCurrentScreen(HOME_SCREEN);

        }
    }

}

void FileItem::update() {

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

sf::Vector2f FileItem::getPosition() const {
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
    HelperFunctions::positionItemByBounds(fileItemContainer, icon, {10, 10});
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


std::string FileItem::getFileName() {
    return data.fileName;
}

void FileItem::setIconTexture(const sf::Texture &iconTexture) {
    icon.setTexture(iconTexture);

}
