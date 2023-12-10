//
// Created by Marthel Rodriguez on 11/20/23.
//

#ifndef SFMLTEMPLATE_FILETREE_H
#define SFMLTEMPLATE_FILETREE_H


#include "../Components/GUIComponent.h"
#include "./FileItem.h"
#include <iostream>

class FileTree : public GUIComponent{
private:
    //the root node of the tree
//    FileNode* rootx = nullptr;
    FileItem *root= nullptr;

    FileItem &createNewFileItem(const std::filesystem::directory_entry &dirEntry, int depth);
    void makeTree();
    void print(TreeNode<std::string> *node);


    //finds the parent and add the item to the parent.
    // If the parent isn't found, a new parent is created
    void push(FileItem &node, int depth);
    sf::Vector2f initPosition = {0, 0};

public:
    //constructors
    FileTree();

    //this is the public version of push
    void push(std::string parent, std::string item = "NULL");

    //draws the root node of the tree
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //does nothing now
    virtual void applySnapshot(const Snapshot& snapshot);

    //calls the traverse function to add the event handlers to each node
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);

    //does nothing now
    virtual void update();
    //does nothing now
    virtual Snapshot& getSnapshot();
    //does nothing now
//    virtual sf::FloatRect getGlobalBounds();
};


#endif //SFMLTEMPLATE_FILETREE_H
