//
// Created by Marthel Rodriguez on 11/20/23.
//

#include "FileNode.h"

FileNode::FileNode() {

}

FileNode::FileNode(sf::Image image_icon, std::string &text, sf::Vector2f size, sf::Vector2f position) {
    //TODO: image_icon
    this->data =  FileItem(text, size, position);
}

///testing method.
FileNode::FileNode(const std::string &text, sf::Vector2f size, sf::Vector2f position) {
    this->data = FileItem(text, size, position);
}

///use this one
FileNode::FileNode(TreeNode<std::string> &data, sf::Vector2f size, sf::Vector2f position){
    this->data = FileItem(data, size, position);
}


/*
 * setters
 * */

void FileNode::setChildren(const std::set<FileNode*> &children){
    this->children = children;
}

std::set<FileNode*> &FileNode::getChildren(){
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
 * */


void FileNode::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(data);
}

void FileNode::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    //TODO: get the boundaries of fileItem and handle the logic wh
    //      when being clicked on it.
}

void FileNode::update() {
    //change background color to blue when this item
}

FileItem &FileNode::getData() {
    return data;
}
