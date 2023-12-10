//
// Created by Marthel Rodriguez on 11/20/23.
//

#include "FileTree.h"

FileTree::FileTree() {

    //for each new node
//    root = new FileNode("charizard.pkg", {120,35}, {50,50});
    makeTree();

    ///logic for left padding by the depth of the children from NAry tree.
//    fileItemContainer.setPosition({position.x +(data.depth*10), position.y});
}

void FileTree::push(FileItem &node, int depth) {
//    if (node) {
//        std::set<FileNode*> newChildren;
    ItemList<FileItem> newChildren;
    sf::Vector2f prevPos;
    for (const auto &entry: std::filesystem::directory_iterator(node.getPath())) {
        FileItem newChild = createNewFileItem(entry, depth);
        if(newChildren.empty()){
            //set the position below its parent.
            newChild.setPosition({node.getPosition().x, node.getPosition().y + node.getSize().y});
        }
        else{
            //just set the position, it will be updated on the itemList
            newChild.setPosition({node.getPosition().x, newChildren.getLastItemPosition().y + node.getSize().y});
        }

//        newChild.setPosition({root->getPosition().x, prevPos.y + root->getSize().y});
        std::cout << "***recursive->newChild root fileName:" << newChild.getFileName() << ", at y: " << newChild.getPosition().y<< std::endl;
        if (newChild.getFileType() == std::filesystem::file_type::directory) {
            push(newChild, depth + 1);
        }
        newChildren.pushFrontItemVertically(newChild);
    }
    node.setChildren(newChildren);
}

FileItem &FileTree::createNewFileItem(const std::filesystem::directory_entry &dirEntry, int depth) {

    FileItem *newFileItem;
    TreeNode<std::string> newData;
    ///
    newData.path = dirEntry.path();
    newData.typeOfFile = dirEntry.status().type();
    newData.fileName = dirEntry.path().filename();
    newData.depth = depth;

    ///

    newFileItem = new FileItem(newData, {120, 35}, {100, 100});
//    newFileNode = new FileNode(newData,{120,35},{100,100});
    std::cout << "new fileNode path: " << newData.path << "\n";
    std::cout << "new fileNode created at the depth: " << depth << "\n";
    return *newFileItem;
}

void FileTree::makeTree() {
    TreeNode<std::string> rootData;
    if (!root) {
        //init the TreeNode data
        rootData.path = "./Files";
        rootData.fileName = "Files";
        rootData.depth = 0;
        //
        root = new FileItem(rootData, {120, 35}, {100, 100});

//        std::set<FileNode*> newChildren;
        ItemList<FileItem> newChildren;
        std::cout << "root fileName:" << root->getFileName() << std::endl;
//        previous param: root->path
        //TODO: it's required to build an iterator.
        sf::Vector2f prevPos;
        for (const std::filesystem::directory_entry &entry: std::filesystem::directory_iterator(rootData.path)) {
            //createNewFileNode();
            FileItem newChild = createNewFileItem(entry, 1);
            if(newChildren.empty()){
                //set the position below its parent.
                newChild.setPosition({root->getPosition().x, root->getPosition().y + root->getSize().y});
            }
            else{
                //just set the position, it will be updated on the itemList
                newChild.setPosition({root->getPosition().x, newChildren.getLastItemPosition().y + root->getSize().y});
            }
//            FileItem newFileItem = FileItem();
            std::cout << "**newChild root fileName:" << newChild.getFileName() << ", at y: " << newChild.getPosition().y<< std::endl;
            if (newChild.getFileType() == std::filesystem::file_type::directory) {
                push(newChild,newChild.getDepth() + 1);
                //update the current
//                newChild.getChildren().getLastItemPosition();
//                newChild.getChildren().setColumnListPosition(sf::Vector2f (newChild.getChildren().getLastItemPosition().x, newChild.getChildren().getLastItemPosition().y+ root->getSize().y));
            }
//            else{
                newChildren.pushFrontItemVertically(newChild);
//            }
        }
        root->setChildren(newChildren);
    }
}


void FileTree::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(*root);
//    if(!root->empty()){
//        root->getChildren().begin();
//        for(auto fileItem =root->getChildren().begin(); fileItem != root->getChildren().end(); fileItem++){
//            fileItem->draw(window, states);
//        }
//    }
    //recursively iterate for the children to go.
}

void FileTree::applySnapshot(const Snapshot &snapshot) {
    /// Not needed here.
}

void FileTree::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    root->addEventHandler(window, event);
}

void FileTree::update() {
    root->update();
}

Snapshot &FileTree::getSnapshot() {
    ///Not Needed;
}

