//
// Created by Marthel Rodriguez on 11/20/23.
//

#include "FileTree.h"

FileTree::FileTree() {
    makeTree();
}

void FileTree::push(FileNode *node, int depth) {
        std::set<FileNode *> newChildren;
        for (const auto &entry: std::filesystem::directory_iterator(node->getData().getPath())) {
            FileNode *newChild = createNewFileNode(entry, depth);
            if (newChild->getData().getFileType() == std::filesystem::file_type::directory) {
                push(newChild, depth + 1);
            }
            newChildren.insert(newChild);
        }
        node->setChildren(newChildren);
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

    newFileNode = new FileNode(newData, {120, 35}, {0, 0});
    std::cout << "new fileNode path: " << newData.path << "\n";
    std::cout << "new fileNode created at the depth: " << depth << "\n";
    return newFileNode;
}

void FileTree::makeTree() {
    TreeNode<std::string> rootData;
    if (!root) {
        rootData.path = "./Files";
        rootData.fileName = "Files";
        rootData.depth = 0;
        //
        root = new FileNode(rootData, {120, 35}, {100, 100});

        std::set<FileNode *> newChildren;
        for (const std::filesystem::directory_entry &entry: std::filesystem::directory_iterator(rootData.path)) {
            FileNode *newChild = createNewFileNode(entry, 1);
            if (newChild->getData().getFileType() == std::filesystem::file_type::directory) {
                push(newChild, newChild->getData().getDepth() + 1);
            }
            newChildren.insert(newChild);
        }
        root->setChildren(newChildren);
    }
}


void FileTree::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(*root);
}

void FileTree::applySnapshot(const Snapshot &snapshot) {
    /// Not needed here.
}

void FileTree::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    root->addEventHandler(window, event);
}

void FileTree::update() {
    root->reposition();
}

Snapshot &FileTree::getSnapshot() {
    ///Not Needed;
}

