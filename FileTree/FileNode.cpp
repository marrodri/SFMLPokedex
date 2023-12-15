//
// Created by Marthel Rodriguez on 11/20/23.
//

#include "FileNode.h"

FileNode::FileNode() {

}

FileNode::FileNode(sf::Image image_icon, std::string &text, sf::Vector2f size, sf::Vector2f position) {
    //TODO: image_icon
    this->data = FileItem(text, size, position);
    disabledState(OPENED);

}

///testing method.
FileNode::FileNode(const std::string &text, sf::Vector2f size, sf::Vector2f position) {
    this->data = FileItem(text, size, position);
    disabledState(OPENED);
}

///use this one
FileNode::FileNode(TreeNode<std::string> &data, sf::Vector2f size, sf::Vector2f position) {
    this->data = FileItem(data, size, position);
    disabledState(OPENED);
}


/*
 * setters
 * */

void FileNode::setChildren(const std::set<FileNode *> &children) {
    this->children = children;
}

std::set<FileNode *> &FileNode::getChildren() {
    return this->children;
}

void FileNode::setPosition(const sf::Vector2f position) {
    this->data.setPosition(position);

}


/**
 * iterators
 * */
FileNode::iterator FileNode::begin() {
    return children.begin();
}

FileNode::iterator FileNode::end() {
    return children.end();
}


/**
 * GUI methods
 **/

void FileNode::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(data);
    if (checkState(OPENED)) {
        for (auto child = children.begin(); child != children.end(); child++) {
            (*child)->draw(window, states);
        }
    }

}

void FileNode::toggleChlidren() {
    if (!checkState(OPENED)) {
        enableState(OPENED);
    } else {
        disabledState(OPENED);
    }
}

void FileNode::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    //TODO: get the boundaries of fileItem and handle the logic wh
    //      when being clicked on it.
    data.addEventHandler(window, event);
    if (MouseEvents<FileItem>::mouseClicked(data, window) && MouseEvents<FileItem>::hovered(data, window) ) {
        toggleChlidren();

    }
    if (checkState(OPENED)) {
        for (auto fileItem = children.begin(); fileItem != children.end(); fileItem++) {
            (*fileItem)->addEventHandler(window, event);
        }
    }
}

void FileNode::update() {
    //change background color to blue when this item
//    this->reposition();
    data.update();
    if (checkState(OPENED)) {
        for (auto fileItem = children.begin(); fileItem != children.end(); fileItem++) {
            (*fileItem)->update();
        }
    }
}

FileItem &FileNode::getData() {
    return data;
}

void FileNode::reposition() const {
//    std::cout << "repositioning\n";
    sf::Vector2f position = data.getPosition();
    position.x += 30;
    position.y += data.getGlobalBounds().height;
    if (checkState(OPENED)) {

        for (auto child = children.begin(); child != children.end(); child++) {
            (*child)->setPosition(position);
            position.y += (*child)->getGlobalBounds().height;
            (*child)->reposition();
        }
    }
}

sf::FloatRect FileNode::getGlobalBounds() {
    sf::FloatRect bounds = data.getGlobalBounds();
    if (checkState(OPENED) && !children.empty()) {

        for (auto child = children.begin(); child != children.end(); child++) {
            bounds.height += (*child)->getGlobalBounds().height;
        }
    }
    return bounds;
}




