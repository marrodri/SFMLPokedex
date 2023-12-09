//
// Created by Marthel Rodriguez on 11/20/23.
//

#include "FileTree.h"

FileTree::FileTree() {

    //for each new node
//    root = new FileNode("charizard.pkg", {120,35}, {50,50});
    makeTree();

    ///logic for left padding by the depth of the children from NAry tree.
//    container.setPosition({position.x +(data.depth*10), position.y});
}

void FileTree::push(FileNode *node, int depth) {
    if (node) {
        std::set<FileNode*> newChildren;
        for (const auto & entry : std::filesystem::directory_iterator(node->getData().getPath())){
            FileNode* newChild = createNewFileNode(entry, depth);

            if (newChild->getData().getFileType() == std::filesystem::file_type::directory) {
                push(newChild, depth+1);
            }
            newChildren.insert(newChild);
        }
        node->setChildren(newChildren);
    }
}

FileNode *FileTree::createNewFileNode(const std::filesystem::directory_entry &dirEntry, int depth) {

    FileNode *newFileNode;
    TreeNode<std::string> newData;
    ///
    newData.path = dirEntry.path();
    newData.typeOfFile = dirEntry.status().type();
    newData.fileName = dirEntry.path().filename();
    newData.depth = depth;

    ///
    newFileNode = new FileNode(newData,{120,35},{100,100});
    std::cout << "new fileNode created at the depth: " << depth <<"\n";
    return newFileNode;
}

void FileTree::makeTree() {
    TreeNode<std::string> rootData;
    if(!root){
        //init the TreeNode data
        rootData.path="./Files";
        rootData.fileName="Files";
        rootData.depth = 0;
        //
        root = new FileNode(rootData, {120,35},{100,100});

        std::set<FileNode*> newChildren;

//        previous param: root->path
        //TODO: it's required to build an iterator.
        for (const std::filesystem::directory_entry & entry : std::filesystem::directory_iterator(rootData.path)){
            //createNewFileNode();
            FileNode * newChild = createNewFileNode(entry, 1);
            if(newChild->getData().getFileType() ==std::filesystem::file_type::directory){
                push(newChild, newChild->getData().getDepth()+1);
            }
            newChildren.insert(newChild);
        }
        root->setChildren(newChildren);
    }
}

void FileTree::traverse(FileNode *&root, sf::RenderWindow &window, sf::Event event) {

}

void FileTree::draw(FileNode *node, sf::RenderTarget &window, sf::RenderStates states){
    if(!root->getChildren().empty()){
        root->getChildren().begin();
    }
}

void FileTree::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    //    root->draw(window,states);
    sf::Vector2f initYpos;
    window.draw(*root);
    initYpos = root->getData().getPosition();
    if(!root->getChildren().empty()){
        root->getChildren().begin();
    }
    //recursively iterate for the children to go.


}

void FileTree::applySnapshot(const Snapshot &snapshot) {
    /// Not needed here.
}

void FileTree::addEventHandler(sf::RenderWindow &window, sf::Event event) {
//    root->addEventHandler(window, event);
}

void FileTree::update() {
//    root->update();
}

Snapshot &FileTree::getSnapshot() {
    ///Not Needed;
}

sf::FloatRect FileTree::getGlobalBounds() {
    //this is useful for properly setup in the window.
//    return root->getGlobalBounds();
}
